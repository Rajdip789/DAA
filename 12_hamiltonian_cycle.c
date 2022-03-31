#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,j,v,e,**adj,ans;
	printf("Enter the number of vertices and edges of the graph: ");
	scanf("%d%d",&v,&e);
	
	adj=(int**)malloc(v*sizeof(int*));	
	for(i=0;i<v;i++)
		adj[i]=(int*)malloc(v*sizeof(int));
		
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			adj[i][j]=0;
			
	printf("Enter the edges of the graph(v1,v2): ");
	for(i=0;i<e;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x][y]=1;
		adj[y][x]=1;
	}

		
	/*for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}*/
	return 0;
}
