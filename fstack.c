#include<stdio.h>
#define MAX 15
int stack[MAX] ,data, top = -1;
void push(int data){   //function to push data onto the stack
    if(top == MAX - 1){
        printf("Overflow\n"); //stack is full
    }
    else if(top == -1){
        top++;
        stack[top] = data;  //stack is empty
    }
    else{
        top++;
        stack[top] = data;  //general
    }   
}
int main(){
    int data, i;
    for(i=0; i<MAX; i++){
    printf("Enter the data you want to push: ");
    scanf("%d", &data);//taking data from the user
    push(data);//calling the function
    printf("The data pushed onto the stack: %d\n", stack[top]);
    }
return 0;
}