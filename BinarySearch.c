#include <stdio.h>

int bin_src(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return bin_src(arr, low, mid - 1, key);
    else
        return bin_src(arr, mid + 1, high, key);
}

int main()
{
    int n, i, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = bin_src(arr, 0, n - 1, key);

    if(result == -1)
        printf("Element not found.");
    else
        printf("Element found at index %d", result);

    return 0;
}