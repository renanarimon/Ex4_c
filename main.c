#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"
// #include "graph.h"

int main()
{
    char ch;
    int num;
    while (scanf("%c", &ch) == 1 && ch != '~')
    {
        switch (ch)
        {
        case 'A':
            scanf("%d", &num);
            createNodes(num);
            // printGraph_cmd();

            break;
        case 'n':
            printf("n");
            createGraph();
            printGraph_cmd();
            break;
        case 'B':
            break;

        case 'D':
            break;

        case 'S':
            break;

        case 'T':
            break;

        default:
            break;
        }
    }

    return 0;
}