#include <stdio.h>

#include "../src/graph.h"

int main(int argc, char *argv[])
{
    Graph g = graph_create();

    if (g == NULL || g->nodes != NULL) {
        puts("failed");
        return 1;
    }

    puts("passed");

    return 0;
}
