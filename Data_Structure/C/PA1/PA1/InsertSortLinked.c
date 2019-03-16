//
//  InsertSortLinked.c
//  PA1
//
//  Created by Babak Farahmand on 1/16/19.
//  Copyright © 2019 Babak Farahmand. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"List.h"

#define MAX_LEN 1000

int main(int argc, char* argv[]){
    
    FILE *in, *out;
    char line[MAX_LEN];
    List tokenlist = newList();
    char* token;
    
    // insertion sort variables
    Node i,j,a;
    int key;
    
    if( argc != 3 ){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }
    in = fopen(argv[1],"r");
    out = fopen(argv[2],"w");
    if (in == NULL) {
        printf("problem reading the input file");
        exit(1);
    }
    if (out == NULL) {
        printf("problem writing on the outpu file");
        exit(1);
    }
    
    /* read each line of input file, then count and print tokens */
    while( fgets(line, MAX_LEN, in) != NULL)  {
        token = strtok(line, " \n");
        while(token!=NULL ){
            append(tokenlist,atoi(token));
            token = strtok(NULL, " \n");
        }
        prepend(tokenlist, '\0');
        a = getFront(tokenlist);
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
        deleteFront(tokenlist);
        printList(out, tokenlist);
        fprintf(out,"\n");
       //clear(tokenlist);
        }
    /* close files */
    fclose(in);
    fclose(out);
    freeList(&tokenlist);
    i = NULL;
    j = NULL;
    a = NULL;
    token = NULL;
    in = NULL;
    out = NULL;
    
    return(0);
}
