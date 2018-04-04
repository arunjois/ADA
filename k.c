#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

struct mytimer{
	int t;
}mytime;

int i,k,j,a,b,u,v,ne=1,n,min,mincost=0;
int count = 0, var=1,cost[10][10],visited[10],parent[9];

int find(int i){
	
	while(parent[i])
		i = parent[i];
	return i;

}
int uni(int i ,int j){
	
	if(i != j){	
		parent[j] = i;
		return 1;
	}
	else
		return 0;
}

void main(){

struct timeval st,en;
printf("\nEnter No. of vertices :: ");
scanf("%d",&n);
printf("\nEnter adjacency matrix:: \n");

for(i=0;i<n;i++)
	for(j=0;j<n;j++){
		scanf("%d",&cost[i][j]);
		if(cost[i][j] == 0)
			cost[i][j] = 999;
	}
gettimeofday(&st,0);

visited[1] = 1;
printf("\n");

while(ne < n){
	
	for(i=0,min=999;i<n;i++)
		for(j=0;j<n;j++)
			if(cost[i][j] < min){
					min = cost[i][j];
					a = u = i;
					b = v = j;			
			}
	u = find(u);
	v = find(v);
	if (min == 999)
		break;
	
	if(uni(u,v)){
	
		printf("\nEdge %d (%d -- > %d ):: Cost = %d",ne++,a,b,min);
		mincost += min;
		count++;
	}
		cost[a][b] = cost[b][a] = 999;
	}

gettimeofday(&en,0);
	
mytime.t = (en.tv_usec - st.tv_usec);

	if (count < n-1)
		printf("\n\nGraph is Not connected\n");
	else{
		printf("\nMincost = %d \n",mincost);
		printf("\nTime Taken = %d\n",mytime.t);
	}
}



