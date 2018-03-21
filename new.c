#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,j,k,n,count=0,a[20][20],ind[20],flag[20];
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		ind[i]=0;
		flag[i]=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ind[i]=ind[i]+a[j][i];
		}
	}
	printf("topological sort\n");
	while(count<n)
	{
		for(k=0;k<n;k++)
		{
			if((ind[k]==0) && (flag[k]==0))
			{
				printf("%d\n",(k+1));
				flag[k]==1;
			}
			for(i=0;i<n;i++)
			{
				if(a[i][k]==1)
					ind[k]--;
			}
		} 
		count++;
	}
}

