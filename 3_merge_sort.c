#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int low, int mid, int high)
{
	int i=low, k=low, j=mid+1;
	int b[20];
	while((i<=mid) && (j<=high))
	{
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

void merge_sort(int a[], int low, int high)
{
	int mid;
	mid = (low+high)/2;
	if(low<high){
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
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
	
	merge_sort(arr,0,n-1);
	
	printf("\nAfter sorting the elements are: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
