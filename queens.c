#include<stdio.h>
#include<stdlib.h>
int a[30], count = 0;
int place(int p)
{
	int i;
	for(i=1; i<p; i++)
	{
		if((a[i] == a[p]) || (abs(a[i]-a[p]) == abs(i-p)))
			return 0;
	}
	return 1;
}
void print_soln(int n)
{
	int i, j;
	count++;
	printf("Solution = %d \n", count);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(a[i] == j)
				printf("Q\t");
			else
				printf("#\t");
		}
		printf("\n");
	}
}
void queen(int n)
{
	int k = 1;
	a[k] = 0;
	while(k != 0)
	{
		a[k] = a[k] + 1;
		while((a[k] <= n) && !place(k))
			a[k]++;
		if(a[k] <= n)
		{
			if(k == n)
				print_soln(n);
			else
			{
				k++;
				a[k] = 0;
			}
		}
		else
			k--;
	}
}
void main()
{
	int i, n;
	printf("Enter No. of queens\t");
	scanf("%d",&n);
	if(n == 1)
		printf("Trivial solution\n");
	else if (n <= 3)
		printf("No solution\n");
	else
		queen(n);
	if(count != 0)
		printf("\nTotal solution = %d\n", count);
}

