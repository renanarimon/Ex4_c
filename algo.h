#ifndef GRAPH_
#define GRAPH_
#include "graph.h"

pNode createNode(int id, pNode next);
pNode getNode(pNode head,int id);
void addNode(pNode head, int id);
void removeNode(pNode head, int id);
void FreeEdges(pNode head,int id);
pEdge createEdge(int weight, int dest);
pEdge getEdge(pNode src, int dest);
void addEdge(pNode src, int weight, int dest);
void delEdge(pNode src,int dest);
char createGraph(pNode head);
char insert_node_cmd(pNode head);
void delete_node_cmd(pNode head);
void deleteGraph_cmd(pNode head);
void restartGraph(pNode h);

void swap(int *x, int *y);
int permute(int cities[], int l, int r, int len, int currWeight, pNode head, int ans[]);
void dijkstra (pNode head,int key);
void shortestPath(pNode head);
void TSP(pNode head);




#endif
