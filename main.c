#include <stdio.h>
#include <string.h>
#include "algo.h"
#include "graph.h"

int main()
{
    char ch;
    int num;
    int num2;
    int ans = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'A') {
            scanf("%d", &num);
            createNodes(num);
            printGraph_cmd();
            printf("end A\n");

        }
        if(ch == 'n') {
            createGraph();
            printGraph_cmd();
            printf("end n\n");
        }
        if(ch == 'B') {
            addNode();
            printGraph_cmd();
            printf("end B\n");
        }
        if(ch == 'D') {
            scanf("%d", &num);
            deleteNode(num);
            printGraph_cmd();
        }
        if(ch == 'S') {
            printf("in s\n");
            scanf("%d", &num);
            scanf("%d", &num2);
            ans = shortestPath(num, num2);
            printf("Dijsktra shortest path:%d", ans);
        }
        if(ch == 'T') {
            scanf("%d", &num);
            TSP(num);

        }
        if(ch == '\n') {
            deleteGraph_cmd();
            break;
        }

    }

    return 0;
}