#include<stdio.h>

int a[20];
void MaxMin(int, int, int*, int*);
int Find_Max(int, int);
int Find_Min(int, int);

int main(){
	int n,i,x,y;
	printf("Enter number of elements: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	MaxMin(0,n-1,&x,&y);
	printf("\nMax=%d\nMin=%d",x,y);	
	return 0;
}

void MaxMin(int i, int j, int *max, int *min){ //x=max, y=min
	int mid,x,y,x1,y1;
	if(i==j)
		x=y=a[i];
 	else if(i==j-1){
	 	x = Find_Max(a[i],a[j]);
	 	y = Find_Min(a[i],a[j]);
 	}
 	else{
 		mid=(i+j)/2;
 		MaxMin(i, mid, &x, &y);
 		MaxMin(mid+1, j, &x1, &y1);
 		x=Find_Max(x, x1); 
	 	y=Find_Min(y, y1);
 	}
 	*max=x;
 	*min=y;
}

int Find_Max(int i, int j){
	if(i>j)
		return(i);
	else
		return(j);
}

int Find_Min(int i, int j){
	if(i<j)
		return(i);
	else
		return(j);
}
