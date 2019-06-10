//
//  Digraph.c
//  PA3
//
//  Created by Babak Farahmand on 2/15/19.
//  Copyright © 2019 Babak Farahmand. All rights reserved.
//

#include "Digraph.h"
#include "List.h"
#include<stdio.h>
#include<stdlib.h>



typedef struct DigraphObj {
    int V;
    int E;
    List* list;
    int* state;
    int Cycle;
    int* EndTime;
}DigraphObj;

Digraph newDigraph(int numVertices){
    int i = 1; // counter
    int memoAllocation = numVertices+1;
    Digraph G = malloc(sizeof(DigraphObj));
    G->E = 0;
    G->Cycle = -1;
    G->V = numVertices;
    G->state = (int *)calloc((memoAllocation), sizeof(int));
    G->EndTime = (int *)calloc((memoAllocation), sizeof(int));
    G->list = (List *)calloc((memoAllocation), sizeof(List));
    while (i <= numVertices) {
        G->list[i] = newList();
        i++;
    }
    /*
     State = UNVISITED
     startTime = INFINITY
     endTime = INFINITY
     */
    reseTheList(G);
    return G;
}
void freeDigraph(Digraph* pG){
    int i = 0;
    Digraph G = *pG;
    while (i <= G->V) {
        freeList(&(*pG)->list[i]);
        i++;
    }
    free(*pG);
    *pG = NULL;
}

/*** Access functions ***/

// Returns the order of G, the number of vertices in G.
int getOrder(Digraph G){
    return G->V;
}

// Returns the size of G, the number of edges in G.
int getSize(Digraph G){
    return G->E;
}

// Returns the number of neighbors that vertex v has in G. Returns -1 if v is not a legal vertex.
int getNeighborCount(Digraph G, int v){
    return 0;
}

// Returns a list that has all the vertices that are neighbors of v. There is no input operation
// that corresponds to getNeighbors.
List getNeighbors(Digraph G, int v){
    if (G->list[v] != NULL) {
        return G->list[v];
    }
    return 0;
}

/*** Manipulation procedures ***/

// Adds v to the adjacency list of u, if that edge doesn’t already exist.
// If the edge does already exist, does nothing. Used when edges are entered or added.
// Returns 0 if (u, v) is a legal edge, and the edge didn’t already exist.
// Returns 1 if (u, v) is a legal edge and the edge did already exist.
// Returns -1 if (u, v) is not a legal edge.
int addEdge(Digraph G, int u, int v){
    int result = 2;
    List L = G->list[u];
    if (getFront(L)!= NULL) {
        Node N = getFront(L);
        while (N != NULL) {
            if (getValue(N) == v) {
                return 1;
            }
            N = getNextNode(N);
        }
        N=NULL;
    }
    if (G->V < u || G->V < v || v < 0 || u < 0) {
        return -1;
    }
    else{
        append(L, v);
        G->E++;
        return 0;
    }
    return result;
    L = NULL;
}


// Deletes v from the adjacency list of u, if that edge exists.
// If the edge doesn’t exist, does nothing. Used when edges are deleted.
// Returns 0 if (u, v) is a legal edge, and the edge did already exist.
// Returns 1 if (u, v) is a legal edge and the edge didn’t already exist.
// Returns -1 if (u, v) is not a legal edge.
int deleteEdge(Digraph G, int u, int v){
    int result = 2;
    List L = G->list[u];
    if (getFront(L)!= NULL) {
        Node N = getFront(L);
        while (N != NULL) {
            if (getValue(N) == v) {
                return 1;
            }
            N = getNextNode(N);
        }
        N=NULL;
    }
    if (G->V < u || G->V < v || v < 0 || u < 0) {
        return -1;
    }
    else{
        //deleteNode(L, v);
        G->E--;
        return 0;
    }
    return result;
    L = NULL;
}


/*** Other operations ***/
// Outputs the digraph G in the same format as an input line, including the number of vertices
// and the edges. The edges should be in sorted order, as described above.
void printDigraph(FILE* out, Digraph G){
    int i = 1;
    List L = NULL;
    Node N = NULL;
    if (G == NULL) {
        fprintf(out,"Graph is Empty!");
        exit(1);
    }
    fprintf(out,"%d",G->V);
    while (i <= G->V) {
        L = G->list[i];
        N = getFront(L);
        while (N != NULL) {
            
                fprintf(out,", %d %d",i,getValue(N));
            
            N=getNextNode(N);
        }
        i++;
    }
    fprintf(out,"\n");
    L=NULL;
    N=NULL;
    
    
}

// Outputs the distance between vertices u and v if there is a directed path between them in the
// digraph. Otherwise, outputs INF
void distance(FILE* out, Digraph G, int u, int v){
fprintf(out, "INF");
}

// Outputs YES if the digraph is acyclic. Otherwise, outputs NO.
void acyclic(FILE* out, Digraph G){
    //
    int result;
    int i = 1;
    while (i<=G->V) {
        result = DFSRecursive (G,i);
        if (result == FOUND) {
        fprintf(out, "NO");
        return;
        }
        i++;
    }
    fprintf(out, "YES");
}

// Outputs a topological sort of the digraph. If the digraph is not acyclic, outputs IMPOSSIBLE.
void topoSort(FILE* out, Digraph G){
    if (G->Cycle == YesCycle && G->V > 0) {
        fprintf(out, "This is a graph but not a tree, there is cycle exits");
        exit(1);
    }
    else if (G->V <= 0){
        fprintf(out, "Graph with 0 vertix doens't exit");
        exit(1);
    }

}
// Deletes v from the adjacency list of u, if that edge exists.
// If the edge doesn’t exist, does nothing. Used when edges are deleted.
// Returns 0 if (u, v) is a legal edge, and the edge did already exist.
// Returns 1 if (u, v) is a legal edge and the edge didn’t already exist.
// Returns -1 if (u, v) is not a legal edge.

//helper functions

/*
 State = UNVISITED
 startTime = INFINITY
 endTime = INFINITY
 */
void reseTheList(Digraph G){
    int i = 1;
    while(i <= G->V){
        G->state[i] = UNVISITED;
        G->EndTime[i] = 0;
        i++;
    }
}

// DFS

int DFSRecursive(Digraph G, int w){
    Node x = NULL;
    int theFoundValue = 0;
    int theMark = 0;
    setMark(G,w,INPROGRESS);
    x = getFront(getNeighbors(G, w));
    if (x == NULL) {
      
    }
    while (x != NULL) {
        theMark= getMark(G,getValue(x));
        if (theMark == UNVISITED) {
            G->EndTime[w]++;
            theFoundValue = DFSRecursive(G,getValue(x));
        }
        if (G->state[w] == INPROGRESS ) {
            return FOUND;
        }
        x=getNextNode(x);
    }   
    G->EndTime[w]++;
    setMark(G,w,ALLDONE);
    return NOTFOUND;
    
}

void setMark(Digraph G, int u, int theMark){
    G->state[u] = theMark;
    
}
int getMark(Digraph G, int u){
    return G->state[u];
}
void acyclic(FILE* out, Digraph G){
    //
    int result;
    int i = 1;
    while (i<=G->V) {
        result = AcycleFinder (G,i);
        if (result == FOUND) {
            fprintf(out, "NO");
            return;
        }
        i++;
    }
    fprintf(out, "YES");
}
int AcycleFinder(Digraph G, int w){
    Node x = NULL;
    int theFoundValue = 0;
    int theMark = 0;
    G->EndTime[w] = 0;
    setMark(G,w,INPROGRESS);
    x = getFront(getNeighbors(G, w));
    while (x != NULL) {
        theMark= getMark(G,getValue(x));
        if (theMark == UNVISITED) {
            theFoundValue = AcycleFinder(G,getValue(x));
        }
        if (G->state[getValue(x)] == INPROGRESS ) {
            G->Cycle = NoCycle;
            return FOUND;
        }
        x=getNextNode(x);
    }
    setMark(G,w,ALLDONE);
    G->Cycle = YesCycle;
    return NOTFOUND;
    
}
