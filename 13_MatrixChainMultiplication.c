#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//TABULATION + OPTIMIZED
int MatrixChainOrder_2(int *p,int n,int **m,int **s){
	int i,j,d,k,q,min;
	for(i=0;i<n;i++){
		m[i][i]=0;
		s[i][i]=0;
	}
	for(d=1;d<n-1;d++){
		for(i=1;i<n-d;i++){
			j=i+d;
			min = INT_MAX;
			for(k=i;k<=j-1;k++){
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<min){
					min=q;
					s[i][j]=k;
				}
			}
			m[i][j]=min;
		}
	}
	return min;		
}

//OPTIMAL SEQUENCE
void optimal(int **s,int i,int j){
	if(i==j)
		printf("A%d",i);
	else{
		printf("(");
		optimal(s,i,s[i][j]);
		optimal(s,s[i][j] + 1,j);
		printf(")");
	}
}

//PRINT THE M AND S MATRIX
void pritfMatrices(int **m, int **s, int n){
	int i,j;
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i<=j)
				printf("%d ",m[i][j]);
			else
				printf("  ");
		}
		printf("\n");
	}	
	printf("\n");		
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i<=j)
				printf("%d ",s[i][j]);
			else
				printf("  ");
		}
		printf("\n");
	}
}

//RECURSION + MEMOIZATION
int MatrixChainOrder_1(int *arr,int i, int j, int **dp){     
	if(i==j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	int k,steps;	
	int mini = INT_MAX;
	for(k=i;k<j;k++){
		steps = (arr[i-1]*arr[k]*arr[j])+MatrixChainOrder_1(arr,i,k,dp)+MatrixChainOrder_1(arr,k+1,j,dp);
		
		if(steps<mini) 
			mini = steps;
	}	
	return dp[i][j]=mini;
}

int main(){
	int n,*p,i,j,**m,**s;
	printf("Enter the number of matrices: "); 
	scanf("%d",&n);
	
	//Length of the array is n+1
	p=(int*)malloc((n+1)*sizeof(int));
	m=(int**)malloc((n+1)*sizeof(int*));
	s=(int**)malloc((n+1)*sizeof(int*));
	
	for(i=0;i<=n;i++)
		m[i]=(int*)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;i++)
		s[i]=(int*)malloc((n+1)*sizeof(int));
				
	printf("Enter the array for dimensions of matrices: ");
	for(i=0;i<=n;i++)
		scanf("%d",&p[i]);
		
	printf("Minimum cost for multiplication is: %d",MatrixChainOrder_2(p,n+1,m,s));			//TABULATION METHOD
	printf("\nThe optimal sequence is: ");
	optimal(s,1,n);
	
	//pritfMatrices(m,s,n);			//UNCOMENT TO SHOW THE MATRICES
	
	
	/*for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			m[i][j]=-1;
	printf("%d",MatrixChainOrder_1(p,1,n,m));*/			//RECURSION + MEMOIZATION METHOD
			
	return 0;
}
