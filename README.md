Simple Directed Graph
===

This project will implement a simple directed graph library.  We will
not address performance concerns to any meaningful degree; in
particular, node and neighbor accesses will be linear searches
through a list of nodes.

Each node in the graph will have a name, and the graph will be
implemented in a neighbor-list format.  Every node in the graph will
therefore consist of a C string for the name and a list of neighboring
nodes.  Other information may be included to facilitate graph
traversals or other algorithms.

Node names are unique, and consist of no more than 15 non-whitespace
characters.

Directed Graphs
---

A directed graph consists of a set of nodes and a set of edges, where
each edge has a _from_ end and a _to_ end.  If there is an edge from
node A to node B, this does not imply that there is also an edge from
node B to node A.

There are various ways to represent these edges; we will use an
_adjacency list_.  Each node will be associated with a list of nodes
which are its neighbors; the presence of a node B on the adjacency
list for node A indicates that there an edge _from_ node A _to_ node
B.

Graph Files
---

Graphs will be represented on disk in a similar neighor-list format
with a variety of assumptions to make parsing easy.  Because node
names are unique and consist of only non-whitespace characters, nodes
will be represented in the file by their names.  The file will be
records separated by newlines.  The first "word" on any line is a node
name, and it is separated by a single ASCII space from its adjacency
list.  Nodes on the adjacency list are separated by a single ASCII
space, and the adjacency list is terminated by a newline.

Any node that appears in the file in any position is assumed to exist
(and should be created when it is encountered).  A node may appear on
more than one line as either the first word or in the adjacency list.

A simple file representing a directed graphs having two nodes, A and
B, and only one edge from A to B, would look like:

```
A B
```

The following would also be acceptable, and equivalent:

```
B
A B
A
```

In both cases, exactly two nodes and one edge are declared.  As a
second example, consider the following "circular" graph:

```
    A
   ^ \		 
  /	  \	 
 /	   v	 
B <--- C
```

It might be represented in our graph file format as:

```
A C
B A
C B
```

The following graph:

```
   B
  ^
 /
A
 \
  v
   C
```

Would be represented as:

```
A B C
```
