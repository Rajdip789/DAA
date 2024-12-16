#include<stdio.h>
#include<stdlib.h>

int partition(int a[], int p, int r)
{
	int i,j,x;
	x=a[p];
	i = p-1;
	j = r+1;
	while(1){
		do{
			i+=1;
		}while(a[i]<x);
		
		do{
			j-=1;
		}while(a[j]>x);
		
		if(i<j){
			a[i]+=a[j];
			a[j]=a[i]-a[j];
			a[i]-=a[j];
		}
		else{
			return j;
		}
	}	
}



void quicksort(int a[], int p, int r)
{
	int q;
	if(p<r){
		q=partition(a,p,r);
		quicksort(a,p,q);
		quicksort(a,q+1,r);
	}	
}

main()
{		
	int *arr,n,i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	printf("Entered elements are: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	
	quicksort(arr,0,n-1);
	
	printf("\nAfter sorting the elements are: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
