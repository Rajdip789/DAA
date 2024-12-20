/**
 *  Floyd Warshall Alrorithm: finds shortest path from each vertex to every other vertex in the graph.
 *  It is also called All-pair shortest path algorithm or multi-source shortest path algorithm.
 *  Works in directed as well as undirected graph. It can also detect negative weigth cycle.
 * 
 *  TC - O(V^3)  / SC - O(V^2)
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool floydWarshall(vector<vector<int>> &matrix) {
            int V = matrix.size();

            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    if(matrix[i][j] == -1) {
                        matrix[i][j] = 1e9;
                    }

                    if(i == j) matrix[i][j] = 0;    // distance from a node to itself
                }
            }

            // Floyed - warshall algo
            for(int k = 0; k < V; k++) {
                for(int i = 0; i < V; i++) {
                    for(int j = 0; j < V; j++) {
                        matrix[i][j] = min(matrix[i][j],
                                        matrix[i][k] + matrix[k][j]);
                    }
                }
            }

            // If their is a -ve distance from a vertex to itself then a negative weight cycle is present
            for(int i = 0; i < V; i++) {
                if(matrix[i][i] < 0) return false;
            }

            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    if(matrix[i][j] == 1e9) {
                        matrix[i][j] = -1;
                    }
                }
            }

            return true;
        }
};

int main() {
	int n, m;
	cout << "Enter the no of vertex and edges: ";
	cin >> n >> m;
	
	vector<vector<int>> matrix(n, vector<int> (n, -1));

	cout << "Enter the edge details: (v1, v2, weight) " << endl;	
	for(int i = 0; i < m; i++) {        
		int u, v, wt;
        cin >> u >> v >> wt;
		matrix[u][v] = wt;
	}

	Solution s1;
	
	if(!s1.floydWarshall(matrix)) 
		cout << "Negative weight cycle found";	
	
	cout << "Graph after computation: " << endl;
	for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
		    cout << matrix[i][j] << " ";
        }
        cout << endl;
	}
        
	return 0;
}