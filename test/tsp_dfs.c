#include<stdio.h>
#define INFINITY 9999
#define MAX 10
int a[10][10], t[10][2], k=0, apxcost=0;
void dfs(int cov[], int s, int n)
{
	int i;
	cov[s]=1;
	for(i=0; i<=n; i++)
	{
		if(!cov[i] && a[s][i])
		{
			t[k][0]=s;
			t[k][1]=i;
			k++;
			dfs(cov,i,n);
		}
	}
}
void approximate(int cov[], int s, int n)
{
	int i, sum=0;
	dfs(cov, s, n);
	if (a[t[k-1][1]][s]!=0)
	{
		t[k][0]=t[k-1][1];
		t[k][1]=s;
		k++;
	}
	if(t[k-1][1]==s)
	{
		printf("\nHamiltonian Circuit\n Vertices are:\n");
		for(i=0; i<k; i++)
		{
			printf("%d -->", t[i][0]);
			apxcost+=a[t[i][0]][t[i][1]];
		}
	}
	if(apxcost>0)
		printf("\n Approximatation Cost is %d \n", apxcost);
}
int tsp_dp(int c[][MAX], int tour[], int start, int n)
{
	int i, j, k;
	int temp[MAX], mintour[MAX], mincost=0, ccost;
	if(start==n-2)
		return c[tour[n-2]][tour[n-1]]+c[tour[n-1]][0];
	mincost=INFINITY;
	for(i=start+1; i<n; i++)
	{
		//
		printf("\nStart : %d", start);
		for(j=0; j<n; j++)
			temp[j]=tour[j];
		temp[start+1]=tour[i];
		temp[i]=tour[start+1];
		if(c[tour[start]][tour[i]]+(ccost=tsp_dp(c, temp, start+1, n))<mincost)
		{
			mincost=c[tour[start]][tour[i]]+ccost;
			for(k=0; k<n; k++)
				mintour[k]=temp[k];
		}
	}
	for(i=0; i<n; i++)
	{
		tour[i]=mintour[i];
	}
	return mincost;
}
void main()
{
	int i, j, mincost, cost, n, s, cov[10], tour[10];
	printf("\nEnter the total number of vertices:");
	scanf("%d", &n);
	printf("\n Enter the matrix for %d vertices\n", n);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("\n%d", &a[i][j]);
		}
	}
	for(i=0; i<n; i++)
	{
		cov[i]=0;
		tour[i]=i;
	}
	approximate(cov,0,n);
	mincost=tsp_dp(a, tour, 0, n);
	for(i=0; i<n; i++)
		printf("%d---->", tour[i]);
	if(mincost>0)
	{
		printf("\n Dynamic Programming Min Cost is %d\n",mincost);
		printf("\nError rate is %f\n", (((float)apxcost-mincost)/mincost)*100);
		printf("\nAccuracy rate is %f\n",((float)apxcost/mincost));
	}
}

