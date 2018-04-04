#include<stdio.h>

int root[10],cost[10][10],temp,flag;
int n,count=0,i,j,x,y,min,total_cost = 0;

void find_min(){
	min = 999;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(cost[i][j] < min){
				min = cost[i][j];
				x = i;
				y = j;
			}
}


void check_cycle(){

	if((root[x]==root[y]) && (root[x] != 0 ))
		flag = 0;
	else
		flag = 1;
}
void update(){

	if(root[x] == 0 && root[y] == 0 )
		root[x] = root[y] = x;
	else if(root[x] == 0)
		root[x] = root[y];
	else if(root[y] == 0 )
		root[y] = root[x];
	else{
		temp = root[y];
		for(i=1;i<=n;i++)
			if(root[i] == temp)	
				root[i] = root[x];
	}
}

void main(){

	printf("\nEnter number of vertices :: ");
	scanf("%d",&n);

	printf("\nEnter Cost adjacency matrix :: \n");

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	}

	find_min();

	while(min != 999 && count != (n-1)){

		check_cycle();

		if(flag){
			printf("\n%d -- > %d :: cost = %d",x,y,min);
			total_cost += min;
			count++;
			update();
		}

		cost[x][y] = cost[y][x] = 999;
		find_min();
	}
	if(count < (n-2))
		printf("\nGraph is not connected\n");
	else
		printf("\nTotalCost = %d\n",total_cost);
}





