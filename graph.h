#ifndef GRAPH
#define GRAPH

typedef struct Node *pNode;

typedef struct edge {
    int weight;
    pNode dest;
    struct edge* next;
} edge, *pEdge;


typedef struct Node {
    int nodeId;
    int weight;
    pEdge edges;
    struct Node* next;
    struct Node* parent;
    int visited;
} node;

#endif
