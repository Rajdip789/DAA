#include<stdio.h>
#include<stdlib.h>

int binarySearch(int a[],int n,int y)
{
	int low=0,high=n-1,mid,pos=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==y)
		{
			pos = mid;
		    break;
		}
		else if(a[mid]>y)
		    high = mid-1;
		else
		    low = mid+1;
	}		
	return pos;
}

main()
{
	int *p,n,i,key,pos;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	
	p=(int*)malloc(n*sizeof(int));
	printf("Enter the elements (in sorted order):\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	
	printf("Enter the element to be search: ");
	scanf("%d",&key);
	
	pos = binarySearch(p,n,key);
	
	if(pos==-1)
		printf("Element not found.");
	else
		printf("Found in position %d.",pos+1);
}
