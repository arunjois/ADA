#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,j,a[10][10],n;
	printf("Enter the no. of verticfes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	warshall(a,n);

}
/*
 * Added a comment
 */
void warshall(int p[10][10],int n)
{
int i,j,k;
for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(p[i][j]==0 && p[k][j]==1 &&p[i][k]==1)
			{
				p[i][j]=1;
			}

		}




printf("Transitive Closure\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
	{
		printf("%d",p[i][j]);
	}
	printf("\n");
}			
}

