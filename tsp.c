#include<stdio.h>
int n=6,totaldistance=0;
int path[20],rear=0,min,temp[20],s,visited[20],firstvertex;

int cost_matrix[6][6]={
					  { 0 ,58 ,37,57,49,34},
					  {58 , 0 ,44,17,53,36},
					  {37 ,44 , 0,45,48,50},
					  {57 ,17 ,45,0,6,5},
					  {49 ,53 ,48,6,0,24},
					  {34 ,36 ,50,5,24,0}};
int min_value(int a,int b) {
	min=a<b?a:b;
	return min;
}
void tsp(){
	int i=0,j=0,rowcounter=0;
	visited[i]=1;
	firstvertex=0;
	path[rear++]=i;
	printf("\n Values selected: ");
	while(i<n && rowcounter<n) {
		j=0;
		min=9999;
		s=0;
		while(j<n) {
			if(i!=j && !visited[j]) {
				temp[s++]=min_value(cost_matrix[j][i],min);
			}
			else {
				temp[s++]=-1;
			}
			j++;
		}
		for(s=0;s<n;++s) {
			if(temp[s]==min ) {
				printf("%d ",min);
				i=s;
				totaldistance+=min;
				path[rear++]=s;
				visited[i]=1;
				break;
			}
		}
		if(rowcounter+1==n) {
			printf("%d",cost_matrix[firstvertex][i]);
			totaldistance+=cost_matrix[firstvertex][i];
			path[rear]=firstvertex;
		}
		rowcounter++;
	}
}
void displaymatrix() {
	int i,j;
	for(i=0;i<n;++i) {
		visited[i]=0;
		for(j=0;j<n;++j) {
			printf("%d ",cost_matrix[i][j]);
		}
		printf("\n");
	}

}
void printvisited() {
	int i;
	printf("\n Visited: ");
	for(i=0;i<n;++i) {
		printf("%d ",visited[i]);
	}
	printf("\n");
}
void printpathinalphabet() {
	int i;
	printf("\nPath: ");
	for(i=0;i<=n;++i) {
		if(i!=n)
			printf(" %c ->",path[i]+65);
		else
			printf(" %c ",path[i]+65);
	}
	printf("\n");
}
void printpathindigit() {
	int i;
	printf("\n Total Distance:%d ",totaldistance);
	printf("\nPath: ");
	for(i=0;i<=n;++i) {
		printf("%d ",path[i]);
	}
	printpathinalphabet();
}

int main() {
	//int i,j;
	//printf("\n Input number of object:");
	//scanf("%d",&n);
	//printf("\n Input Matrix:\n");
	//for(i=1;i<=n;++i) {
	//	visited[i]=0;
	//	for(j=1;j<=n;++j) {
	//		scanf("%d",&cost_matrix[i][j]);
	//	}
	//}
	//printf("\n Input starting vertex: ");
	//scanf("%d",&s);
	displaymatrix();
	tsp();
	printpathindigit();
	return 0;
}

