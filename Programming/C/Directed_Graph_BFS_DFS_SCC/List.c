//
//  List.c
//  PA1
//
//  Created by Babak Farahmand on 1/16/19.
//  Copyright © 2019 Babak Farahmand. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include "List.h"

// private NodeObj type
typedef struct NodeObj {
    int data;
    struct NodeObj *next;
    struct NodeObj *prev;
} NodeObj;

// private List type
typedef struct ListObj {
    Node front; // First Node
    Node back; // Last Node
    int length;
} ListObj;

// returns a List which points to a new empty list object
List newList(void){
    List L = malloc(sizeof(ListObj));
    L->front=NULL;
    L->back=NULL;
    L->length = 0;
    return L;
}

// returns a node which points to a new empty list object
Node newNode(int data){
    Node N = malloc(sizeof(NodeObj));
    N->next=NULL;
    N->prev=NULL;
    N->data=data;
    return N;
}

// frees all heap memory associated with its List* argument,
// and sets *pL to NULL
// Access functions
void freeList(List* pL){
    List L = *pL;
    if (L == NULL) {
        return;
    }else{
    
    while (L->length >0) {
        deleteFront(*pL);
    }
    free(*pL);
        *pL = NULL;}
}

// Returns the number of nodes in this List.
int length(List L){
    if (L == NULL) {
        printf("List is Empty - Lenght()");
        exit(1);
    }
    return L->length;
}

// Returns the integer in the front Node.
// Precondition: L has at least one Node on it.
int frontValue(List L){
    if (L->length > 0) {
        return L->front->data;
    }
    else {
        printf("List Is Empty - frontValue()");
        exit(1);
    }
    
}

// Returns the integer in the back Node.
// Precondition: L has at least one Node on it.
int backValue(List L){
    if (L->length > 0) {
        return L->back->data;
    }
    else {
        printf("List Is Empty - frontValue()\n");
        exit(1);
    }
}

// Returns the integer in Node N.
// Precondition: N is not NULL
int getValue(Node N){
    if (N == NULL) {
        printf("Get Value(): Node is NULL \n");
        exit(1);
    }
    int value = N->data;
    return value;
}

// Returns 1 if if List A and List B are the same integer
// sequence, otherwise returns 0.
// Manipulation procedures
int equals(List A, List B){
    int eq = 0;
    Node N = NULL;
    Node M = NULL;
    
    if( A==NULL || B==NULL ){
        printf("equals(): one/both list(s) are ");
        exit(1);
    }
    
    eq = ( A->length == B->length );
    N = A->front;
    M = B->front;
    while( eq && N!=NULL){
        eq = (N->data==M->data);
        N = N->next;
        M = M->next;
    }
    return eq;
}

// Resets this List to the empty state.
void Clear(List L){
    if (L == NULL) {
        fprintf(stderr,"List is NULL");
        exit(1);
    }
    Node N = L->front;
    Node NodeHolder = NULL;
    while (N->next != NULL){
        NodeHolder = N;
        N = N->next;
        free(NodeHolder);
        NodeHolder = NULL;

    }
    L->front = L->back = NULL;
    L->length = 0;
}

// If List is non-empty, returns the front Node, without
// changing the List. Otherwise, does nothing.
Node getFront(List L){
    if (L==NULL) {
            return NULL;
    }
    if (L->length > 0) {
        return L->front;
    }
    return NULL;
}

// If List is non-empty, returns the back Node, without
// changing the List. Otherwise, does nothing.
Node getBack(List L){
    if (L->length > 0) {
        return L->back;
    }
    else exit(0);
}

// Without changing the List that N is on, returns the
// Node that is previous to Node N on its List. If
// there is no previous Node, returns NULL.
Node getPrevNode(Node N){
    if (N->prev == NULL) {
        return NULL;
    }
    else{
        return N->prev;
    }
}

// Without changing the List that N is on, returns the
// Node that is next after Node N on its List. If
// there is no next Node, returns NULL.
Node getNextNode(Node N){
    if (N->next == NULL) {
        return NULL;
    }
    else{
        return N->next;
    }
}

// Inserts a new Node into List L before the front
// Node that has data as its value. If List is empty,
// makes that new Node the only Node on the list.
void prepend(List L, int data){
    Node NN = newNode(data);
    if (L->length == 0) {
        L->back = NN;
        L->front = NN;
        L->length++;
        return;
    }
    NN->next = L->front;
    L->front->prev = NN;
    L->front = NN;
    L->length++;
}

// Inserts a new Node into List L after the back
// Node that has data as its value. If List is empty,
// makes that new Node the only Node on the list
void append(List L, int data){
    Node NN = newNode(data);
    if (L->length == 0) {
        L->back = NN;
        L->front = NN;
        L->length++;
        return;
    }
    NN->prev = L->back;
    L->back->next = NN;
    L->back = NN;
    L->length++;
}

// Insert a new Node into Node N’s list
// before Node N that has data as its value.
// Assume that Node N is on List L. If Node N is
// the front of List L, then N becomes the new front.
// Precondition: Node N is not NULL
void insertBefore(List L,Node N, int data){
    Node NN = newNode(data);
            if (N->prev == NULL) {
                NN->next = N;
                N->prev = NN;
                L->front = NN;
                L->length++;
            }
            else{
                NN->prev = N->prev;
                NN->next = N;
                N->prev->next = NN;
                N->prev = NN;
                L->length++;
        }
}

// Insert a new Node into Node N’s list
// after Node N that has data as its value.
// Assume that Node N is on List L. If Node N is
// the back of List L, then N becomes the new back.
// Precondition: Node N is not NULL
void insertAfter(List L, Node N, int data){
    Node NN = newNode(data);
            if (N->next == NULL) {
                NN->prev = N;
                N->next=NN;
                L->back = NN;
                L->length++;
            }
            else{
                N->next->prev = NN;
                NN->next = N->next;
                N->next = NN;
                NN->prev = N;
                L->length++;
            }
}

// Deletes the front Node in List L.
// Precondition: L has at least one Node on it.
void deleteFront(List L){
        Node N = L->front;
        L->front = N->next;
        free(N);
        N = NULL;
        L->length--;
}

// Deletes the back Node in List L.
// Precondition: L has at least one Node on it.
void deleteBack(List L){
    Node N = L->back;
    L->back = L->back->prev;
    free(N);
    N = NULL;
    L->length--;
}

// Prints the values in List L from front to back
// to the file pointed to by out, formatted as a
// space-separated string.
// For those familiar with Java, this is similar
// to toString()in Java.
// Optional Manipulation procedures
void printList(FILE* out, List L){
    Node N = L->front;
    while (N != NULL) {
        fprintf(out, "%d ",N->data);
        N = N->next;
    }
    
}

// Optional Manipulation procedures -------------------------------------------------

// This operation is optional.
// Removes N from List L by making the Node before
// Node N link to the Node that’s after Node N as its
// next Node, and making the Node after Node N link to
// the Node that’s before Node N as its previous Node.
//
// After detachNode, Node N should have NULL as both its
// next and previous Nodes.
//
// Special cases:
//
// If Node N is the front the List L, then the Node after
// Node N becomes the front of List L, which should have
// a NULL previous Node.
//
// If Node N is the back of List L, then the Node before
// Node N becomes the back of List L, which should have
// a NULL next Node.
//
// Precondition: N is not NULL and N is a Node on List L.
void detachNode(List L, Node N);

// This operation is optional.
// Deletes Node N from List L.
// Removes N from List L by making the Node before
// Node N link to the Node that’s after Node N as its
// next Node, and making the Node after Node N link to
// the Node that’s before Node N as its previous Node.
//
// Special cases:
//
// If Node N is the front the List L, then the Node after
// Node N becomes the front of List L, which should have
// a NULL previous Node.
//
// If Node N is the back of List L, then the Node before
// Node N becomes the back of List L, which should have
// a NULL next Node.
//
// Precondition: N is not NULL and N is a Node on List L.
void deleteNode_int(List L, int n){
    int count = 0;
    Node x_front = getFront(L);
    Node x_end = getBack(L);
    if (getValue(x_front) == n) {
        deleteFront(L);
        count++;
    }
    if (getValue(x_end) == n) {
        deleteBack(L);
        count++;
    }
    if (count == 0) {
        while (x_front != NULL) {
            if (getValue(x_front) == n) {
                getPrevNode(x_front)->next = getNextNode(x_front)->prev;
                getNextNode(x_front)->prev =  getPrevNode(x_front)->next;
                x_front = NULL;
                break;
            }
            x_front=getNextNode(x_front);
        }
    }

    
}

// This operation is optional.
// Attaches Node N between Nodes N1 and N2. Makes N1's
// next Node be N, and N's previous Node be N1. Makes
// N2's previous Node be N, and N's next Node be N2.
//
// Special cases:
//
// If N1 is NULL and N2 is the front of List L, makes N
// the front of List L, which should have a NULL
// previous Node, and whose next Node should be N2.
//
// If N1 is the back of List L and N2 is NULL, makes N
// the back of List L, which should have a NULL next
// Node, and whose previous Node should be N1.
//
// Preconditions: N1 and N2 are adjacent nodes on List
// L, with N2 being N1's next node and N1's being N2's
// previous node. If N1 is NULL, then N2 is the front of
// list L. If N2 is NULL, then N1 is the back of List L.
void attachNodeBetween(List L, Node N, Node N1, Node N2);

void setValue(Node N, int M){
    N->data = M;
}
void Listsort(List L){
    Node a,j,i = NULL;
    int key;
    prepend(L, '\0');
    a = getFront(L);
    i=getNextNode(a);
    for (;i != NULL; i=getNextNode(i)) {
        key = getValue(i);
        j=getPrevNode(i);
        while (j!= NULL && getValue(j) > key) {
            setValue(getNextNode(j),getValue(j));
            if (getPrevNode(j) != NULL) {
                j = getPrevNode(j);
            }
            else break;
        }
        setValue(getNextNode(j),key);
    }
    deleteFront(L);
}
