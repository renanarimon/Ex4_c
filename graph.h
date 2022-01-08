#ifndef EX4_EDGE_H
#define EX4_EDGE_H


typedef struct Edge {
    int weight;
    int dest;
    struct Edge *next;
} edge, *pEdge;

typedef struct Node{
    int id;
    struct Node* next;
    struct Edge* Edges;
    int weight;
    struct Node* father;
    int visited;
}node,*pNode;



#endif //EX4_EDGE_H
