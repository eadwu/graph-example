#include <string.h>
#include <stdlib.h>

#include "graph.h"

Graph graph_create() {
    return calloc(1, sizeof(struct Graph));
}

void graph_insert_node(Graph g, Node n) {
    if (g == NULL || n == NULL) {
        return;
    }

    n->next = g->nodes;
    g->nodes = n;
}

Node graph_create_node(Graph g, char *name) {
    Node n;

    if (g == NULL) {
        return NULL;
    }

    n = node_create(name);
    if (n == NULL) {
        return NULL;
    }

    graph_insert_node(g, n);

    return n;
}

Node node_create(char *name) {
    Node n = calloc(1, sizeof(struct Node));

    if (strlen(name) > NAMELEN) {
        return NULL;
    }

    strncpy(n->name, name, NAMELEN + 1);

    return n;
}

void node_attach(Node n, Edge e) {
    if (n == NULL || e == NULL) {
        return;
    }

    e->next = n->edges;
    n->edges = e;
}

Edge edge_create(Node to) {
    Edge e = calloc(1, sizeof(struct Edge));

    e->node = to;

    return e;
}
