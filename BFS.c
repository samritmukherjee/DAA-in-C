#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void bfs(int start, int n)
{
    int i;

    visited[start] = 1;
    queue[++rear] = start;

    while(front != rear)
    {
        int vertex = queue[++front];

        printf("%d ", vertex);

        for(i = 0; i < n; i++)
        {
            if(graph[vertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");

    bfs(start, n);

    return 0;
}