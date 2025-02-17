#include <stdio.h>
#define SIZE 9

int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i, j, tmp, x, min;
    int swap = 0;

    printf("\n Array Before Sort : ");
    for (x = 0; x < SIZE; x++)
    {
        printf("%d ", a[x]);
    }

    for (i = 0; i < SIZE - 1; i++)
    {
        min = i;
        for (j = i + 1; j < SIZE; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }

        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }

    printf("\n After Sort :");
    for (x = 0; x < SIZE; x++)
    {
        printf("%d ", a[x]);
    }
}