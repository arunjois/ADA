#include<stdio.h>
#include<stdlib.h>
int p[10],w[10],m,n;
knap()
{
	int k[n+1][m+1],x[n],i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
		{
			if(i == 0 || j == 0)
				k[i][j] = 0;
			else if(j >= w[i])
				k[i][j] = max(k[i-1][j],k[i-1][j-w[i]]+p[i]);
			else
				k[i][j] = k[i-1][j];
			
		}
	for(i=1;i<=n;i++)
		x[i] = 0;
	i = n;
	j = m;
	while(i != 0 && j != 0)
	{
		if(k[i][j] != k[i-1][j])
		{
			x[i] = 1;
			j = j-w[i];
		}
		i--;
	}
	printf("\nProfit matrix\n************************************************************\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(k[i][j] >= 0 && k[i][j] <10)
				printf("%d   ",k[i][j]);
			else
				printf("%d  ",k[i][j]);
		}
		printf("\n");
	}
	printf("************************************************************\nTotal profit is : %d\n",k[n][m]);
	printf("\nSelected objects\n*********************\n");
	for(i=0;i<=n;i++)
	{
		if(x[i] == 1 && x[i]>0)
			printf("%d : %d\n",i,x[i]);
	}
	printf("\n*********************\n");
}

max(int a, int b)
{
	return (a > b) ? a : b;
}

void main()
{
	int i,j;
	printf("Enter value for n : ");
	scanf("%d",&n);
	printf("Enter weights\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("Enter profits\n");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	printf("Enter max capacity : ");
	scanf("%d",&m);
	knap();
}

