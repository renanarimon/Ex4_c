#include <stdio.h>
#include <stdlib.h>
// #include "nodes.h"
// #include"edges.h"
#include "graph.h"

static pNode graphNodes;
// static edges* graphEdges;
pNode GetNode(int data);

void createNodes(int size)
{
    pNode tmp = (pNode)malloc(sizeof(node));
    tmp->nodeId = size - 1;
    tmp->next = NULL;
    tmp->edges = NULL;
    for (int i = size - 2; i >= 0; i--)
    {
        pNode newNode = (pNode)malloc(sizeof(node));
        newNode->nodeId = i;
        newNode->next = tmp;
        tmp = newNode;
    }
    graphNodes = tmp;
}

void createGraph()
{
    int num1;
    int num2;
    int srcId;
    pEdge e = (pEdge)malloc(sizeof(edge));
    scanf("%d", &srcId);
    printf("srcId: %d\n", srcId);
    pNode p = GetNode(srcId);
    printf("p: %d\n", p->nodeId);
    if (scanf("%d", &num1) == 1)
    {
        if (scanf("%d", &num2) == 1)
        {
            printf("num1: %d, num2: %d\n", num1, num2);
            e->weight = num2;
            p->edges = e;
            e->dest = GetNode(num1);
            e->next = NULL;
        }
    } 

    while (scanf("%d", &num1) == 1)
    {
        if (scanf("%d", &num2) == 1)
        {
            pEdge tmp = (pEdge)malloc(sizeof(edge));
            e->next = tmp;
            tmp->weight = num2;
            tmp->dest = GetNode(num1);
            e = tmp;
        }
    }
}

pNode GetNode(int data)
{
    pNode p = graphNodes;
    while (p->nodeId != data)
    {
        p = p->next;
    }
    return p;
}

void deleteGraph_cmd(){
    pNode* tmp = &graphNodes;
    int nodeId;
    while (*tmp)
    {
        nodeId = (*tmp)->nodeId;
        deleteNode(nodeId);
        
    }
    
}


void printGraph_cmd()
{
    pNode head = graphNodes;
    printf("{");
    while (head)
    {
        printf("[id: %d, ", head->nodeId);
        pEdge ep = head->edges;
        printf("edges: ");
        while (ep)
        {
            printf("w: %d, dest: %d, ", ep->weight, ep->dest->nodeId);
            ep = ep->next;
        }
        printf("], ");
        head = head->next;
    }
    printf("}");
}
