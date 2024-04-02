#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow\n");
        exit(1);
    } 
    else 
    {
        stack[++top] = ch;
    }
}

char pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
        exit(1);
    } 
    else 
    {
        return stack[top--];
    }
}

int main() {
    char exp[MAX];
    int flag = 1;

    printf("Enter an expression: ");
    scanf("%s", exp);

    for (int i = 0; i < strlen(exp); i++) 
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') 
        {
            push(exp[i]);
        } 
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') 
        {
            if (top == -1) 
            {
                flag = 0;
                break;
            } 
            else 
            {
                char temp = pop();
                if ((exp[i] == ')' && (temp == '{' || temp == '[')) ||
                    (exp[i] == '}' && (temp == '(' || temp == '[')) ||
                    (exp[i] == ']' && (temp == '(' || temp == '{'))) 
                {
                    flag = 0;
                    break;
                }
            }
        }
    }

    if (top > -1) 
    {
        flag = 0;
    }

    if (flag == 1) 
    {
        printf("Valid Expression\n");
    } 
    else 
    {
        printf("Invalid Expression\n");
    }

    return 0;
}