//
//  Graph.c
//  PA2
//
//  Created by Babak Farahmand on 2/4/19.
//  Copyright © 2019 Babak Farahmand. All rights reserved.
//
#include "Graph.h"
#include "List.h"
#include<stdio.h>
#include<stdlib.h>


typedef struct GraphObj {
    int V;
    int E;
    List* list;
    int* state;
}GraphObj;

/*** Constructors-Destructors ***/

// Returns a Graph that points to a newly created GraphObj representing a graph which has
// n vertices and no edges.
Graph newGraph(int numVertices){
    int i = 1; // counter
    int memoAllocation = numVertices+1;
    Graph G = malloc(sizeof(GraphObj));
    G->E = 0;
    G->V = numVertices;
    G->state = (int *)calloc((memoAllocation), sizeof(int));
    G->list = (List *)calloc((memoAllocation), sizeof(List));
    while (i <= numVertices) {
        G->list[i] = newList();
        i++;
    }
    unvisitAll(G);
    return G;
}

// Frees all dynamic memory associated with its Graph* argument, and sets
// *pG to NULL.
/*** Access functions ***/
void freeGraph(Graph* pG){
    int i = 0;
    Graph G = *pG;
    while (i <= G->V) {
        freeList(&(*pG)->list[i]);
        i++;
    }
    free(*pG);
    *pG = NULL;
}

// Returns the order of G, the number of vertices in G.
int getOrder(Graph G){
    return G->V;
}

// Returns the size of G, the number of edges in G.
int getSize(Graph G){
    return G->E;
}

// Returns the number of neighbors that vertex v has in G. Returns -1 if v is not a legal vertex.
int getNeighborCount(Graph G, int v){
    if (v > G->V) {
        return -1;
    }
    Node N = getFront(G->list[v]);
    int count = 0;
    while (N != NULL) {
        count++;
        N=getNextNode(N);
    }
    return count;
}

// Returns a list that has all the vertices that are neighbors of u. There is no input operation
// that corresponds to getNeighbors.
/*** Manipulation procedures ***/
List getNeighbors(Graph G, int v){
    if (G->list[v] != NULL) {
        return G->list[v];
    }
    return 0;
}

// Adds v to the adjacency list of u and u to the adjacency list of v, if that edge doesn’t
// already exist. If the edge does already exist, does nothing. Used when edges are entered.
// Returns 0 if u and v are legal vertices, otherwise returns -1.
int addEdge(Graph G, int u, int v){
    int counter =0;
    if (G->V < u || G->V < v) {
        return -1;
    }
    else{
        counter += addEdgeHelper(G, u, v,counter);
        counter += addEdgeHelper(G ,v, u,counter);
        if (counter > 1) {
            G->E++;
        }
        return 0;
    }
}

// Marks all vertices of the graph as UNVISITED.
void unvisitAll(Graph G){
    int i = 1;
    while(i <= G->V){
        G->state[i] = UNVISITED;
        i++;
    }
}

// Returns the mark for vertex u, which will be UNVISITED, INPROGRESS or ALLDONE.
int getMark(Graph G, int u){
    return G->state[u];
}
// Sets the mark for vertex u to be theMark.
// theMark must be UNVISITED, INPROGRESS or ALLDONE.
void setMark(Graph G, int u, int theMark){
    G->state[u] = theMark;
    
}

// Described below; returns FOUND or NOTFOUND, which are (different) constants.
/*** Other operations ***/
int PathExistsRecursive(Graph G, int w, int v){
    Node x = NULL;
    int theFoundValue = 0;
    int theMark;
    if (w==v) return (FOUND);
    setMark(G,w,INPROGRESS);
    x = getFront( getNeighbors(G, w));
    while (x != NULL) {
        theMark= getMark(G,getValue(x));
        if (theMark == UNVISITED) {
            theFoundValue = PathExistsRecursive(G,getValue(x),v);
        }
        if (theFoundValue == FOUND) {
            return FOUND;
        }
        x=getNextNode(x);
    }
    setMark(G,w,ALLDONE);
    return NOTFOUND;
}

// Prints the Graph G in the same format as an input line, so all that a client need to do is a single
// call to PrintGraph(). But it should not print out an edge twice. Achieve this by only printing
// the edge for {j, k} when j < k.
void printGraph(FILE* out, Graph G){
    int i = 1;
    List L = NULL;
    Node N = NULL;
    if (G == NULL) {
        fprintf(out,"Graph is Empty!");
        exit(1);
    }
    fprintf(out,"%d",G->V);
    while (i < G->V) {
        L = G->list[i];
        N = getFront(L);
        while (N != NULL) {
            if (i<getValue(N)) {
            fprintf(out,", %d %d",i,getValue(N));
            }
            N=getNextNode(N);
        }
        i++;
    }
    fprintf(out,"\n");
    L=NULL;
    N=NULL;
}

//helper function of addEdge
int addEdgeHelper(Graph G, int headNode, int node, int counter){
   List L = G->list[headNode];
    if (getFront(L)!= NULL) {
        Node N = getFront(L);
        while (N != NULL) {
            if (getValue(N) == node) {
                return 0;
            }
            N = getNextNode(N);
        }
        N=NULL;
    }

    append(L, node);
    L=NULL;
    return ++counter;
    
}

