//
// Created by PC on 12/29/2021.
//

#ifndef EX4_ALGO_H
#define EX4_ALGO_H

#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

void createNodes(int);
void printGraph_cmd();
pNode GetNode(int data);
void addEdges(pNode node);
void addNode();
void createGraph();
void deleteNode(int num);
void deleteGraph_cmd();
void relax(pNode src, pNode dest, pEdge e);
void dijkstra(int src, int dest);
int contains(int nodeId);
pNode createNode(int id, pNode next, pEdge edge);
pNode getLast();
void freeEdgesOfNode(pNode p);
int shortestPath(int src, int dest);
void combinationUtil(int arr[], int n, int index,int data[], int i);
void TSP(int num);
#endif //EX4_ALGO_H
