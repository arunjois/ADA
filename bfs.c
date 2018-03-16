#include<stdio.h>
int a[20][20],visited[20],q[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
	for(i=1;i<=n;i++)
	{
		if(a[v][i] && !visited[i])
		{
			q[++r]=i;
		}
	}
	if(f<=r)
	{
		visited[q[f]]=1;
		bfs(q[f++]);
	}

}
void main()
{
	int v;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
		q[i]=0;
	}
	printf("Enter the adjacency matrix elements\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the vertex to begin from\n");
	scanf("%d",&v);
	bfs(v);
	printf("Reachable nodes are\n");
	for(i=1;i<=n;i++)
		if(visited[i])
		{
			printf("reachable node:- %d\n",i);
		}
		else
		{
			printf("not reachable node:- %d\n",i);
		}
}


