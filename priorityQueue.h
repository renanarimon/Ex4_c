//
// Created by PC on 12/29/2021.
//
#include "graph.h"
#ifndef EX4_PRIORITYQUEUE_H
#define EX4_PRIORITYQUEUE_H

typedef struct PQNode {

    pNode data;
    // Lower values indicate higher priority
    int priority;

    struct PQNode *next;

} pqNode;

pqNode* newNode(pNode d, int p);
pqNode* peek(pqNode** head);
void pop(pqNode** head);
void push(pqNode** head, pNode d, int p);
int isEmpty(pqNode** head);






#endif //EX4_PRIORITYQUEUE_H
