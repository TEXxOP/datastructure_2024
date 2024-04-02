#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insert(int value) 
{
    if (front < 0) 
    {
        front = rear = 0;
        queue[rear] = value;
    } 
    else if (rear == MAX - 1) 
    {
        printf("Overflow\n");
    } 
    else 
    {
       rear = rear+1;
       queue[rear] = value;
    }
}

int delete() 
{
    int value;
    if (front < 0) 
    {
        printf("Underflow\n");
        return -1;
    } 
    else if (front == rear) 
    {
        value = queue[front];
        front = rear = -1;
    } 
    else 
    {
        value = queue[front];
       front = front+1;
    }
    return value;
}

void display() 
{
    if (front < 0) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insertion in the Queue\n");
        printf("2. Deletion from the Queue\n");
        printf("3. Display elements of the Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                value = delete();
                if (value != -1) {
                    printf("Deleted element: %d\n", value);
                }
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