#include<stdio.h>
#include<stdlib.h>

struct item{
	int profit;
	int weight;
	float ratio;	
};

/*MERGE SORT*/
void merge(struct item itemList[10], int low, int mid, int high){
	int i=low, k=low, j=mid+1;
	struct item temp[10];
	while((i<=mid) && (j<=high)){
		if(itemList[i].ratio>itemList[j].ratio){
			temp[k]=itemList[i];
			k++;
			i++;
		}
		else{
			temp[k]=itemList[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		temp[k]=itemList[i];
		k++;
		i++;
	}
	while(j<=high){
		temp[k]=itemList[j];
		k++;
		j++;
	}
	int r=low;
	while(r<k){
		itemList[r]=temp[r];
		r++;
	}
}

void merge_sort(struct item itemList[10], int low, int high){
	int mid;
	mid = (low+high)/2;
	if(low<high){
		merge_sort(itemList, low, mid);
		merge_sort(itemList, mid+1, high);
		merge(itemList, low, mid, high);
	}	
}

/*GREDDY KNAPSACK*/
float greddy_knapSack(int m, int n, struct item itemList[10], float* x){
	int i,u;
	float profit;
	merge_sort(itemList,0,n-1);
	
	for(i=0;i<n;i++)
		x[i]=0.0;
		
	for(i=0;i<n;i++){
		if(itemList[i].weight>m) break;
		x[i]=1.0;
		m-=itemList[i].weight;
		profit+=itemList[i].profit;
	}
	if(i<n){
		x[i]=(float)m/itemList[i].weight;
		profit+=(x[i]*itemList[i].profit);
	}
		
	return profit;
}

int main(){	
	int i,m,n;
	float *x,p;
	
	printf("Enter the knapsack capacity: ");
	scanf("%d",&m);
	printf("Enter the number of items: ");
	scanf("%d",&n);
	
	struct item itemList[n];
	x=(float*)malloc(n*sizeof(float));
	
	printf("Enter the profits and weights:\n");
	for(i=0;i<n;i++){
		int x,y;
		printf("Item %d: ",i+1);
		scanf("%d%d",&x,&y);
		itemList[i].profit=x;
		itemList[i].weight=y;
		itemList[i].ratio=(float)x/y;
	}
	
	p = greddy_knapSack(m,n,itemList,x);
	
	printf("Items after sorting: ");
	for(i=0;i<n;i++){
		printf("\n%d %d %f",itemList[i].profit,itemList[i].weight,itemList[i].ratio);
	}
	
	printf("\nMaximum profit: %f\nAnd the result vector is:\n",p);
	for(i=0;i<n;i++)
		printf("%f\t",x[i]);
	
	return 0;
}










