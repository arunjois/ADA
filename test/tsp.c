#include<stdio.h>
#include<stdlib.h>
int c=0,cost=999,graph[20][20];
int a[20];
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void copy_array(int *a,int n)
{
	int sum=0,i;
	for(i=0;i<=n;i++)
		sum=sum+graph[a[i%n]][a[i+1]%n];
	if(cost>sum)
		cost=sum;
}
void permutate(int *a,int i,int n)
{
	int j;
	if(i==n)
		copy_array(a,n);
	else
	{
		for(j=1;j<=n;j++)
		{
			swap((a+i),(a+j));
			permutate(a,i+1,n);
			swap(a+i,a+j);
		}
	}
}
void main()
{
	int i,j,n;
	printf("Enter the total no. of vertices:");
	scanf("%d",&n);
	printf("\n Enter Matrix of %d vertices\n",n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&graph[i][j]);
	for(j=0;j<n;j++)
		a[i]=1;
	permutate(a,0,n-1);
	printf("Minimum Cost:%d\n",cost);
}
