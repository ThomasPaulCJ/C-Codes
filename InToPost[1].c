#include <stdio.h>
#define MAX_SIZE 100
int top = -1;
char item;
char infix[MAX_SIZE];
char postfix[MAX_SIZE];
char stack[MAX_SIZE];
void push(char item) 
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
char pop() 
{
	if (top == -1) 
	{
		printf("Stack underflow\n");
		return '\0';
	} 
	else 
	{
		char item = stack[top];
		top--;
		return item;
	}
}
int precedence(char i) 
{
	if (i == '^') 
	{
		return 3;
	} 
	else if (i == '/' || i == '*') 
	{
		return 2;
	} 
	else if (i == '+' || i == '-') 
	{
		return 1;
	} 
	else 
	{
		return 0;
	}
}
void ipostfix(char infix[]) 
{
	int i = 0, j = 0;
	push('#');
	while (infix[i] != '\0') 
	{
		char ch = infix[i++];
		if (ch == '(') 
		{
			push(ch);
		} 
		else if (ch == ')') 
		{
			while (stack[top] != '(') 
			{
				postfix[j++] = pop();
			}
			pop(); // pop the '(' from the stack
		} 
		else if (ch == '^' || ch == '+' || ch == '-' || ch == '*' || ch == '/') 
		{
			while (precedence(ch) <= precedence(stack[top])) 
			{
				postfix[j++] = pop();
			}
			push(ch);
		} 
		else 
		{
			postfix[j++] = ch;
		}
	}
	while (stack[top] != '#') 
	{
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
	printf("Postfix expression: %s\n", postfix);
}
int main() 
{
	printf("Enter the infix expression: ");
	scanf("%s", infix);
	ipostfix(infix);
	return 0;
}
