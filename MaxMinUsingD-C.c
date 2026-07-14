#include <stdio.h>

int max, min;

void maxMin(int arr[], int low, int high)
{
    int mid;
    int max1, min1;

    if(low == high)
    {
        max = min = arr[low];
    }
    else if(low == high - 1)
    {
        if(arr[low] > arr[high])
        {
            max = arr[low];
            min = arr[high];
        }
        else
        {
            max = arr[high];
            min = arr[low];
        }
    }
    else
    {
        mid = (low + high) / 2;

        maxMin(arr, low, mid);
        max1 = max;
        min1 = min;

        maxMin(arr, mid + 1, high);

        if(max1 > max)
            max = max1;

        if(min1 < min)
            min = min1;
    }
}

int main()
{
    int n, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    maxMin(arr, 0, n - 1);

    printf("Maximum Element = %d\n", max);
    printf("Minimum Element = %d\n", min);

    return 0;
}