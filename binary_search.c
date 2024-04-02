#include <stdio.h>

// Function for binary search 
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevent potential overflow

        if (arr[mid] == target) {
            return mid; // Element found
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1;  // Element not found
}

int main() {
    int size, target;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int index = binarySearch(arr, 0, size - 1, target);

    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
