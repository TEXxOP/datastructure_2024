#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* start = NULL;

// Function to display the doubly linked list
void display() {
    if (start == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }

    struct Node* current = start;

    // Traverse the doubly linked list
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Function to insert a node at the beginning
void insertbeginning(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;

    if (start == NULL) {
        newnode->next = NULL;
        start = newnode;
    } else {
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}

// Function to insert a node at the end 
void insertend(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if (start == NULL) {
        newnode->prev = NULL;
        start = newnode;
    } else {
        struct Node* last = start;

        // Traverse to the last node
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = newnode;
        newnode->prev = last;
    }
}

// Function to delete a node from the beginning 
void deletebeginning() {
    if (start == NULL) {
        printf("Doubly linked list is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp = start;

    if (start->next != NULL) {
        start = start->next;
        start->prev = NULL;
    } else {
        start = NULL;
    }

    free(temp);
}

// Function to delete a node from the end 
void deleteend() {
    if (start == NULL) {
        printf("Doubly linked list is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* last = start;

    while (last->next != NULL) {
        last = last->next;
    }

    if (last->prev != NULL) {
        last->prev->next = NULL;
    } else {
        start = NULL;
    }

    free(last);
}

int main() {
    int choice, data;
    do {
        printf("\nMenu:\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Exit\n");

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
                deletebeginning();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    // Free memory 
    struct Node* current = start;
    struct Node* nextnode;

    // Traverse and free each node 
    while (current != NULL) {
        nextnode = current->next;
        free(current);
        current = nextnode;
    }

    return 0;
}
