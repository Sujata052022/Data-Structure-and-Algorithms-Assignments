#include "s.h"
#include<stdio.h>
void readmatrix( sparse s1[],int m)
{
	//int m;
	int i;
	printf("\n Enter the dimensions");
	scanf("%d%d",&s1[0].row,&s1[0].col);
	s1[0].value=m;
	printf("Enter row, col and value for %d elements",m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&s1[i].row,&s1[i].col,&s1[i].value);
	}
}
void printmatrix( sparse s1[],int m)
{
	int i;
	printf("Sparse Matrix::\n");
	printf("Row   Col   Value::\n");
	for(i=0;i<=m;i++)
	{
		printf("%d\t%d\t%d\n",s1[i].row,s1[i].col,s1[i].value);
	}
}
int main()
{
	int m;
	printf("\n Enter the number of nonzero elements");
	scanf("%d",&m);
	
	 sparse a[m];
	readmatrix(a,m);
	printmatrix(a,m);
	return 0;
}