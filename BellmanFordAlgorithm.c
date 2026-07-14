#include <stdio.h>

#define MAX 10
#define INF 999

int main()
{
    int cost[MAX][MAX];
    int dist[MAX];
    int n, i, j, k, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    for(k = 1; k <= n - 1; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] != INF && dist[i] != INF)
                {
                    if(dist[i] + cost[i][j] < dist[j])
                    {
                        dist[j] = dist[i] + cost[i][j];
                    }
                }
            }
        }
    }

    printf("\nShortest distances from source vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}