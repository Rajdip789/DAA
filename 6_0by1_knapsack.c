#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(x,y){
	return (x>y)?x:y;
}

//Recursion + Memoization
int knapSack_0_1_1(int m, int ind, int* p, int* w, int** dp){	
	if(ind==0){
		if(w[ind]<=m)
			return p[ind];
		else
			return 0;
	}

	if(dp[ind][m]!=-1)
		return dp[ind][m];
			
	int notTake=0+knapSack_0_1_1(m,ind-1,p,w,dp);
	int take = INT_MIN;
	if(w[ind]<=m)
		take=p[ind]+knapSack_0_1_1(m-w[ind],ind-1,p,w,dp);
	
	return dp[ind][m]=max(take,notTake);
}

//Tabulation
int knapSack_0_1_2(int maxWeight, int n, int* val, int* wt, int** dp){	
	int ind,w;
	for(w=wt[0];w<=maxWeight;w++) 
		dp[0][w]=val[0];
		
	for(ind=1;ind<n;ind++){
		for(w=0;w<=maxWeight;w++){
			int notTake=0+dp[ind-1][w];
			int take = INT_MIN;
			if(wt[ind]<=w)
				take=val[ind]+dp[ind-1][w-wt[ind]];
			
			dp[ind][w]=max(take,notTake);
		}
	}
	return dp[n-1][maxWeight];
}

//single row space optimization
int knapSack_0_1_3(int maxWeight, int n, int* val, int* wt){	
	int ind,w;
	int *prev;
	prev=(int*)malloc((maxWeight+1)*sizeof(int));
	for(ind=0;ind<n;ind++)
			prev[ind]=0;
	
	for(w=wt[0];w<=maxWeight;w++) 
		prev[w]=val[0];
		
	for(ind=1;ind<n;ind++){
		for(w=maxWeight;w>=0;w--){
			int notTake=0+prev[w];
			int take = INT_MIN;
			if(wt[ind]<=w)
				take=val[ind]+prev[w-wt[ind]];
			
			prev[w]=max(take,notTake);
		}
	}
	return prev[maxWeight];
}


int main(){
	int i,j,m,n,*p,*w,**dp;
	
	printf("Enter the knapsack capacity: ");
	scanf("%d",&m);
	printf("Enter the number of items: ");
	scanf("%d",&n);
	
	p=(int*)malloc(n*sizeof(int));
	w=(int*)malloc(n*sizeof(int));
	dp=(int**)malloc(n*sizeof(int*));
	
	for(i=0;i<n;i++)
		dp[i]=(int*)malloc((m+1)*sizeof(int));
	
	for(i=0;i<n;i++)
		for(j=0;j<=m;j++)
			dp[i][j]=0;
		
	printf("Enter the profits and weights:\n");
	for(i=0;i<n;i++){
		printf("Item %d: ",i+1);
		scanf("%d%d",&p[i],&w[i]);
	}

	printf("\nMaximum profit: %d\n",knapSack_0_1_2(m,n-1,p,w,dp));
	//printf("\nMaximum profit: %d\n",knapSack_0_1_3(m,n-1,p,w));
	
	/*for(i=0;i<n;i++){
		for(j=0;j<=m;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}*/
			
	return 0;
}



