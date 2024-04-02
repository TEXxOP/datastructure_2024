#include<stdio.h>
#define MAX 15
int stack[MAX] ,data, top = -1,i;
int main(){
    for(i=0; i<MAX; i++){
    printf("Enter the data you want to push: ");
    scanf("%d", &data);//taking data from the user
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
    printf("The data pushed onto the stack: %d\n", stack[top]);
    }
return 0;
}    
