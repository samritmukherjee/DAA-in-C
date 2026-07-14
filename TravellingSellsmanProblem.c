#include <stdio.h>

#define MAX 10
#define INF 99999

int graph[MAX][MAX];
int visited[MAX];
int n;
int minCost = INF;

void tsp(int currentCity, int count, int cost)
{
    int i;

    if(count == n && graph[currentCity][0] != 0)
    {
        cost = cost + graph[currentCity][0];

        if(cost < minCost)
            minCost = cost;

        return;
    }

    for(i = 0; i < n; i++)
    {
        if(!visited[i] && graph[currentCity][i] != 0)
        {
            visited[i] = 1;

            tsp(i, count + 1, cost + graph[currentCity][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    visited[0] = 1;

    tsp(0, 1, 0);

    printf("Minimum Travelling Cost = %d", minCost);

    return 0;
}