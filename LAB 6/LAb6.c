#include <stdio.h>

int main()
{
    int nb, np, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[20], b1[20], b2[20], b3[20];

    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < nb; i++)
    {
        scanf("%d", &block[i]);
        b1[i] = b2[i] = b3[i] = block[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[20];

    printf("Enter sizes of processes:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &process[i]);

    /* FIRST FIT */
    printf("\n----- First Fit -----\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < np; i++)
    {
        int allocated = 0;

        for(j = 0; j < nb; j++)
        {
            if(b1[j] >= process[i])
            {
                printf("%d\t\t%d\t\t%d\n", i+1, process[i], j+1);
                b1[j] -= process[i];
                allocated = 1;
                break;
            }
        }

        if(!allocated)
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, process[i]);
    }

    /* BEST FIT */
    printf("\n----- Best Fit -----\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < np; i++)
    {
        int best = -1;

        for(j = 0; j < nb; j++)
        {
            if(b2[j] >= process[i])
            {
                if(best == -1 || b2[j] < b2[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            printf("%d\t\t%d\t\t%d\n", i+1, process[i], best+1);
            b2[best] -= process[i];
        }
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, process[i]);
    }

    /* WORST FIT */
    printf("\n----- Worst Fit -----\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < np; i++)
    {
        int worst = -1;

        for(j = 0; j < nb; j++)
        {
            if(b3[j] >= process[i])
            {
                if(worst == -1 || b3[j] > b3[worst])
                    worst = j;
            }
        }

        if(worst != -1)
        {
            printf("%d\t\t%d\t\t%d\n", i+1, process[i], worst+1);
            b3[worst] -= process[i];
        }
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, process[i]);
    }

    return 0;
}