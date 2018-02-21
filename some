#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void quicksort(int*,int,int);
int main()
{
	int arr[5000],n,i,k,iter,j;
	FILE *fp;
	fp=fopen("output.txt","w");
	struct timeval tvalBefore, tvalAfter; 
	printf("\n Enter the no. of iternation\n");
	scanf("%d",&iter);
	for(j=0;j<iter;j++) 
	{
		printf("\n Enter the value of n\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
			arr[i]=rand()%1000;
		gettimeofday(&tvalBefore,NULL); 
		quicksort(arr,0,n-1);
		gettimeofday(&tvalAfter,NULL); 
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
		k = (tvalAfter.tv_usec) - (tvalBefore.tv_usec);
		fprintf(fp,"\n %d  %d \n",n,k);
	}
	fclose(fp);
	return 0;
}
void quicksort(int *arr,int low,int high)
{
	int pivot,i,j,temp;
	if(low<high)
	{
		pivot=low;
		i=low;
		j=high;
		while(i<j) {
			while(arr[i]<=arr[pivot]&&i<=high)
				i++;
			while(arr[j]>arr[pivot]&&j>=low)
				j--;
			if(i<j) {
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[j];
		arr[j]=arr[pivot];
		arr[pivot]=temp;
		quicksort(arr,low,j-1);
		quicksort(arr,j+1,high);
	}
}


