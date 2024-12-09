#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int array[SIZE] = {0}; // Initialize array to 0

int main() {
    int choice;
    int location, data;
    int i, left, mid, right, search, found;

    while (1) {
        printf("\nArray Operations Menu:");
        printf("\n1. Add Element");
        printf("\n2. Display Array");
        printf("\n3. Delete Element");
        printf("\n4. Exit");
        printf("\n5. Linear Search");
        printf("\n6. Binary Search");
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: // Add element
                printf("\nEnter Location (1-%d) and Data: ", SIZE);
                if (scanf("%d%d", &location, &data) != 2) {
                    printf("\nInvalid input! Please enter valid numbers.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (location < 1 || location > SIZE) {
                    printf("\nInvalid Location! Enter between 1 and %d.\n", SIZE);
                    break;
                }

                // Check if array is full at the desired location
                if (array[SIZE-1] != 0) {
                    printf("\nArray is full! Cannot add more elements.\n");
                    break;
                }

                // Shift elements to right
                for (i = SIZE - 1; i > location - 1; i--) {
                    array[i] = array[i - 1];
                }
                array[location - 1] = data;
                printf("\nElement added successfully!\n");
                break;

            case 2: // Display elements
                printf("\nElements in the Array:\n");
                for (i = 0; i < SIZE; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;

            case 3: // Delete element
                printf("\nEnter Location to Delete (1-%d): ", SIZE);
                if (scanf("%d", &location) != 1) {
                    printf("\nInvalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (location < 1 || location > SIZE) {
                    printf("\nInvalid Location! Enter between 1 and %d.\n", SIZE);
                    break;
                }

                // Check if location is empty
                if (array[location - 1] == 0) {
                    printf("\nLocation is already empty!\n");
                    break;
                }

                // Shift elements to left
                for (i = location - 1; i < SIZE - 1; i++) {
                    array[i] = array[i + 1];
                }
                array[SIZE - 1] = 0;
                printf("\nElement deleted successfully!\n");
                break;

            case 4: // Exit program
                printf("\nExiting program. Goodbye!\n");
                return 0;

            case 5: // Linear Search
                printf("\nEnter Element to Search: ");
                if (scanf("%d", &search) != 1) {
                    printf("\nInvalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (i = 0; i < SIZE; i++) {
                    if (array[i] == search) {
                        printf("\nElement %d found at position %d.\n", search, i + 1);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nElement %d not found.\n", search);
                }
                break;

            case 6: // Binary Search
                printf("\nEnter Element to Search: ");
                if (scanf("%d", &search) != 1) {
                    printf("\nInvalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    break;
                }

                // Check if array is sorted
                for (i = 1; i < SIZE; i++) {
                    if (array[i] < array[i-1] && array[i] != 0) {
                        printf("\nArray must be sorted for binary search!\n");
                        break;
                    }
                }
                if (i < SIZE) break;

                left = 0;
                right = SIZE - 1;
                found = 0;

                while (left <= right) {
                    mid = (left + right) / 2;
                    if (array[mid] == search) {
                        printf("\nElement %d found at position %d.\n", search, mid + 1);
                        found = 1;
                        break;
                    } else if (array[mid] == 0 || search > array[mid]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) {
                    printf("\nElement %d not found.\n", search);
                }
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n");
                break;
        }
    }
    return 0;
}