#include "c_api.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
    c_api_exec(10);
    int num_nodes = c_api_get_num_nodes();

    printf("num of nodes = %d\n", num_nodes);

    for (int i = 0; i < num_nodes; i++)
    {
        int node = c_api_get_node(i);

        if (node >= 0)
        {
            printf("route[%d] = %d\n", i, node);
        }
    }

    c_api_exit();

    return 0;
}
