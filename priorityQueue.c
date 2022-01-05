//
// Created by PC on 12/29/2021.

#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"


// Function to Create A New Node
pqNode* newNode(pNode d, int p)
{
    pqNode* temp = (pqNode*)malloc(sizeof(pqNode));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Return the value at head
pqNode* peek(pqNode** head)
{
    return *head;
}

// Removes the element with the
// highest priority form the list
void pop(pqNode** head)
{
    pqNode* temp = *head;
    *head = (*head)->next;
    free(temp);

}

// Function to push according to priority
void push(pqNode** head, pNode d, int p)
{
    pqNode* start = (*head);

    // Create new Node
    pqNode* temp = newNode(d, p);

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->priority > p) {

        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {

        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
               start->next->priority < p) {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to check is list is empty
int isEmpty(pqNode** head)
{
    return (*head) == NULL;
}
//

