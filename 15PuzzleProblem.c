#include <stdio.h>

#define N 4

int calculateCost(int initial[N][N], int goal[N][N])
{
    int i, j, cost = 0;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(initial[i][j] != 0 && initial[i][j] != goal[i][j])
                cost++;
        }
    }

    return cost;
}

int main()
{
    int initial[N][N], goal[N][N];
    int i, j;

    printf("Enter Initial State:\n");
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            scanf("%d", &initial[i][j]);

    printf("Enter Goal State:\n");
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            scanf("%d", &goal[i][j]);

    printf("Cost (Misplaced Tiles) = %d", calculateCost(initial, goal));

    return 0;
}