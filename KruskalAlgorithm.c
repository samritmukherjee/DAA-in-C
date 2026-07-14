#include <stdio.h>

#define MAX 10
#define INF 999

int parent[MAX];

int find(int i)
{
    while(parent[i])
        i = parent[i];

    return i;
}

void unionSet(int i, int j)
{
    parent[j] = i;
}

int main()
{
    int cost[MAX][MAX];
    int n, i, j;
    int min, a, b;
    int u, v;
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

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edgeCount < n - 1)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(u != v)
        {
            printf("%d --> %d  Cost = %d\n", a, b, min);

            minCost += min;

            unionSet(u, v);

            edgeCount++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum Cost = %d", minCost);

    return 0;
}