//Implement a program in C to find the DFS traversal sequence from a given graph.
#include<stdio.h>
#define True 1
#define False 0

int top;

void EmptyStack(int S[20]) {
	top=-1;
}

void Push(int S[20],int item) {
	top++;
	S[top]=item;
}

int Empty(int S[20]) {
	if(top==-1)
		return True;
	else
		return False;
}

int Pop(int S[20]) {
	int item;
	item=S[top];
	top--;
	return item;	
}

void Print(int n) {
	printf("%d\t",n);
}

void DFS(int G[20][20], int s, int n) {	// s = Starting vertex 
	int i, v, visited[20], S[20], w,u;
	for(v=1;v<=n;v++)
		visited[v] = False;
		
	EmptyStack(S); 
	Push(S,s);
	 
	while (!Empty(S)) {
		u = Pop(S); 
		if (visited[u]==False) {
			visited[u] = True; 
			Print(u); 
			for (w=1;w<=n;w++)
				if (G[u][w]!=0 && (visited[w] == False))
					Push(S, w);
		} 
	}
}

int main(void){
	int s, G[20][20],n,i,j;
	printf("Enter number of vertices and starting vertex\n");
	scanf("%d%d",&n,&s);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&G[i][j]);
	
	printf("DFS traversal is:\n");
	DFS(G,s,n);
	printf("\n");
	return 0;
}
