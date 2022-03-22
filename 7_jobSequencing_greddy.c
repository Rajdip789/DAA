#include<stdio.h>
#include<stdlib.h>

struct job{
	int no;
	int profit;
	int deadline;	
};


/*MERGE SORT*/
void merge(struct job jobList[10], int low, int mid, int high){
	int i=low, k=low, j=mid+1;
	struct job temp[10];
	while((i<=mid) && (j<=high)){
		if(jobList[i].profit>jobList[j].profit){
			temp[k]=jobList[i];
			k++;
			i++;
		}
		else{
			temp[k]=jobList[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		temp[k]=jobList[i];
		k++;
		i++;
	}
	while(j<=high){
		temp[k]=jobList[j];
		k++;
		j++;
	}
	int r=low;
	while(r<k){
		jobList[r]=temp[r];
		r++;
	}
}

void merge_sort(struct job jobList[10], int low, int high){
	int mid;
	mid = (low+high)/2;
	if(low<high){
		merge_sort(jobList, low, mid);
		merge_sort(jobList, mid+1, high);
		merge(jobList, low, mid, high);
	}	
}

/*int greddy_JS(int n, struct job jobList[10], int* J){
	int i,k,q,r;
	merge_sort(jobList,1,n);
	
	J[1] = 1; // Include job 1 that gives maximum profit.
	k=1; // k indicates how many jobs are there in J matrix.
	for(i=2;i<=n;i++){
		r=k;
		// Find the position r after which i will be included in J[].
		while((jobList[J[r]].deadline>jobList[i].deadline) && (jobList[J[r]].deadline > r))
			r-=1;
			
		if(jobList[i].deadline>r){
			// Insert i into J[r+1].
			for(q=k;q>=r+1;q--)
				J[q+1] = J[q];
				
			J[r+1]=i;
			k=k+1;
		}
	}
	return k;
}*/

int* greddy_JS(int n, struct job jobList[n], int* k){
	int i,j,*result,maxDead=0;
	
	merge_sort(jobList,1,n);
	
	for(i=1;i<=n;i++){
		printf("\n%d %d %d",jobList[i].profit,jobList[i].deadline,jobList[i].no);
	}
	
	for(i=1;i<=n;i++){
		if(maxDead<jobList[i].deadline)
			maxDead=jobList[i].deadline;
	}
	result=(int*)malloc(maxDead*sizeof(int));
	
	for(i=1;i<=maxDead;i++)
		result[i]=-1;
		
	printf("\nDeadline: %d\n",maxDead);
	for(i=1;i<=n;i++){
		for(j=jobList[i].deadline;j>0;j--){
			if(result[j]==-1){
				result[j]=jobList[i].no;
				(*k)++;
				break;
			}
		}
	}
	
	return result;
}

int main(){
	int i,n,p,*J,k=0;
	
	printf("Enter the number of jobs: ");
	scanf("%d",&n);
	
	struct job jobList[n];
	J=(int*)malloc(n*sizeof(int));

	printf("Enter the profits and deadline:\n");
	for(i=1;i<=n;i++){
		int x,y;
		printf("Job %d: ",i);
		scanf("%d %d",&x,&y);
		jobList[i].no=i;
		jobList[i].profit=x;
		jobList[i].deadline=y;
	}
	
	J = greddy_JS(n,jobList,&k);
	
	printf("\nNo of items: %d\nThe items are: ",k);
	for(i=1;i<=k;i++)
		printf("%d ",J[i]);
	return 0;
}















