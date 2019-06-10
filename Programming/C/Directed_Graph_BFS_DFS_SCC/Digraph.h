//
//  Digraph.h
//  PA4
//
//  Created by Babak Farahmand on 3/3/19.
//  Copyright © 2019 Babak Farahmand. All rights reserved.
//

#ifndef Digraph_h
#define Digraph_h


#define INFINITY -1

#define UNVISITED -1
#define INPROGRESS -2
#define DONE -3

#include <stdio.h>
#include "List.h"


typedef struct DigraphObj* Digraph;
/*** Constructors-Destructors ***/

// Returns a Digraph that points to a newly created DigraphObj representing a digraph whic has
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


// Returns the number of outgoing neighbors that vertex u has in G, the number of vertices v such
// that (u, v) is an edge in G. Returns -1 if v is not a legal vertex.
int getOutDegree(Digraph G, int u);


// Returns a list that has all the vertices that are outgoing neighbors of vertex u, i.e.,
// a list that has all the vertices v such that (u, v) is an edge in G.
// There is no input operation that corresponds to getNeighbors.
List getNeighbors(Digraph G, int u);



// Returns the number of Strongly Connected Components in G.
int getCountSCC(Digraph G);



// Returns the number of vertices (including u) that are in the same Strongly Connected Component
// as u in G.. Returns -1 if u is not a legal vertex.
int getNumSCCVertices(Digraph G, int u);


// Returns 1 if u and v are in the same Strongly Connected Component of G, and returns 0 if u and v
// are not in the same Strongly Connected Component of the current digraph.
// A vertex is always in the same Strongly Connected Component as itself.
// Returns -1 if u is not a legal vertex.
/*** Manipulation procedures ***/
int inSameSCC (Digraph G, int u, int v);



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
/*** Other operations ***/

int deleteEdge(Digraph G, int u, int v);


// Outputs the digraph G in the same format as an input line, including the number of vertices
// and the edges. The edges should be in sorted order, as described above.
void printDigraph(FILE* out, Digraph G);

void reseTheGrapth(Digraph G);

void setMark(Digraph G, int u, int theMark);

int getMark(Digraph G, int u);

void DFS_Path(Digraph G);

void Visit(Digraph G,int w);

void DFS(Digraph G, List L);


#endif /* Digraph_h */
