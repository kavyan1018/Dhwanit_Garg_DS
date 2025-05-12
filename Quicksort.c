#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// function to partition the array

int partition(int low, int high, int array[])
{
    int pivot = array[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++)       
    {
        if (array[j] <= pivot)         
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// quicksort recursive function
void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high, array);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

// function to print the array

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}


int main()
{
    int array[] = {3 , 7 , 12 , 9 , 11};

    int size = sizeof(array) / sizeof(array[0]);


    quicksort(array, 0, size - 1);

    printf("Sorted array: \n");
    printArray(array, size);

    return 0;
}