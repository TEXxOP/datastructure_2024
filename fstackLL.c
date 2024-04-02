#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*top = NULL;
void push(int value)
{
    struct node*newnode = (struct node*)malloc(sizeof(struct node));//dynamic memory alloaction
    if (newnode == NULL){
        printf("overflow"); //stack is full
    }
    else{
        newnode->data = value;
        newnode->next = NULL;
        if(top == NULL){
            top = newnode;
        }
        else{
            newnode->next = top;
            top = newnode;
        }
    }

}
int main(){
    int value;
    printf("Enter the value you want to push onto the stack: ");
    scanf("%d", &value);
    push(value);
    printf("Value pushed onto the stack: %d\n", top->data);
    return 0;
    }