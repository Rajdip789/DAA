/*#include<stdio.h>
#include<stdlib.h>

struct job{
	int no;
	int profit;
	int deadline;	
};


//MERGE SORT
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
}

int* greddy_JS(int n, struct job jobList[], int* k){
	int i,j,*result,maxDead=0;
	
	merge_sort(jobList,1,n);
	
	for(i=1;i<=n;i++){
		if(maxDead<jobList[i].deadline)
			maxDead=jobList[i].deadline;
	}
	result=(int*)malloc((maxDead+1)*sizeof(int));
	
	for(i=1;i<=maxDead;i++)
		result[i]=-1;
		
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
	
	struct job jobList[n+1];
	J=(int*)malloc((n+1)*sizeof(int));

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
	
	printf("\Total no. of accepted items: %d\nThe job sequence is: ",k);
	for(i=1;i<=k;i++)
		printf("%d ",J[i]);
	return 0;
}*/


//Implement a program in C to solve the Job sequencing with deadline problem using Greedy method.
#include<stdio.h>
#include<conio.h>

int d[20],p[20],J[20],SortedIndex[20];
int Greedy_JS( int);
void Sort(int , int );

int main(void)
{
   	int n,i,k,profit=0,p1[20];
	
   	printf("Enter number of job\n");
   	scanf("%d",&n);
   	printf("Enter the deadlines\n");
   	for(i=1;i<=n;i++)
		scanf("%d",&d[i]);
   	printf("Enter profits\n");
   	for(i=1;i<=n;i++)
   	{
	   	scanf("%d",&p[i]);
	   	p1[i]=p[i];
   	}
		
	Sort(1,n);   	
   	k=Greedy_JS(n);
   		
   	printf("The job array is:\n");
   	for(i=1;i<=k;i++)
   		printf("%d\t",J[i]);
	printf("\nMaximum profit=:\n");
	for(i=1;i<=k;i++)
		profit=profit+p1[J[i]];
 	printf("%d\t\n",profit);
 	
 	return 0;
}

int Greedy_JS(int n)
{
	int k,i,r,q,x;
	J[1] = SortedIndex[1];		// Include job 1 that gives maximum profit.
	k=1;			// k indicates how many jobs are there in J matrix.
	for(x=2;x<=n;x++)
	{
		i=SortedIndex[x];
		r=k;
		// Find the position r after which i will be included in J[]. 
		while((d[J[r]]>d[i]) && (d[J[r]] > r))
		{
			r=r-1;
		}
		if(d[i]>r)
		{
			// Insert i into J[r+1].
			for(q=k;q>=r+1;q--)
				J[q+1] = J[q];
			J[r+1]=i;
			k=k+1;
		}
	}
	return k;
}

void Sort(int low, int high)
{
	int i,index,j,temp,max;
	for(i=low;i<=high;i++)
	{
		max=-9999;
		index=i;
		for(j=low;j<=high;j++)
			if(max<p[j])
			{
				max=p[j];
				index=j;
			}
		p[index]=-9999;
		SortedIndex[i]=index;
	}	
}
