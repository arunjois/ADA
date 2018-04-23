#include<stdio.h>
#include<stdlib.h>
int count,w[10],d,x[10];
void subset(int cs,int k,int r)
{
	int i;
	x[k]=1;
	if(cs+w[k]==d)
	{
		printf("\n Subset Solution %d\n",++count);
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
				printf("%d\t",w[i]);
		}
		printf("\n");
	}
	else 
		if(cs+w[k]+w[k+1]<=d)
			subset(cs+w[k],k+1,r-w[k]);
	if((cs+r-w[k]>=d)&&(cs+w[k+1]<=d))
	{
		x[k]=0;
		subset(cs,k+1,r-w[k]);
	}
}
void main()
{
	int sum=0,i,n;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Enter the elements in Ascending order\n");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Enter the required sum:\n");
	scanf("%d",&d);
	for(i=0;i<n;i++)
		sum+=w[i];
	if(sum<d)
	{
		printf("No Solution possible\n");
		return;
	}
	printf("The solution is:\n");
	count=0;
	subset(0,0,sum);
}

