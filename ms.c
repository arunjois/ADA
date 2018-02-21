#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>

int a[9000],b[9000];
struct timeval et,st;

void merge(int a[],int i1,int i2,int j1,int j2)
{

	int temp[9000],i,j,k;
	i=i1;
	j=j1;
	k=0;

	while(i<=i2 && j<=j2)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}

	while(i<=i2)
		temp[k++]=a[i++];
	while(j<=j2)
		temp[k++]=a[j++];   

	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}

void mergesort(int a[],int i,int j)
{
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);
		mergesort(a,mid+1,j);
		merge(a,i,mid,mid+1,j);
	}
}

void main()
{
	int j,n,m,i,no,k;
	struct timeval et,st;
	FILE *fp;                      
	fp=fopen("result.txt","w");    
	printf("Enter the no. of iterations \n");
	scanf("%d",&no);
	for(j=0;j<no;j++)
	{
		printf("\nEnter n:\n ");
		scanf("%d",&n);

		for(i=0;i<n;i++)
		{
			a[i]=rand()%1000;
		}
		printf("Before sorting\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}

		gettimeofday(&st,0);
		mergesort(a,0,n-1);
		gettimeofday(&et,0);
		k=et.tv_usec-st.tv_usec;
		fprintf(fp,"%d\t%d\n",n,k);
		printf("\nSorted array is \n");
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
	}
	fclose(fp);
	printf("\n");  
}

