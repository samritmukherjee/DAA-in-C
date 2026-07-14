#include <stdio.h>

struct Job
{
    char id[5];
    int deadline;
    int profit;
};

int main()
{
    struct Job job[20], temp;
    int slot[20];
    int n, i, j, maxDeadline = 0;
    int totalProfit = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter Job ID, Deadline and Profit:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%s%d%d", job[i].id, &job[i].deadline, &job[i].profit);

        if(job[i].deadline > maxDeadline)
            maxDeadline = job[i].deadline;
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(job[i].profit < job[j].profit)
            {
                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    for(i = 1; i <= maxDeadline; i++)
        slot[i] = -1;

    for(i = 0; i < n; i++)
    {
        for(j = job[i].deadline; j >= 1; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = i;
                totalProfit += job[i].profit;
                break;
            }
        }
    }

    printf("\nSelected Jobs:\n");

    for(i = 1; i <= maxDeadline; i++)
    {
        if(slot[i] != -1)
            printf("%s ", job[slot[i]].id);
    }

    printf("\nTotal Profit = %d", totalProfit);

    return 0;
}