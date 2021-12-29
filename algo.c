//
// Created by PC on 12/29/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "priorityQueue.h"


static pNode graphNodes;
static int minPath = __INT_MAX__;
// static edges* graphEdges;
pNode GetNode(int data);
void deleteGraph_cmd();

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
    printf("}\n");
}

pNode createNode(int id, pNode next, pEdge edge){
    pNode tmp = (pNode)malloc(sizeof(node));
    tmp->nodeId = id;
    tmp->next = next;
    tmp->edges = edge;
    tmp->weight = __INT_MAX__;
    tmp->parent = NULL;
    return tmp;
}

void createNodes(int size)
{
    if(graphNodes != NULL){
        deleteGraph_cmd();
    }
    pNode tmp = createNode(size - 1, NULL, NULL);
    for (int i = size - 2; i >= 0; i--)
    {
        pNode newNode = createNode(i, tmp, NULL);
        tmp = newNode;
    }
    graphNodes = tmp;
}


/**
 * add edges to node:
 *  1. first edge connected to node->edges
 *  2. all other edges is linked list from first edge
 * @param node
 */
void addEdges(pNode node)
{
    int num1;
    int num2;
    char ch;
    scanf("%c", &ch);
    if(ch == '\n'){
        return;
    }
    pEdge e = (pEdge)malloc(sizeof(edge));
    if (scanf("%d", &num1) == 1)
    {

        if (scanf("%d", &num2) == 1)
        {
            e->weight = num2;
            node->edges = e;
            e->dest = GetNode(num1);
            e->next = NULL;
        }
    }else{
        return;
    }

    scanf("%c", &ch);
    if(ch == '\n'){
        return;
    }
    while (scanf("%d", &num1) == 1)
    {
        if (scanf("%d", &num2) == 1)
        {
            pEdge tmp = (pEdge)malloc(sizeof(edge));
            tmp->next = NULL;
            e->next = tmp;
            tmp->weight = num2;
            tmp->dest = GetNode(num1);
            e = tmp;
        }
        scanf("%c", &ch);
        if(ch == '\n'){
            return;
        }
    }

}

void createGraph()
{
    int srcId;
    scanf("%d", &srcId);
    pNode node = GetNode(srcId);
    addEdges(node);
}


int contains(int nodeId)
{
    pNode tmp = graphNodes;
    while (tmp)
    {
        if (tmp->nodeId == nodeId)
        {
            return 1; //True
        }
        tmp = tmp->next;
    }
    return 0;
}

pNode getLast(){
    pNode tmp = graphNodes;
    while (tmp->next){
        tmp = tmp->next;
    }
    return tmp;
}

void freeEdgesOfNode(pNode p) {
    pEdge del_e = p->edges;
    if (del_e != NULL) {
        pEdge tmp = del_e->next;
        if (tmp == NULL) {
            free(del_e);
        } else {
            while (del_e->next != NULL) {
                pEdge ptmp = tmp;
                del_e->next = tmp->next;
                free(ptmp);
            }
            free(del_e);
        }
    }
}

void addNode()
{
    int srcId;
    scanf("%d", &srcId);
    if (contains(srcId) == 0) //NOT contains -> new nodeId
    {
        pNode last = getLast();
        pNode tmp = createNode(srcId, NULL, NULL);
        last->next = tmp;
        addEdges(tmp);
    } else{
        pNode curr = GetNode(srcId);
        freeEdgesOfNode(curr);
        curr->edges = NULL;
        addEdges(curr);
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



void deleteNode(int num) {
    pNode del = GetNode(num);
    pNode p = graphNodes;
    while (p) {
        pEdge e = p->edges;
        while (e) {

            if (e->dest == del) {
                p->edges = e->next;
                pEdge pe = e;
                free(pe);
                e = NULL;
            } else {
                pEdge tmp = e->next;
                if (tmp != NULL && tmp->dest == del) {
                    e->next = tmp->next;
                    free(tmp);
                } else {
                    e = tmp;
                }
            }
        }
        p = p->next;
    }
    pNode h = graphNodes;
    if (h != del) {
        while (h->next != del) {
            h = h->next;
        }
        h->next = del->next;
    }
    freeEdgesOfNode(del);
    free(del);

}

void deleteGraph_cmd()
{
    pNode tmp = graphNodes;
    int nodeId;
    while (tmp)
    {
        nodeId = tmp->nodeId;
        deleteNode(nodeId);
        tmp = tmp->next;
    }
    graphNodes = NULL;
}

void restartGraph(){
    pNode tmp = graphNodes;
    while (tmp){
        tmp->weight = __INT_MAX__;
        tmp->parent = NULL;
        tmp->visited = 0;
        tmp = tmp->next;
    }
}
void relax(pNode src, pNode dest, pEdge e)
{
    int wEdge = e->weight;
    int wSrc = src->weight;
    int wDest = dest->weight;
    if (wDest > wSrc + wEdge)
    {
        dest->weight = wSrc + wEdge;
        dest->parent = src;
    }
}

void dijkstra(int src, int dest){
    restartGraph();
    pNode srcNode = GetNode(src);
    srcNode->weight = 0;
    pqNode* pq = newNode(srcNode, srcNode->weight);
    pqNode** head = &pq;
    while (isEmpty(head) == 0){
        pqNode* curr = pop(head);
        if(curr->data->visited == 0){
            if(curr->data->nodeId == dest){
                return;
            }
            curr->data->visited = 1;
            pEdge e = curr->data->edges;
            while (e){
                relax(curr->data, e->dest, e);
                if(pq == NULL){
                    pq = newNode(e->dest, e->dest->weight);
                } else{
                    push(head, e->dest, e->dest->weight);
                }
                e = e->next;
            }
        }

    }
}

int shortestPath(int src, int dest){
    dijkstra(src,dest);
    pNode d =GetNode(dest);
    return d->weight;
}
void combinationUtil(int arr[], int n, int index,int data[], int i)
{

    if (index == n) {
        int sum=0;
        for (int j = 0; j < n-1; ++j) {
            sum+= shortestPath(data[j],data[j+1]);
        }
        if(sum<minPath){
            minPath=sum;
            return;
        }
    }

    if (i >= n)
        return;
    data[index] = arr[i];
    combinationUtil(arr, n,  index + 1, data, i + 1);
    combinationUtil(arr, n,  index, data, i + 1);
}

void TSP(int num){
    minPath = __INT_MAX__;
    int cities[num];
    int n;
    for(int i=0; i<num; i++){
       scanf("%d",&n);
       cities[i]=n;
    }

    int data[num];
    combinationUtil(cities, num, 0, data, 0);
    printf("TSP shortest path: %d\n",minPath);
}


