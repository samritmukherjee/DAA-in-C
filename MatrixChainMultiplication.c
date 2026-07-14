#include <stdio.h>

int mcm(int p[], int i, int j)
{
    if(i == j)
        return 0;

    int k;
    int min = 999999;
    int count;

    for(k = i; k < j; k++)
    {
        count = mcm(p, i, k)
              + mcm(p, k + 1, j)
              + p[i - 1] * p[k] * p[j];

        if(count < min)
            min = count;
    }

    return min;
}

int main()
{
    int n, i;
    int p[20];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array:\n");

    for(i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Minimum number of multiplications = %d", mcm(p, 1, n));

    return 0;
}