//
//  Digraph.h
//  PA3
//
//  Created by Babak Farahmand on 2/15/19.
//  Copyright © 2019 Babak Farahmand. All rights reserved.
//

#ifndef Digraph_h
#define Digraph_h
#include "List.h"

#define UNVISITED -1
#define INPROGRESS -2
#define ALLDONE -3

#define FOUND 1
#define NOTFOUND 0

#define YesCycle -11
#define NoCycle -10


#include <stdio.h>


typedef struct DigraphObj* Digraph;
/*** Constructors-Destructors ***/

// Returns a Digraph that points to a newly created DigraphObj representing a digraph which has
// n vertices and no edges.
Digraph newDigraph(int numVertices);

// Frees all dynamic memory associated with its Digraph* argument, and sets
// *pG to NULL.
void freeDigraph(Digraph* pG);

/*** Access functions ***/

// Returns the order of G, the number of vertices in G.
int getOrder(Digraph G);

// Returns the size of G, the number of edges in G.
int getSize(Digraph G);

// Returns the number of neighbors that vertex v has in G. Returns -1 if v is not a legal vertex.
int getNeighborCount(Digraph G, int v);

// Returns a list that has all the vertices that are neighbors of v. There is no input operation
// that corresponds to getNeighbors.
List getNeighbors(Digraph G, int v);

/*** Manipulation procedures ***/

// Adds v to the adjacency list of u, if that edge doesn’t already exist.
// If the edge does already exist, does nothing. Used when edges are entered or added.
// Returns 0 if (u, v) is a legal edge, and the edge didn’t already exist.
// Returns 1 if (u, v) is a legal edge and the edge did already exist.
// Returns -1 if (u, v) is not a legal edge.
int addEdge(Digraph G, int u, int v);

// Deletes v from the adjacency list of u, if that edge exists.
// If the edge doesn’t exist, does nothing. Used when edges are deleted.
// Returns 0 if (u, v) is a legal edge, and the edge did already exist.
// Returns 1 if (u, v) is a legal edge and the edge didn’t already exist.
// Returns -1 if (u, v) is not a legal edge.
int deleteEdge(Digraph G, int u, int v);


/*** Other operations ***/
// Outputs the digraph G in the same format as an input line, including the number of vertices
// and the edges. The edges should be in sorted order, as described above.
void printDigraph(FILE* out, Digraph G);

// Outputs the distance between vertices u and v if there is a directed path between them in the
// digraph. Otherwise, outputs INF
void distance(FILE* out, Digraph G, int u, int v);

// Outputs YES if the digraph is acyclic. Otherwise, outputs NO.
void acyclic(FILE* out, Digraph G);

// Outputs a topological sort of the digraph. If the digraph is not acyclic, outputs IMPOSSIBLE.
void topoSort(FILE* out, Digraph G);

int addEdgeHelper(Digraph G, int headNode, int node);
void reseTheList(Digraph G);

void pathExists(FILE* out, Digraph G, int u, int v);
int DFSRecursive(Digraph G, int w);

void setMark(Digraph G, int u, int theMark);
int getMark(Digraph G, int u);
#endif /* Digraph_h */
