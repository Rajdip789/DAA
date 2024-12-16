#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool found=false;

void nextValue(int k, int n, int **adj, int *x){
	int j=0;
	do{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
			return;
		if(adj[x[k-1]][x[k]]==1){
			for(j=1;j<=k-1;j++)
				if(x[j]==x[k])
					break;
			if(j==k)
				if(k<n || ((k==n) && adj[x[n]][x[1]]==1))
					return;
		}
	}while(true);
}

void hamiltonian(int k, int n, int **adj, int *x){
	int i;
	x[1]=1;
	do{
		nextValue(k,n,adj,x);
		if(x[k]==0)
			return;
		if(k==n){
			found = true;
			for(i=1;i<n+1;i++){
				printf("%d-->",x[i]);
			}
			printf("1\n");
		}
		else
			hamiltonian(k+1,n,adj,x);			
	}while(true);
}

int main(){
	int i,j,v,e,**adj,*x;
	printf("Enter the number of vertices and edges of the graph: ");
	scanf("%d%d",&v,&e);
	
	adj=(int**)malloc((v+1)*sizeof(int*));	
	for(i=0;i<v+1;i++)
		adj[i]=(int*)malloc((v+1)*sizeof(int));
		
	x=(int*)malloc((v+1)*sizeof(int));

	for(i=0;i<v+1;i++)
		for(j=0;j<v+1;j++)
			adj[i][j]=0;
			
	printf("Enter the edges of the graph(v1,v2):\n ");
	for(i=0;i<e;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x][y]=1;
		adj[y][x]=1;
	}

	hamiltonian(2,v,adj,x);
	
	if(!found)
		printf("Hamiltonian circuit does not exists.\n");
		
	/*for(i=1;i<v+1;i++){
		for(j=1;j<v+1;j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}*/
	return 0;
}
