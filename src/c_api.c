#include "c_api.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _flat_route
{
    int num_nodes;
    int *route;
} _flat_route, *flat_route_t;

static flat_route_t flat_route;

/// run algorithm
LIB_API int c_api_exec(int data)
{
    if (!flat_route)
        flat_route = (flat_route_t)malloc(sizeof(_flat_route));

    if (flat_route == NULL)
        return -1;

    flat_route->route = (int *)malloc(sizeof(int) * data);
    if (!flat_route->route)
        return -1;

    for (int i = 0; i < data; i++)
    {
        flat_route->route[i] = i;
    }
    flat_route->num_nodes = data;

    return 0;
}

/// get the number of nodes
LIB_API int c_api_get_num_nodes()
{
    if (NULL != flat_route)
        return flat_route->num_nodes;

    return 0;
}

/// get then node at index
LIB_API int c_api_get_node(int index)
{
    if (NULL == flat_route)
        return -1;

    if (index < 0 || index >= flat_route->num_nodes)
        return -1;

    if (NULL == flat_route->route)
        return -1;

    return flat_route->route[index];
}

/// clear
LIB_API void c_api_exit()
{
    if (NULL != flat_route)
    {
        free(flat_route->route);
    }
    free(flat_route);

    flat_route = NULL;
}
