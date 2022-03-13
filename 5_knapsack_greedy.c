#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int low, int mid, int high){
	int i=low, k=low, j=mid+1;
	int b[20];
	while((i<=mid) && (j<=high)){
		if(a[i]>a[j]){
			b[k]=a[j];
			k++;
			j++;
		}
		else{
			b[k]=a[i];
			k++;
			i++;
		}
	}
	while(i<=mid){
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<=high){
		b[k]=a[j];
		k++;
		j++;
	}
	int r=low;
	while(r<k){
		a[r]=b[r];
		r++;
	}
}

void merge_sort(int a[], int low, int high){
	int mid;
	mid = (low+high)/2;
	if(low<high){
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}	
}

void greddy_knapSack(int m, int n, int* p, int* w, float* temp, float* x){
	int i;
	merge_sort(temp,0,n-1);
	for(i=0;i<n;i++)
		x[i]=0.0;
		
	for(i=0;i<n;i++){
		if(w[i]>m) break;
		x[i]=1.0;
		m-=w[i];
	}
	if(i<n)
		x[i]=m/w[i];
}

int main(){	
	int i,m,n,*p,*w;
	float *x,*temp;
	
	printf("Enter the knapsack capacity: ");
	scanf("%d",&m);
	printf("Enter the number of items: ");
	scanf("%d",&n);
	
	p = (int*)malloc(n*sizeof(int));
	w = (int*)malloc(n*sizeof(int));
	x = (float*)malloc(n*sizeof(float));
	temp = (float*)malloc(n*sizeof(float));
	
	printf("Enter the profits and weights:\n");
	for(i=0;i<n;i++){
		printf("Item %d: ",i+1);
		scanf("%d%d",&p[i],&w[i]);
		temp[i]=(float)p[i]/w[i];
	}
	
	greddy_knapSack(m,n,p,w,temp,x);
	
	for(i=0;i<n;i++){
		printf("%.2f\n",temp[i]);
	}
	return 0;
}
