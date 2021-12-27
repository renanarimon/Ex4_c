#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "algo.c"

int main()
{
    char ch;
    int num;
    char charN;
    char *str;
    int size = 0;
    while (scanf("%c", &ch) != EOF)
    {
        switch (ch)
        {
        case 'A':
            scanf("%d", &num);
            size = num * 3;
            scanf("%c", &charN);
            if (charN == '\n' || charN == '\0' || charN == '\t' || charN == ' ')
            {
                scanf("%c", &charN);
                while (charN == 'n')
                {
                    scanf("%c", &charN);
                    char *string;
                    scanf("%[^\n]", string);
                    char *token = strtok(string, " ");
                    while (token != NULL)
                    {
                        printf(" %s\n", token);
                        token = strtok(NULL, " ");
                    }
                    scanf("%c", &charN);
                    scanf("%c", &charN);
                }
            }

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