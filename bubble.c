#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void sbs(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			if(a[j+1]<a[j])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
}
void mbs(int b[],int n)
{
	int i,j,temp,flag=0;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
			if(b[j+1]<b[j])
			{
				temp=b[j+1];
				b[j+1]=b[j];
				b[j]=temp;
				flag=1;
			}
		if(flag==0)
			break;
	}
}
void main()
{
	int a[5000],b[5000],n;
	struct timeval before, After;
	int i,cho,iter;

	FILE *fp;
	fp=fopen("output.txt","w");


	printf("\n Enter the size of Array\n");
	scanf("%d",&n);
	printf("\n Enter number of iteration\n");
	scanf("%d",&iter);
	while(1)
	{
		for(i=0;i<n;i++)
		{
			a[i]=rand()%1000;
			b[i]=a[i];
			//printf(" %d\t",a[i]);
		}
		for(i=0;i<iter;i++)
		{
		        /*printf("\n New Set of arrays\n");
			for(i=0;i<n;i++)
			{
				a[i]=rand()%1000;
				b[i]=a[i];
				//printf(" %d\t",a[i]);
			}*/
			printf("\n MENU\n");
			printf(" 1. Simple Bubble Sort\n");
			printf(" 2. Modified Bubble Sort\n");
			printf(" 3. Exit\n");
			printf(" Enter Your Choice\n");
			scanf("%d",&cho);
			switch(cho)
			{
				int k;
				case 1: gettimeofday(&before,NULL);
					sbs(a,n);
					gettimeofday(&After,NULL);
					k=After.tv_usec-before.tv_usec;
					printf("\nTime taken for sorting is %d microseconds\n",k);
					for(i=0;i<n;i++)
						printf("%d \t",a[i]);
					fprintf(fp,"%d\t%d\n",n,k);
					break;
					fprintf(fp,"\n\n");
				case 2: gettimeofday(&before,NULL);
					mbs(b,n);
					gettimeofday(&After,NULL);
					k=After.tv_usec-before.tv_usec;
					printf("\nTime taken for sorting is %d microseconds\n",k);
					for(i=0;i<n;i++)
						printf("%d \t",b[i]);
					fprintf(fp,"%d\t%d\n",n,k);
					fprintf(fp,"\n\n");
					break;
				case 3:exit(0);
			}
			for(i=0;i<n;i++)
				printf("%d \t",a[i]);


		}
		printf("\n");
	}
}
