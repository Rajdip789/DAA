#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(x,y){
	return (x>y)?x:y;
}

int knapSack_0_1(int m, int ind, int* p, int* w){
	if(ind==0){
		if(w[ind]<=m)
			return p[ind];
		else
			return 0;
	}
	
	int first=0+knapSack_0_1(m,ind-1,p,w);
	
	int second = INT_MIN;
	if(w[ind]<=m)
		second=p[ind]+knapSack_0_1(m-w[ind],ind-1,p,w);
	
	return max(first,second);
}

int main(){
	int i,m,n,*p,*w,profit;
	int **dp;
	
	printf("Enter the knapsack capacity: ");
	scanf("%d",&m);
	printf("Enter the number of items: ");
	scanf("%d",&n);
	
	/*p=(int*)malloc(n*sizeof(int));
	w=(int*)malloc(n*sizeof(int));
	dp=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		dp[i]=(int*)malloc(m*sizeof(int));
		
	for(i=0;i<n;i++)
		for(i=0;i<n;i++)*/
			

		
	printf("Enter the profits and weights:\n");
	for(i=0;i<n;i++){
		printf("Item %d: ",i+1);
		scanf("%d%d",&p[i],&w[i]);
	}

	printf("\nMaximum profit: %d",knapSack_0_1(m,n-1,p,w));
	return 0;
}
