#include<stdio.h>
#include<stdlib.h>
int a,b,i,u,v,j,n,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10],totalcost=0;
int main()
{
	printf("\n Enter the no of vertices:\n");
	scanf("%d",&n);
	printf("\n Enter the matrix\n",n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	visited[1]=1;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min)
					if(visited[i]!=0)
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
		if(visited[v]==0 || visited[v]!=1)
		{
			printf("\n Edge %d:(%d,%d) Cost-%d\n",ne++,a,b,min);
			totalcost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("Total Cost is %d\n",totalcost);
}
