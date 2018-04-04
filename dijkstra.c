#include<stdio.h>

int cost[20][20],dist[20],n,v;

int dij()
{
	int count,i,min,u,flag[20],w;
	for(i=1;i<=n;i++)
	{
		flag[i]=0;
		dist[i]=cost[v][i];
	}
	count=2;
	while(count<n)
	{
		min=999;
		for(w=1;w<=n;w++)
		{
			if(dist[w]<min && !flag[w]){
				min=dist[w];
				u=w;
			}
		}
		flag[u]=1;
		count++;
		for(w=1;w<=n;w++)
		{
			if(dist[u]+cost[u][w]<dist[w] &&!flag[w])
			{
				dist[w]=dist[u]+cost[u][w];
			}
		}
	}
}

void main()
{
	int i, j;
	printf("Enterno. of vertices : ");
	scanf("%d",&n);
	printf("Enter adjacency matrix :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			{
				cost[i][j]=999;
			}
		}
	}
	printf("Enter source : ");
	scanf("%d",&v);
	dij();
	printf("\nShortest path is : \n");
	for(i=1;i<=n;i++)
	{
		if(i!=v)
		{
			printf("%d --> %d cost %d\n",v,i,dist[i]);
		}
	}
}



