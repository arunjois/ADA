#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int arr[3000];
int n,i;
void quicksort(int*,int,int);
int main()
{
	printf("\n Enter the value of n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
		printf("%d ",arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("\n Sorted elements are\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
void quicksort(int *arr,int low,int high)
{
	int i,j,pivot,temp;
	if(low<high) {
		i=low;
		j=high;
		pivot=low;
		while(i<j)
		{
			while(arr[i]<=arr[pivot]&&i<=j)
				i++;
			while(arr[j]>arr[pivot]&&j>i)
				j--;
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=arr[i];
			}
		}
		temp=arr[j];
		arr[j]=arr[pivot];
		arr[pivot]=arr[j];
		quicksort(arr,low,j-1);
		quicksort(arr,j+1,high);
	}
}
