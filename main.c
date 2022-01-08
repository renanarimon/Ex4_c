#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "algo.h"

int main() {
    pNode head = createNode(-1,NULL);
    char ch;
    while (scanf(" %c",&ch) != EOF){
        while (1){
            if(ch=='A'){
                ch =createGraph(head);
                continue;
            }
            if(ch == 'B'){
                ch = insert_node_cmd(head);
                continue;
            }
            if(ch == 'D'){
                delete_node_cmd(head);
                break;
            }
            if(ch == 'S'){
                shortestPath(head);
                break;
            }
            if(ch == 'T') {
                TSP(head);
                break;
            }
            else{
                break;
            }
        }
    }
    pNode node1 = head->next;
    while (node1){
        pNode next = node1->next;
        removeNode(head,node1->id);
        node1 = next;
    }
    free(head);
    head=NULL;
    return 0;
}
