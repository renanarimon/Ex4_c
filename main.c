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
        }
        if(ch == 'n') {
            createGraph();
        }
        if(ch == 'B') {
            addNode();
        }
        if(ch == 'D') {
            scanf("%d", &num);
            deleteNode(num);
        }
        if(ch == 'S') {
            scanf("%d", &num);
            scanf("%d", &num2);
            ans = shortestPath(num, num2);
            printf("Dijsktra shortest path: %d\n", ans);
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