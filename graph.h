#ifndef GRAPH
#define GRAPH

typedef struct Node *pNode;;

typedef struct edge {
    int weight;
    pNode dest;
    struct edge *next;
} edge, *pEdge;


typedef struct Node {
    int nodeId;
    pEdge edges;
    struct Node *next;
} node, *pNode;

void build_graph_cmd(pNode *head);
void insert_node_cmd(pNode *head);
void delete_node_cmd(pNode *head);
void printGraph_cmd(); //for self debug
void deleteGraph_cmd(pNode* head);
void shortsPath_cmd(pNode head);
void TSP_cmd(pNode head);

#endif
