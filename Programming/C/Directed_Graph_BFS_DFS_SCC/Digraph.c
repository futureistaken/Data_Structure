//
//  Digraph.c
//  PA4
//
//  Created by Babak Farahmand on 3/3/19.
//  Copyright © 2019 Babak Farahmand. All rights reserved.
//
#include "Digraph.h"
#include "List.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct DigraphObj {
    int V; //Vertex
    int E; // edge
    int revese_state; // 0 = DFS on Original Graph / 1 = DFS on Revesed Graph
    
    int* state; // Unvisited - Inprogress - Done
    int* SCC_List; // This is a data structure that maintaine and defines SCCs
    
    List* list; // adjacancy list
    List* rev_List; // reverse_adjacancy list
    
    List FinishedL; // A list that holds the vertex with the largest finishind time in order
    
    
}DigraphObj;

Digraph newDigraph(int numVertices){
    int i = 1; // counter
    int memoAllocation = numVertices+1;
    
    Digraph G = malloc(sizeof(DigraphObj));
    
    G->E = 0;
    G->V = numVertices;
    G->revese_state = 0;
    
    G->state = (int *)calloc((memoAllocation), sizeof(int));
    G->SCC_List = (int *)calloc((memoAllocation), sizeof(int));
    
    G->FinishedL = newList();
    
    G->list = (List *)calloc((memoAllocation), sizeof(List));
    G->rev_List = (List *)calloc((memoAllocation), sizeof(List));
    
    
    while (i <= numVertices) {
        G->list[i] = newList();
        G->rev_List[i] = newList();
        i++;
    }
    
    /*
     State = UNVISITED
     startTime = INFINITY
     endTime = INFINITY
     */
    reseTheGrapth(G);
    return G;
}

// Frees all dynamic memory associated with its Digraph* argument, and sets
// *pG to NULL.
void freeDigraph(Digraph* pG){
    int i = 0;
    Digraph G = *pG;
    while (i <= G->V) {
        freeList(&(*pG)->list[i]);
        freeList(&(*pG)->rev_List[i]);
        i++;
    }
    freeList(&(*pG)->FinishedL);
    free(*pG);
    *pG = NULL;
}

void reseTheGrapth(Digraph G){
    int i = 0;
    while(i <= G->V){
        G->state[i] = UNVISITED;
        i++;
    }
    G->SCC_List[0]=0;
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

// Returns the number of outgoing neighbors that vertex u has in G, the number of vertices v such
// that (u, v) is an edge in G. Returns -1 if v is not a legal vertex.
int getOutDegree(Digraph G, int u){
    if (u > G->V || u < 0) return -1;
    int result = 0;
    Node x = NULL;
    G->revese_state = 0;
    x = getFront(getNeighbors(G, u));
    while (x != NULL) {
        result++;
        x= getNextNode(x);
    }
    x = NULL;
    return result;
}


// Returns a list that has all the vertices that are outgoing neighbors of vertex u, i.e.,
// a list that has all the vertices v such that (u, v) is an edge in G.
// There is no input operation that corresponds to getNeighbors.
List getNeighbors(Digraph G, int u){
    if (G->list[u] == NULL) {
        fprintf(stdout, "\nError - getNeighbors\n");
    }
    
    else if (G->revese_state == 0) {
        return G->list[u];
    }
    
    return G->rev_List[u];
}

void setMark(Digraph G, int u, int theMark){
    G->state[u] = theMark;
    
}

// get the  mark of the requested vertext
int getMark(Digraph G, int u){
    return G->state[u];
}

// Returns the number of Strongly Connected Components in G.
int getCountSCC(Digraph G){
    return G->SCC_List[0];
}
// Returns the number of vertices (including u) that are in the same Strongly Connected Component
// as u in G.. Returns -1 if u is not a legal vertex.
int getNumSCCVertices(Digraph G, int u){
    if (u > G->V || u < 0) return -1;
    
    int result = 0;
    int i = 1;
    
    while (i <= G->V) {
        if (G->SCC_List[u] == G->SCC_List[i]) {
            result++;
        }
        i++;
    }
    return result;
}


// Returns 1 if u and v are in the same Strongly Connected Component of G, and returns 0 if u and v
// are not in the same Strongly Connected Component of the current digraph.
// A vertex is always in the same Strongly Connected Component as itself.
// Returns -1 if u is not a legal vertex.
/*** Manipulation procedures ***/
int inSameSCC (Digraph G, int u, int v){
    
    if (G->V < u || G->V < v || v < 0 || u < 0) {
        return -1;
    }
    
    if (G->SCC_List[u] == G->SCC_List[v]) {
        return 1;
    }
    
    return 0;
}

// DFS_Path_Function //

void DFS_Path(Digraph G){
    List H = newList();
    // create a dummy list to run the dfs over everysingle vertex in my graph
    for (int i=1; i<=G->V; i++) {
        append(H,i);
    }
    
    DFS(G,H);
    G->revese_state = 1;
    reseTheGrapth(G);
    DFS(G, G->FinishedL);
    freeList(&H);
}

void DFS(Digraph G, List L){
    G->SCC_List[0] = 0;
    Node x = NULL;
    x = getFront(L);
    while (x != NULL) {
        if (getMark(G,getValue(x)) == UNVISITED) {
            G->SCC_List[0]++;
            Visit(G, getValue(x));
        }
        x = getNextNode(x);
    }
}

void Visit(Digraph G,int w){    // w = source node
    Node x = NULL;
    int theMark = 0;
    setMark(G,w,INPROGRESS);    // set the mark to inprogress for the first vertext
    x = getFront(getNeighbors(G, w));   // get all the neighbors related to the source
    while (x != NULL) {
        theMark= getMark(G,getValue(x));    // get the mark/sing of the first neighbor
        if (theMark == UNVISITED) {         // if the first neighbor was unvisited -
            Visit(G,getValue(x));           // make the neighbor the source
        }
        x = getNextNode(x);
    }
    setMark(G,w,DONE);
    if (G->revese_state == 0) {
        prepend(G->FinishedL,w);
    }
    else if (G->revese_state == 1){
        G->SCC_List[w] = G->SCC_List[0];
    }
}

/*** Add / Delete Functions ***/

// Adds v to the adjacency list of u, if that edge doesn’t already exist.
// If the edge does already exist, does nothing. Used when edges are entered or added.
// Returns 0 if (u, v) is a legal edge, and the edge didn’t already exist.
// Returns 1 if (u, v) is a legal edge and the edge did already exist.
// Returns -1 if (u, v) is not a legal edge.
int addEdge(Digraph G, int u, int v){
    if (G->V < u || G->V < v || v < 0 || u < 0) {
        return -1;
    }
    
    List L = G->list[u];
    List L_rev = G->rev_List[v];
    
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
    
    append(L, v);
    append(L_rev, u);
    G->E++;
    
    Listsort(L);
    Listsort(L_rev);
    
    L = NULL;
    
    return 0;
}

// Deletes v from the adjacency list of u, if that edge exists.
// If the edge doesn’t exist, does nothing. Used when edges are deleted.
// Returns 0 if (u, v) is a legal edge, and the edge did already exist.
// Returns 1 if (u, v) is a legal edge and the edge didn’t already exist.
// Returns -1 if (u, v) is not a legal edge.
int deleteEdge(Digraph G, int u, int v){
    if (G->V < u || G->V < v || v < 0 || u < 0) {
        return -1;
    }
    int mark = 0;
    
    List L = G->list[u];
    List L_rev = G->rev_List[v];
    
    Node N_L = getFront(L);
    Node N_L_Rev = getFront(L_rev);
    
    if (getFront(L)!= NULL) {
        while (N_L != NULL) {
            if (getValue(N_L) == v) {
                deleteNode_int(L,v);
                mark++;
            }
            N_L = getNextNode(N_L);
        }
        N_L = NULL;
    }
    
    if (getFront(L_rev)!= NULL) {
        while (N_L_Rev != NULL) {
            if (getValue(N_L_Rev) == u) {
                deleteNode_int(L_rev,u);
                mark++;
            }
            N_L_Rev = getNextNode(N_L_Rev);
        }
        N_L_Rev = NULL;
    }
    if (mark == 2) {
        Listsort(L);
        reseTheGrapth(G);
        DFS_Path(G);
        return 0;
    }
    
    L = NULL;
    
    return 1;
    
}

/*** Print Functions ***/

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

void print_arry(int* A,int size){
    for (int i = 1; i <=size; i++) {
        printf("%d , ",A[i]);
    }
}

