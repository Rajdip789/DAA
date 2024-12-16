#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define v 4

void floyd_warshall(int graph[v][v]) {
	int i, j, k;
	int dist[v][v];
	
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			dist[i][j] = graph[i][j];
		}
	}
	
	for(k = 0; k < v; k++) {
		for(i = 0; i < v; i++) {
			for(j = 0; j < v; j++) {
				if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
					continue;
				else if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	for(i = 0; i < v; i++) {
		if(dist[i][i] < 0) {
			printf("Negative edge weight cycle is present\n");
			return;
		}
	}
	
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			printf("%d to %d distance is %d\n",i, j, dist[i][j]);
		}
	}
}

int main() {
	int graph[v][v] = { {0, 8, INT_MAX, 1},
						{INT_MAX, 0, 1, INT_MAX},
						{4, INT_MAX, 0, INT_MAX},
						{INT_MAX, 2, 9, 0}
					};
	floyd_warshall(graph);
	return 0;
}
