#include <stdio.h>

#define MAX_SIZE 100 //maximum size of the array(generic program)

int arr[MAX_SIZE]; //array 
int size = 0; //size of the array

//function to insert element at the beginning of the array
void insertAtBeginning(int value){
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    for (int i = size; i > 0; i--) {//making space for the elemnet
        arr[i] = arr[i - 1];//shifting each element to right
    }
    arr[0] = value;//storing value
    size++;
}

//function to insert at the end of the array
void insertAtEnd(int value){
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    arr[size] = value;
    size++;
}

//function to insert at a specific location in the array
void insertAtLocation(int value, int location){
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (location<0 || location>size){//valid index or not check
        printf("Invalid location.\n");
        return;
    }
    for (int i=size; i>location; i--){//making space for element
        arr[i] = arr[i - 1];
    }
    arr[location] = value;//storing the value 
    size++;
}

//function to delete the first element of the array
void deleteAtBeginning(){
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {//shifting elements to left
        arr[i] = arr[i + 1];
    }
    size--;
}

//function to delete the last element of the array
void deleteAtEnd(){
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    size--;
}

//function to delete an element at a specific location in the array
void deleteAtLocation(int location){
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    if (location < 0 || location >= size) {//valid index or not
        printf("Invalid location.\n");
        return;
    }
    for (int i = location; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

//function to search for an element in the array
int searchElement(int value){
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;//return the index of the found element
        }
    }
    return -1;//return -1 if the element is not found
}

//function to display the array
void displayArray() {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//function to initialize the array with a static array
void initializeArray(){
    int staticArr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        arr[i] = staticArr[i];
        size++;
    }
}

//function to input the array from the user
void inputArrayFromUser(){
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main(){
    int choice, value, location;
    int arrayChoice;

    printf("Choose how you want to initialize the array:\n");
    printf("1. Use a static array\n");
    printf("2. Input the array from the user\n");
    printf("3. Use an empty array\n");
    printf("Enter your choice: ");
    scanf("%d", &arrayChoice);

    switch (arrayChoice) {
        case 1:
            printf("Using a static array.\n");
            initializeArray();
            break;
        case 2:
            printf("Input the array from the user.\n");
            inputArrayFromUser();
            break;
        case 3:
            printf("Using an empty array.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return 1; // 
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a particular location\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at a particular location\n");
        printf("7. Search element\n");
        printf("8. Display array\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the location: ");
                scanf("%d", &location);
                insertAtLocation(value, location);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter the location: ");
                scanf("%d", &location);
                deleteAtLocation(location);
                break;
            case 7:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                int index = searchElement(value);
                if (index != -1) {
                    printf("Element found at index %d.\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 8:
                displayArray();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
