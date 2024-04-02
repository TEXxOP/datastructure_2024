#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insert(int value) 
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) 
    {
        printf("No Empty Space\n");
        return;
    }
    if (front == NULL) 
    {
        front = newnode;
        newnode->data = value;
        newnode->next = NULL;
        rear = newnode;
    } 
    else 
    {
        rear->next = newnode;
        newnode->data = value;
        newnode->next = NULL;
        rear = newnode;
    }
}

void delete() 
{
    if (front == NULL) 
    {
        printf("Underflow\n");
        return;
    }
    struct Node* temp = front;
    if (front == rear) 
    {
        front = rear = NULL;
    } 
    else 
    {
        front = front->next;
    }
    free(temp);
}

void display() 
{
    if (front == NULL) 
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insertion in the Queue\n");
        printf("2. Deletion from the Queue\n");
        printf("3. Displaying the Elements of the Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the Program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}