#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
typedef struct
{
	int key;
}element;
element stack[MAXSIZE];
int top=-1;

void push(int value)
{
	if(top==MAXSIZE-1)
	{
		printf("\nStack Full");
		return;
	}
	else
	{
		top++;
		stack[top].key=value;
		printf("\n%d is pushed into stack",stack[top].key);
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\n Stack is empty");
		return;
	}
	else
	{ int value;
		value=stack[top].key;
		printf("\n %d is popped from stack",value);
		top--;
		
	}
}
void display()
{
	if(top==-1)
	{
		printf("\n Stack is empty");
	}
	for (int i=0;i<=top;i++)
	{
		printf("\t %d",stack[i]);
	}
}

int main()
{
	int ch,value;
	do
	{
		printf("\n Menu:");
		printf("\n1. Push \n2. Pop  \n3. Display  \n4. Exit");
		printf("\nEnter your choice::");
		
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter the value to insert into stack");
				scanf("%d",&value);
				push(value);
				break;
			case 2: 
				pop();
				break;
			case 3: 
				display();
				break;
			case 4:
				exit(0);
				break;
			default: printf("Enter correct choice");
		}
	}while(ch!=4);
	return 0;
}