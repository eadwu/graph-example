#include <string.h>
#include <stdlib.h>

#include "graph.h"
#include "allocator.h"

static Allocator node_allocator;
static Allocator edge_allocator;

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

Node graph_find_node(Graph g, char *name) {
    for (Node cur = g->nodes; cur != NULL; cur = cur->next) {
        if (!strcmp(cur->name, name)) {
            return cur;
        }
    }

    return NULL;
}

Node node_create(char *name) {
    Node n;

    if (strlen(name) > NAMELEN) {
        return NULL;
    }

    if (node_allocator == NULL) {
        node_allocator = allocator_create(sizeof(struct Node));
        if (node_allocator == NULL) {
            return NULL;
        }
    }

    n = allocator_alloc(node_allocator);
    if (n == NULL) {
        return NULL;
    }

    strncpy(n->name, name, NAMELEN + 1);

    return n;
}

void node_destroy(Node n) {
    if (n == NULL) {
        return;
    }

    while (n->edges != NULL) {
        Edge cur = n->edges;
        n->edges = cur->next;
        edge_destroy(cur);
    }

    allocator_free(node_allocator, n);
}

void node_attach(Node n, Edge e) {
    if (n == NULL || e == NULL) {
        return;
    }

    e->next = n->edges;
    n->edges = e;
}

Edge edge_create(Node to) {
    Edge e;

    if (edge_allocator == NULL) {
        edge_allocator = allocator_create(sizeof(struct Edge));
        if (edge_allocator == NULL) {
            return NULL;
        }
    }

    e = allocator_alloc(edge_allocator);
    if (e == NULL) {
        return NULL;
    }

    e->node = to;

    return e;
}

void edge_destroy(Edge e) {
    allocator_free(edge_allocator, e);
}
