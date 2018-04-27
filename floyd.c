#include<stdio.h>
#include<stdlib.h>
int min(int,int);
void floyd(int p[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i==j)
					p[i][j]=0;
				else
					p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}

int main()
{
	int p[10][10],w,n,e,u,v,i,j;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			p[i][j]=999;
	}
	printf("Enter weight matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&p[i][j]);
		}
	}
	printf("\nMatrix of input data is\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",p[i][j]);
		printf("\n");
	}
	floyd(p,n);
	printf("Transitive closure\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",p[i][j]);
		printf("\n");	
	}

	printf("\nThe short paths are\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i!=j)
				printf("\n <%d,%d> = %d",i,j,p[i][j]);
		}
	printf("\n");
}
int min(int a,int b)
{
	if(a<b)
		return (a);
	else
		return(b);
}

