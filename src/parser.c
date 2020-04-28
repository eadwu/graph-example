#include <stdio.h>
#include <stdbool.h>

#include "graph.h"

Graph graph_parse(FILE *fp) {
    Graph g;
    Node cur;
    char name[NAMELEN + 1];
    int len = 0;
    char c;

    g = graph_create();

    cur = NULL;
    while (true) {
        c = getc(fp);
        if (c == ' ' || c == '\n' || c == EOF) {
            if (len == 0 && (c == ' ' || c == '\n')) {
                continue;
            } else if (len == 0 && c == EOF) {
                break;
            }
            name[len] = '\0';
            len = 0;
            // name of a node parsed
            if (cur == NULL) {
                // This is the first word on the line
                cur = graph_assert_node(g, name);
                if (cur == NULL) {
                    // Leaks!
                    return NULL;
                }
            } else {
                // This is the second or further word
                Node to = graph_assert_node(g, name);
                Edge e;
                if (to == NULL) {
                    // Leaks!
                    return NULL;
                }
                e = edge_create(to);
                node_attach(cur, e);
            }
            if (c == '\n') {
                cur = NULL;
            } else if (c == EOF) {
                break;
            }
        } else {
            if (len == NAMELEN) {
                // Leaks memory!
                return NULL;
            }
            name[len] = c;
            len++;
        }
    }

    return g;
}
