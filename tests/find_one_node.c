#include <string.h>
#include <stdio.h>

#include "../src/graph.h"

int main(int argc, char *argv[])
{
    Graph g = graph_create();
    Node n = graph_create_node(g, "A");

    Node n2 = graph_find_node(g, "A");

    if (n2 == NULL || n2 != n) {
        puts("failed");
        return 1;
    }

    puts("passed");

    return 0;
}
