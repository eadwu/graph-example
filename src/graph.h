#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

#define NAMELEN 15

typedef struct Graph *Graph;
typedef struct Node *Node;
typedef struct Edge *Edge;

struct Graph {
    Node nodes;
};

struct Node {
    char name[NAMELEN + 1];
    Node next;
    Edge edges;
};

struct Edge {
    Edge next;
    Node node;
};

Graph graph_parse(FILE *fp);

Graph graph_create();
Node graph_create_node(Graph g, char *name);
Node graph_find_node(Graph g, char *name);
Node graph_assert_node(Graph g, char *name);

void graph_insert_node(Graph g, Node n);

Node node_create(char *name);
void node_destroy(Node n);
void node_attach(Node n, Edge e);

Edge edge_create(Node to);
void edge_destroy(Edge e);

#endif /* GRAPH_H */
