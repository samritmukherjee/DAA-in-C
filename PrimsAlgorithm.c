#include <stdio.h>

#define MAX 10
#define INF 999

int main()
{
    int cost[MAX][MAX], visited[MAX];
    int n, i, j;
    int min, a, b;
    int edgeCount = 0;
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edgeCount < n - 1)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d --> %d  Cost = %d\n", a, b, min);

        minCost += min;
        visited[b] = 1;
        edgeCount++;
    }

    printf("\nMinimum Cost = %d", minCost);

    return 0;
}