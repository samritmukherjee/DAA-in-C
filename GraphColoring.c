#include <stdio.h>

int graph[10][10];
int color[10];
int n, m;

int isSafe(int vertex, int c)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(graph[vertex][i] == 1 && color[i] == c)
            return 0;
    }

    return 1;
}

void graphColoring(int vertex)
{
    int c, i;

    if(vertex == n)
    {
        printf("\nSolution:\n");

        for(i = 0; i < n; i++)
            printf("Vertex %d --> Color %d\n", i, color[i]);

        return;
    }

    for(c = 1; c <= m; c++)
    {
        if(isSafe(vertex, c))
        {
            color[vertex] = c;

            graphColoring(vertex + 1);

            color[vertex] = 0;
        }
    }
}

int main()
{
    int i, j;

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

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(0);

    return 0;
}
