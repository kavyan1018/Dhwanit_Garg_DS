#include <stdio.h>

int main() {
    char arr[] = {'d', 'a', 'c', 'b', 'e'};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minIndex;
    char temp;

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {  // Compare characters directly
                minIndex = j;
            }
        }
        // Swap characters
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Print sorted letters
    printf("Sorted Letters: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }

    return 0;
}
