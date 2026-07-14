#include <stdio.h>

#define MAX 10
#define INF 999

int main()
{
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    int n, i, j, source;
    int min, next;

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

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    for(i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                next = j;
            }
        }

        visited[next] = 1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && (min + cost[next][j] < dist[j]))
            {
                dist[j] = min + cost[next][j];
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