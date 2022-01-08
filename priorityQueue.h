#ifndef EX4_PRIORITYQUEUE_H
#define EX4_PRIORITYQUEUE_H

typedef struct Queue {
    pNode pri_que[1000];
    int front;
    int rear;
}priorityQueue, *pQueue;

pQueue createPriortyQueue();
void push(pQueue queue, pNode n);
pNode pop(pQueue queue);
void check(pQueue queue,pNode n);
void displayQueue(pQueue queue);
int isEmpty(pQueue queue);


#endif //EX4_PRIORITYQUEUE_H
