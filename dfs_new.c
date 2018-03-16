#include<stdio.h>
int a[20][20],reach[20],n,v[20];
void dfs(int v)
{
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[v][i]&&!reach[i])
		{
			printf("\n%d -> %d",v,i);
			dfs(i);
		}
	}
}
void main()
{
	int i,j,count=0,from;
	printf("enter the no of vertix:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		reach[i]=0;
		for(j=1;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
	printf("enter the matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the intial point of the graph\n");
	scanf("%d",&from);
	dfs(from);
	for(i=1;i<=n;i++)
	{
		if(reach[i])
		{
			count++;
		}
	}
	if(count==n)
		printf("\n graph is connected\n");
	else
		printf("\n graph is not connected\n");
}


