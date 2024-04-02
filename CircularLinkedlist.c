#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;

// Function to display the elements 
void display() {
    struct Node* ptr = start; // pointer to traverse the linked list

    if (start == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    do {
        printf("%d -> ", ptr->data); // print the data of the current node
        ptr = ptr->next; // move to the next node
    } while (ptr != start); // loop until the entire circular list is traversed
    printf("(head)\n"); // print (head) to indicate the start of the list
}

// Function to insert a new node at the beginning 
void insertbeginning(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // allocate memory for the new node
    temp->data = data; // assign data to the new node

    if (start == NULL) { // if the list is empty
        start = temp; // set the start pointer to the new node
        temp->next = start; // make the new node point to itself to create a circular list
    } else {
        struct Node* last = start;
        while (last->next != start) { // traverse to the last node
            last = last->next;
        }
        temp->next = start; // point the new node to the start
        start = temp; // update the start pointer to the new node
        last->next = start; // make the last node point to the new start
    }
}

// Function to insert a new node at the end 
void insertend(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // allocate memory for the new node
    temp->data = data; // assign data to the new node

    if (start == NULL) { // if the list is empty
        start = temp; // set the start pointer to the new node
        temp->next = start; // make the new node point to itself to create a circular list
    } else {
        struct Node* last = start;
        while (last->next != start) { // traverse to the last node
            last = last->next;
        }
        last->next = temp; // make the last node point to the new node
        temp->next = start; // make the new node point to the start
    }
}

// Function to insert a new node at a specific position 
void insertatlocation(int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be a positive integer.\n");
        return;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // allocate memory for the new node
    temp->data = data; // assign data to the new node

    if (position == 1) {
        insertbeginning(data);
        free(temp); // free the memory allocated for the new node (since it is already inserted at the beginning)
        return;
    }

    struct Node* ptr = start; // pointer to traverse the list
    int count = 1;

    while (count < position - 1 && ptr->next != start) {
        ptr = ptr->next; // move to the next node
        count++;
    }

    if (ptr->next == start && count < position - 1) {
        printf("Invalid position. Position exceeds the size of the list.\n");
        free(temp); // free the memory allocated for the new node
        return;
    }

    temp->next = ptr->next; // point the new node to the next node of ptr
    ptr->next = temp; // make ptr point to the new node
}

// Function to delete the first node 
void deletebeginning() {
    if (start == NULL) { // if the list is empty
        printf("Circular Linked List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp = start; // pointer to the first node

    if (start->next == start) { // if there is only one node in the list
        free(temp); // free the memory allocated for the node
        start = NULL; // set the start pointer to NULL
    } else {
        struct Node* last = start;
        while (last->next != start) { // traverse to the last node
            last = last->next;
        }
        start = start->next; // update the start pointer to the next node
        free(temp); // free the memory allocated for the first node
        last->next = start; // make the last node point to the new start
    }
}

// Function to delete the last node 
void deleteend() {
    if (start == NULL) { // if the list is empty
        printf("Circular Linked List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp;
    struct Node* last = start;

    while (last->next != start) { // traverse to the second last node
        temp = last;
        last = last->next;
    }

    if (last == start) { // if there is only one node in the list
        free(start); // free the memory allocated for the node
        start = NULL; // set the start pointer to NULL
    } else {
        temp->next = start; // make the second last node the new last node
        free(last); // free the memory allocated for the last node
    }
}

void deleteatlocation(int position) {
    if (position < 1) { // check if the position is valid
        printf("Invalid position. Position should be a positive integer.\n");
        return;
    }

    if (start == NULL) { // if the list is empty
        printf("Circular Linked List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp;
    struct Node* ptr = start; // pointer to traverse the list
    int count = 1;

    while (count < position && ptr->next != start) {
        temp = ptr; // save the previous node
        ptr = ptr->next; // move to the next node
        count++;
    }

    if (ptr == start && count < position) { 
        printf("Invalid position. Position exceeds the size of the list.\n");
        return;
    }

    temp->next = ptr->next; // bypass the node to be deleted
    free(ptr); // free the memory allocated for the node
}

int main() {
    int choice, data, position;
    do {
        printf("\nMenu:\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Location\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Specific Location\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) { 
            printf("Invalid input. Please enter a valid integer.\n");
        
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertbeginning(data);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertend(data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertatlocation(data, position);
                break;
            case 5:
                deletebeginning();
                break;
            case 6:
                deleteend();
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteatlocation(position);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    // Free memory
    struct Node* current = start;
    struct Node* next;

    if (start != NULL) { // free memory only if the list is not empty
        do {
            next = current->next;
            free(current);
            current = next;
        } while (current != start);
    }

    return 0;
}