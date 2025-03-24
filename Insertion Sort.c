#include<stdio.h>

// Function to sort the array using insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j; // Declare variables i, key, and j

    // Loop through the array starting from the second element
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // Set key as the current element
        j = i - 1;    // Set j to the index just before i

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) { // Check if elements are greater than key
            arr[j + 1] = arr[j];         // Move the larger element one position ahead
            j = j - 1;                   // Move the index j to the left
        }

        arr[j + 1] = key; // Place the key at the correct position in the sorted part
    }
}

// A utility function to print the array
void printarray(int arr[], int n)
{
    int i;

    // Loop through the array and print each element
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); // Print each element
        printf("\n");           // Print a newline after each element
    }
}

// Driver method to test insertion sort
int main()
{
    int arr[] = {12, 11, 13, 5, 6}; // Define and initialize the array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Call the insertionSort function to sort the array
    insertionSort(arr, n);

    // Print the sorted array
    printf("Sorted array: \n");
    printarray(arr, n); // Print the sorted array

    return 0; // End of the program
}
