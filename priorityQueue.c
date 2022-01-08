/*
 * C Program to Implement Priority Queue to Add and Delete Elements
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"
#include "PriorityQueue.h"
#define MAX 1000


void push(pQueue queue, pNode n);
pNode pop(pQueue queue);
void check(pQueue queue, pNode);
void displayQueue(pQueue queue);


///* Function to create an empty priority queue */
pQueue createPriortyQueue(){
    priorityQueue *queue= (pQueue)malloc(sizeof(priorityQueue));
    queue->rear=-1;
    queue->front =-1;
    return queue;
}

/* Function to insert value into priority queue */
void push(pQueue queue, pNode n){
    if (queue->rear >= MAX - 1)
    {
        return;
    }
    if ((queue->front == -1) && (queue->rear == -1))
    {
        queue->front++;
        queue->rear++;
        queue->pri_que[queue->rear] = n;
        return;
    }
    else
        check(queue,n);
    queue->rear++;
}

/* Function to check priority and place element */
void check(pQueue queue,pNode n){
    int i,j;
    for (i = 0; i <= queue->rear; i++){
        if (n->weight < queue->pri_que[i]-> weight){
            for (j = queue->rear + 1; j > i; j--){
                queue->pri_que[j] = queue->pri_que[j - 1];
            }
            queue->pri_que[i] = n;
            return;
        }
    }
    queue->pri_que[i] = n;
}

/* Function to delete an element from queue */
pNode pop(pQueue queue){
    int i;
    pNode temp;
    int flag=0;
    int min_weigh=2147483647;
    int indexOfmin=-1;
    if (queue->rear==0){ //there is only one node in the queue
        temp=queue->pri_que[queue->rear];
        queue->pri_que[queue->rear]=NULL;
        queue->rear--;
        return temp;
    }
    if ((queue->front==-1) && (queue->rear==-1)){
        return NULL;
    }
    for (i = 0; i <= queue->rear ; i++) {
        if (min_weigh > queue->pri_que[i]->weight){
            indexOfmin=i;
            min_weigh=queue-> pri_que[i]->weight;
            temp=queue->pri_que[i];
            flag=1;
        }
    }
   if(flag==0){// min weight was not change in the previous iter
       temp=queue->pri_que[queue->rear];
       queue->pri_que[queue->rear]=NULL;
       queue->rear--;
       return temp;
   }
    for (int j = indexOfmin; j <queue->rear ; j++) {
        queue->pri_que[j]=queue->pri_que[j+1];
    }
    queue->pri_que[queue->rear]=NULL;
    queue->rear--;
    return temp;
}

int isEmpty(pQueue queue){
    if (queue->rear==-1){
        return 1;
    }
    return 0;
}