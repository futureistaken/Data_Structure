//
//  DigraphProperties.c
//  PA4
//
//  Created by Babak Farahmand on 3/3/19.
//  Copyright © 2019 Babak Farahmand. All rights reserved.
//

#include "List.h"
#include "Digraph.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PrintDigraph 1
#define GetSize 2
#define GetOrder 3
#define AddEdge 4
#define DeleteEdge 5
#define GetCountSCC 6
#define GetOutDegree 7
#define GetNumSCCVertices 8
#define InSameSCC 9


#define MAX_LEN 5000

int inputChecker(char* c);



int main(int argc, char* argv[]){
    
    FILE *in, *out=NULL;
    char line[MAX_LEN];
    char* token=NULL;
    int i=0;
    List firstLine = newList();
    Node N = NULL;
    int lineCounter = 0;
    int funcCall=0;
    Digraph G = NULL;
    // vertecies
    int u,v=0;
    
    int func_Result = 0;
    
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
            G = newDigraph(getValue(N));
            N = getNextNode(N);
            while (N != NULL) {
                addEdge(G, getValue(N), getValue(getNextNode(N)));
                N=getNextNode(getNextNode(N));
            }
            DFS_Path(G);
        }
        
        if (lineCounter > 0) {
            if (token[strlen(token)-1] == '\r') {
                token[strlen(token)-1]= 0;
            }
            funcCall = inputChecker(token);
            if (funcCall == 0) {
                fprintf(out, "The function '%s' doesn't exist\n",token);
            }else{
                switch (funcCall) {
                    case PrintDigraph:
                        fprintf(out, "PrintDigraph\n");
                        printDigraph(out,G);
                        break;
                    case GetSize:
                        fprintf(out, "GetSize \n%d \n",getSize(G));
                        break;
                    case GetOrder:
                        fprintf(out, "GetOrder \n%d \n",getOrder(G));
                        break;
                    case AddEdge:
                        fprintf(out, "AddEdge");
                        token = strtok(NULL, " \n");
                        if (token == NULL) {
                            fprintf(out, "\nError\n");
                            break;
                        }
                        u=atoi(token);
                        token = strtok(NULL, " \n");
                        if (token == NULL) {
                            fprintf(out, "\nError\n");
                            break;
                        }
                        v=atoi(token);
                        fprintf(out, " %d %d\n",u,v);
                       func_Result = addEdge(G, u, v);
                        DFS_Path(G);
                        switch (func_Result) {
                            case 1:
                                fprintf(out, "%d\n",1);
                                break;
                            case 0:
                                fprintf(out, "%d\n",0);
                                break;
                            case -1:
                                fprintf(out, "Error\n");
                                break;
                        }
                        break;
                    case DeleteEdge:
                        fprintf(out, "DeleteEdge");
                        token = strtok(NULL, " \n");
                        if (token == NULL) {
                            fprintf(out, "\nError\n");
                            break;
                        }
                        u=atoi(token);
                        token = strtok(NULL, " \n");
                        if (token == NULL) {
                            fprintf(out, "\nError\n");
                            break;
                        }
                        v=atoi(token);
                        fprintf(out, " %d %d\n",u,v);
                        func_Result = deleteEdge(G, u, v);
                        DFS_Path(G);
                        switch (func_Result) {
                            case 1:
                                fprintf(out, "%d\n",1);
                                break;
                            case 0:
                                fprintf(out, "%d\n",0);
                                break;
                            case -1:
                                fprintf(out, "Error\n");
                                break;
                        }
                        break;
                    case GetCountSCC:
                        fprintf(out, "GetCountSCC \n%d \n",getCountSCC(G));
                        break;
                    case GetOutDegree:
                        fprintf(out, "GetOutDegree");
                        token = strtok(NULL, " \n");
                        if (token == NULL) {
                            fprintf(out, "\nError\n");
                            break;
                        }
                        u=atoi(token);
                        fprintf(out, " %d",u);
                        func_Result = getOutDegree(G, u);
                        if (func_Result == -1) {
                            fprintf(out, "\nError\n");
                            break;
                        }
                        fprintf(out, "\n%d\n",func_Result);
                        break;
                    case GetNumSCCVertices:
                        fprintf(out, "GetNumSCCVertices");
                        token = strtok(NULL, " \n");
                        if (token == NULL) {
                            fprintf(out, "\nError\n");
                            break;
                        }
                        u=atoi(token);
                        if (getNumSCCVertices(G,u) == -1) fprintf(out, "\nError\n");
                        else fprintf(out, " %d\n%d\n",u,getNumSCCVertices(G,u));
                        break;
                    case InSameSCC:
                        fprintf(out, "InSameSCC");
                        token = strtok(NULL, " \n");
                        if (token == NULL) {
                            fprintf(out, "\nError\n");
                            break;
                        }
                        u=atoi(token);
                        fprintf(out, " %d ",u);
                        token = strtok(NULL, " \n");
                        if (token == NULL) {
                            fprintf(out, "\nError\n");
                            break;
                        }
                        v=atoi(token);
                        fprintf(out, "%d    \n",v);
                        func_Result = inSameSCC(G,u,v);
                        switch (func_Result) {
                            case 1:
                                fprintf(out, "YES\n");
                                break;
                            case 0:
                                fprintf(out, "NO\n");
                                break;
                            case -1:
                                fprintf(out, "Invalid edge inSameSCC ()\n");
                                break;
                        }
                        func_Result = 0;
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
    freeDigraph(&G);
    return(0);
}

// helper functions *******************************

int inputChecker(char* c){
    int result = 0;
    if (strcmp(c, "PrintDigraph") == 0) {
        return 1;
    }
    else if(strcmp(c, "GetSize") == 0){
        return 2;
    }
    else if(strcmp(c, "GetOrder") == 0){
        return 3;
    }
    else if(strcmp(c, "AddEdge") == 0){
        return 4;
    }
    else if(strcmp(c, "DeleteEdge") == 0){
        return 5;
    }
    else if(strcmp(c, "GetCountSCC") == 0){
        return 6;
    }
    else if(strcmp(c, "GetOutDegree") == 0){
        return 7;
    }
    else if(strcmp(c, "GetNumSCCVertices") == 0){
        return 8;
    }
    else if(strcmp(c, "InSameSCC") == 0){
        return 9;
    }
    return result;
}





