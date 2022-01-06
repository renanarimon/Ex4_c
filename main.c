#include <stdio.h>
#include <string.h>
#include "algo.h"
#include "graph.h"
#define INF 1000000

int main()
{
    char ch;
    int num;
    int num2;
    int ans = 0;


    pNode head = createNode(-1, NULL, NULL);
//    head->nodeId = -1;
//    head->next = NULL;
//    head->edges = NULL;
//    head->weight = INF;
//    head->parent = NULL;

    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'A') {
            scanf("%d", &num);
            createNodes(num, head);
        }
        if(ch == 'n') {
            createGraph(head);
        }
        if(ch == 'B') {
            addNode(head);
        }
        if(ch == 'D') {
            scanf("%d", &num);
            deleteNode(num,head);
        }
        if(ch == 'S') {
            scanf("%d", &num);
            scanf("%d", &num2);
            ans = shortestPath(num, num2,head);
            printf("Dijsktra shortest path: %d \n", ans);
        }
        if(ch == 'T') {
            scanf("%d", &num);
            TSP(num ,head);
        }
        if(ch == '\n') {
            deleteGraph_cmd(head);
            break;
        }

    }
    free(head);

    return 0;
}