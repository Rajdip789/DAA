#include<stdio.h>

struct Edge{
	int vertex1;
	int vertex2;
	int cost;	
};

/*HEAP SORT*/
void max_heapify(struct Edge Edgelist[10], int i, int n){        
	int left, right, largest=i;
	struct Edge temp;
	
	left = 2*i+1;
	right = 2*i+2;
	if((left<n) && (Edgelist[left].cost>Edgelist[i].cost))
		largest = left;

	if((right<n) && (Edgelist[right].cost>Edgelist[largest].cost))
		largest = right;

	if(largest!=i){
		temp = Edgelist[largest];
		Edgelist[largest] = Edgelist[i];
		Edgelist[i] = temp;
		max_heapify(Edgelist,largest, n);
	}
}

void build_maxheap(struct Edge Edgelist[10], int n){
	int i;
	for(i=n/2-1;i>=0;i--)
		max_heapify(Edgelist,i,n);
}

void heapsort(struct Edge Edgelist[10], int n){
	int i;
	struct Edge temp;
	build_maxheap(Edgelist,n);
	for(i=n-1;i>0;i--){
		temp = Edgelist[i];
		Edgelist[i] = Edgelist[0];
		Edgelist[0] = temp;
		max_heapify(Edgelist,0,i);
	}	
}


void Union(int p[], int i, int j){
	p[i]=j;
}

int Find(int p[], int i){
	while(p[i]>=0)
		i=p[i];
	return i;	
}

/*GREDDY KRUSKAL*/
int Greedy_kruskal(struct Edge Edgelist[10], int E, int V, int t[][2]){     
	heapsort(Edgelist,E);
	
	int parent[V],p=1,i;
	float mincost = 0.0;
	for(i=1;i<=V;i++)
		parent[i]=-1;
		
	for(i=0;i<E;i++){
		int j=Find(parent,Edgelist[i].vertex1);
		int k=Find(parent,Edgelist[i].vertex2);
		if(j!=k){
			t[p][1] = Edgelist[i].vertex1;
		 	t[p][2] = Edgelist[i].vertex2;
		 	p=p+1;
		  	mincost = mincost + Edgelist[i].cost;
		    Union(parent,j,k);
		}
	}		
	return mincost;
}

int main(){
	int E,V,i,t[20][2],ans;
	printf("Enter the no of edges and vertex in the graph: ");
	scanf("%d%d",&E,&V);
	
	struct Edge Edgelist[E];

	printf("Enter the details of edge (vertex1 vertex2 cost):\n");
	for(i=0;i<E;i++){
		int x,y,z;
		printf("Edge %d: ",i+1);
		scanf("%d%d%d",&x,&y,&z);
		Edgelist[i].vertex1=x;
		Edgelist[i].vertex2=y;
		Edgelist[i].cost=z;
	}
	
	ans = Greedy_kruskal(Edgelist,E,V,t);
	
	/*printf("Edgelist after sorting: ");
	for(i=0;i<E;i++){
		printf("\n%d %d %d",Edgelist[i].vertex1,Edgelist[i].vertex2,Edgelist[i].cost);
	}*/
	
	if(ans)
		printf("\n\nMinimum cost for spanning tree is: %d",ans);
	else
		printf("No spanning tree");
			
	return 0;	
}
