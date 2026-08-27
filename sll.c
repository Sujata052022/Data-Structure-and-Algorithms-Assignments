#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node* init()
{
	node *head=NULL;
	printf("head is initialized. Address of head is %p\n and value of head is %d\n",head,(void*)head);
	return head;
}
node* createnode(int value)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->link=NULL;
	printf("\nNewnode is created at address %d",newnode);
	return newnode;
}
void insert(int item,node** start)
{
	node* newnode=createnode(item);
	if(*start==NULL)
	{
		*start=newnode;
		printf("\n%d is first node at address %p and the address of start is %p\n",newnode->data,newnode,start);
	}
	else
	{
		node* temp=*start;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;
		printf("\n%d is first node at address %p and the address of start is %p\n",newnode->data,(void*)newnode,(void*)start);
	}
}
int main()
{
	printf("\n Calling init()\n");
	node* start=init();
	insert(10,&start);
	insert(20,&start);
	return 0;
}