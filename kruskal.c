#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);

void kruskal()
{
	printf("The edges of minimum spanning are \n");
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{

			printf(" \n %d edge (%d,%d)=%d\n",ne++,a,b,min);
			
			mincost+=min;
		}
		cost[a][b]=cost[b][a]=999;
	}

}


void main()
{
	struct timeval et,st;
	int tm=0;
	printf("Enter the no of vertices \n");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]==999;
		}
	}
	gettimeofday(&st,0);
	kruskal();
	gettimeofday(&et,0);
	tm=et.tv_usec-st.tv_usec;
	printf("\nTime taken is %d\n",tm);

}

int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}


int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

