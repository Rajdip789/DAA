//Implement a program in C to find the BFS traversal sequence from a given graph.
#include<stdio.h>
#define True 1
#define False 0

int front, rear;

void EmptyQueue(int Q[20]) {
	front=rear=0;
}

void Insert(int Q[20],int item) {
	Q[rear]=item;
	rear++;	
}

int Empty(int Q[20]) {
	if(front==rear)
		return True;
	else
		return False;
}

int Delete(int Q[20]) {
	int item;
	item=Q[front];
	front++;
	return item;	
}

void Print(int n) {
	printf("%d\t",n);
}

void BFS(int G[20][20], int s, int n) {	// s = Starting vertex 
	int i, v, visited[20], Q[20], w,u;
	for(v=1;v<=n;v++)
		visited[v] = False;
	EmptyQueue(Q); 
	Insert(Q,s); 
	while (!Empty(Q)) {
		u = Delete(Q); 
		if (visited[u]==False) {
			visited[u] = True; 
			Print(u); 
			for (w=1;w<=n;w++)
				if (G[u][w]!=0 && (visited[w] == False))
					Insert(Q, w);
		} 
	}
}

int main() {
	int s, G[20][20],n,i,j;
	printf("Enter number of vertices and starting vertex\n");
	scanf("%d%d",&n,&s);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&G[i][j]);
	
	printf("BFS traversal is:\n");
	BFS(G,s,n);
	printf("\n");
	return 0;
}
