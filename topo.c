#include<stdio.h>
#include<stdlib.h>
int a[20][20],rem[20],n,i,j,flag=0,ind;
int main()
{
	printf("Enter number of vertices:\n");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		rem[i]=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Topological order: is:\n");
	while(flag==0)
	{
		flag=1;
		for(i=0;i<n;i++)
		{
			if(rem[i]==0)
			{
				ind=0;
				for(j=0;j<n;j++)
				{
					if(!(rem[j]==1 || a[j][i]==0))
					{
						ind=1;
						break;
					}
				}
				if(ind==0)
				{
					rem[i]=1;
					printf("%d->",i+1);
					i++;
					flag=0;
					break;
				}
			}
		}
	}
	printf("\n");
	return 0;
}

