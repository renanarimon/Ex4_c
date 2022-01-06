//
// Created by PC on 12/29/2021.
//

#ifndef EX4_ALGO_H
#define EX4_ALGO_H

#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

pNode createNode(int id, pNode next, pEdge edge);
void createNodes(int n,pNode h);
void printGraph_cmd(pNode);
pNode GetNode(int, pNode);
void addEdges(pNode node);
void addNode(pNode);
void createGraph(pNode);
void deleteNode(int, pNode);
void deleteGraph_cmd(pNode);
void relax(pNode src, pNode dest, pEdge e);
void dijkstra(int src, int dest , pNode);
int contains(int nodeId , pNode);
pNode getLast(pNode);
void freeEdgesOfNode(pNode p);
int shortestPath(int src, int dest, pNode h);
void TSP(int,pNode);
void swap(int *x, int *y);
void permutation(int a[], int size, int n ,pNode);

#endif //EX4_ALGO_H
