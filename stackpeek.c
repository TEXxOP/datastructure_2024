#include <stdio.h>
#define MAX 15

int stack[MAX];
int top = -1;

// Function to peek 
int peek() {
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        return stack[top];
    }
}

int main() {
    
    int topElement = peek();
    if (topElement != -1) {
        printf("Top element of the stack: %d\n", topElement);
    }

    return 0;
}
