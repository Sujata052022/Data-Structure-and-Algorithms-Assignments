#include<stdio.h>
int n,i,j,ne=1,u,v,a,b;
int cost[9][9],min,parent[9],mincost=0;
int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}

int uni(int i, int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
int main()
{
	printf("\n Kruskal's Algorithm::");
	printf("\n Enter the number of vertices::");
	scanf("%d",&n);
	
	printf("\n Enter the adjacency matrix:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			    cost[i][j]=999;
		}
	}
	printf("\n The edges of minimum cost spannin tree are\n");
	while(ne<n)
	{   min=999;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					u=a=i;
					v=b=j;
				}
			}
			
		}
			
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d)=%d\n",ne++,a,b,min);
			mincost+=min;
		}
	cost[a][b]=cost[b][a]=999;
	}
	if(ne==n)
		printf("\n Mininmum cost=%d\n",mincost);
	else
		printf("Minimum spanning tree does not exist");
	return 0;
}