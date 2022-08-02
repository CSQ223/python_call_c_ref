#include "flat_route.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
    flat_route_t flat_route = flat_route_new();

    if(NULL==flat_route) {
        printf("initialized error");
        return -1;
    }

    int res = flat_route_exec(flat_route, 10);
    if(res!=0){
        printf("execution error");
        return -2;
    }

    int num_nodes = flat_route_size(flat_route);
    printf("num of nodes = %d\n", num_nodes);

    for(int i=0; i<num_nodes; i++){
        int node = flat_route_get(flat_route, i);
        if(node>0){
            printf("route[%d] = %d\n", i, node);
        }
    }

    flat_route_free(flat_route);

    return 0;
}
