#include <string.h>
#include <stdio.h>

#include "../src/graph.h"

int main(int argc, char *argv[])
{
    Graph g = graph_create();

    Node n = node_create("A");

    if (n == NULL || strcmp(n->name, "A")
        || n->next != NULL || n->edges != NULL) {
        puts("failed: n is not correct");
        return 1;
    }

    graph_insert_node(g, n);
    
    if (g->nodes != n || g->nodes->next != NULL) {
        puts("failed: g is not correct");
        return 1;
    }

    puts("passed");

    return 0;
}
