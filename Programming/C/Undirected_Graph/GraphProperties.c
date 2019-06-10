//
//  GraphProperties.c
//  PA2
//
//  Created by Babak Farahmand on 2/7/19.
//  Copyright © 2019 Babak Farahmand. All rights reserved.
//

#include "List.h"
#include "Graph.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define PrintGraph 1
#define GetOrder 2
#define GetSize 3
#define GetNeighborCount 4
#define PathExists 5

#define MAX_LEN 1000

int inputChecker(char* c);
void pathExists(FILE* out, Graph G, int u, int v);

int main(int argc, char* argv[]){
    
    FILE *in, *out=NULL;
    char line[MAX_LEN];
    char* token=NULL;
    int i=0;
    List firstLine = newList();
    Node N = NULL;
    int lineCounter = 0;
    int funcCall=0;
    Graph G = NULL;
    int Ncount=0;
    
    
    //vertecies
    int v;
    int u;
    
    
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
    while(fgets(line, MAX_LEN, in) != NULL)  {
        token = strtok(line, " ,\n");
        while(token!=NULL && lineCounter == 0){
            append(firstLine, atoi(token));
            token = strtok(NULL, " ,\n");
            i++;
        }
        if (lineCounter == 0) {
            N = getFront(firstLine);
            if (getValue(N) == 0) {
                fprintf(out, "Graph size 0 doesn't exist");
                exit(1);
            }
            G = newGraph(getValue(N));
            N=getNextNode(N);
            while (N != NULL) {
                addEdge(G, getValue(N), getValue(getNextNode(N)));
                N=getNextNode(getNextNode(N));
            }
            
        }
        if (lineCounter > 0) {
            if (token[strlen(token)-1] == '\r') {
                token[strlen(token)-1]= 0;
            }
        funcCall = inputChecker(token);
        if (funcCall == 0) {
            fprintf(out, "The function in the line %d doesn't exist",lineCounter);
            exit(1);
        }else{
        switch (funcCall) {
            case PrintGraph:
                printGraph(out, G);
                break;
            case GetOrder:
                fprintf(out, "GetOrder \n%d \n",getOrder(G));
                break;
            case GetSize:
                fprintf(out, "GetSize \n%d \n",getSize(G));
                break;
            case GetNeighborCount:
                token = strtok(NULL, " \n");
                token[strlen(token)-1]= 0;
                Ncount = getNeighborCount(G,atoi(token));
                if (Ncount == -1) {
                    fprintf(out, "Error: Node %s doesn't exist \n",token);
                }else{
                fprintf(out, "GetNeighborCount %s \n",token);
                    fprintf(out, "%d \n",getNeighborCount(G,atoi(token)));}
                break;
            case PathExists:
                token = strtok(NULL, " \n");
                if (token == NULL) {
                    fprintf(out, "Error");
                    break;
                }
                u=atoi(token);
               
                token = strtok(NULL, " \n");
                if (token == NULL) {
                    fprintf(out, "Error");
                    break;
                }
                v=atoi(token);
 
                fprintf(out, "Path Exsits %d %d \n",u,v);
                pathExists(out,G,u,v);
                break;
            default:
                break;
        }
            
        }
            
        }
        lineCounter++;
    }


    /* close files */
    fclose(in);
    fclose(out);
    token = NULL;
    in = NULL;
    out = NULL;
    N = NULL;
    free(firstLine);
    freeGraph(&G);
    
    return(0);
}

// helper functions *******************************

int inputChecker(char* c){
    int result = 0;
    if (strcmp(c, "PrintGraph") == 0) {
        return 1;
    }
    else if(strcmp(c, "GetOrder") == 0){
        return 2;
    }
    else if(strcmp(c, "GetSize") == 0){
        return 3;
    }
    else if(strcmp(c, "GetNeighborCount") == 0){
        return 4;
    }
    else if(strcmp(c, "PathExists") == 0){
        return 5;
    }
    return result;
}


void pathExists(FILE* out, Graph G, int u, int v){
    if (G == NULL) {
        fprintf(out, "Graph is empty");
        exit(1);
    }

    unvisitAll(G);
    int theFoundValue = PathExistsRecursive(G,u,v);
    if (theFoundValue == FOUND){
        fprintf(out, "YES\n");
        
    }else{
        fprintf(out, "NO\n");
    }
}



