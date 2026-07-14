#include <stdio.h>

int x[10], count = 0;

int place(int k, int i)
{
    int j;

    for(j = 1; j < k; j++)
    {
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }

    return 1;
}

void queen(int k, int n)
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                count++;

                printf("\nSolution %d:\n", count);

                for(j = 1; j <= n; j++)
                    printf("Queen %d -> Column %d\n", j, x[j]);
            }
            else
            {
                queen(k + 1, n);
            }
        }
    }
}

int main()
{
    int n = 8;

    queen(1, n);

    return 0;
}