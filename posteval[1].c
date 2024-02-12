#include <stdio.h>
#include <math.h> 
#include <ctype.h>
#define MAX_SIZE 100
int top = -1;
int stack[MAX_SIZE];
void push(int item) 
{
    if (top == MAX_SIZE - 1) 
    {
        printf("Stack overflow\n");
    } 
    else 
    {
        top++;
        stack[top] = item;
    }
}
int pop() 
{
    if (top == -1) 
    {
        printf("Stack underflow\n");
        return '\0';
    } 
    else 
    {
        int item = stack[top];
        top--;
        return item;
    }
}
void operator(char op) 
{
    int a = pop();
    int b = pop();
    switch(op) 
    {
        case '+':
            push(a+b);
            break;
        case '-':
            push(b-a);
            break;
        case '*':
            push(a*b);
            break;
        case '/':
            push(b/a);
            break;
        case '^':
            push(pow(b,a));
            break;
    }
}
int main() 
{
    char exp[MAX_SIZE];
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    for(int i=0; exp[i]!='\0'; i++) {
        if(isdigit(exp[i])) 
        {
            push(exp[i] - '0');
        }
        else 
        {
            operator(exp[i]);
        }
    }
    printf("Result: %d", pop());
    return 0;
}