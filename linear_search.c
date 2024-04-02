#include <stdio.h>

// Function for linear search (remains the same)
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]; // Declare array after getting size from the user 

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
