#include <stdio.h>
#include <string.h>

#include "../src/graph.h"

int main(int argc, char *argv[])
{
    Graph g;
    FILE *fp = fopen("inputs/singlenode-nonewline.graph", "r");

    if (fp == NULL) {
        fprintf(stderr, "Could not open file for reading\n");
        return 1;
    }

    g = graph_parse(fp);

    if (g == NULL || g->nodes == NULL
        || strcmp(g->nodes->name, "A")
        || g->nodes->edges != NULL
        || g->nodes->next != NULL) {
        puts("failed");
    }

    puts("passed");

    return 0;
}
