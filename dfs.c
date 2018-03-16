#include<stdio.h>
#include<stdlib.h>
int g[100][100],visited[100],n;
void dfs(int);
int main()
{
	int i,j;
	printf("\n Enter value of n\n");
	scanf("%d",&n);
	printf("\n Enter the Matrix\n");
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	}
	dfs(0);
}
void dfs(int i)
{
	int count=0,j;
	for(j=0;j<n;j++)
		printf("%d \t",g[i][j]);
	if(!visited[j] && g[i][j]==1)
		dfs(i);
	printf("\n");
}

