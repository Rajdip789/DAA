/**
 *	Bellman Ford Alrorithm: finds shortest path from a given source node to every other node in a Directed Weighted graph.
 *	It also works with negative weight edge. It can detect if a negative weight cycle is present in the graph.
 * 	To use it in an undirected graph it has to be converted into a directed graph. 
 * 
 *	TC - O(V*E) / SC - O(V)
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool bellmanFord(int src, int V, vector<int> &dist, vector<vector<int>> &edges) {
			dist[src] = 0;

			// relax the all the edges of the graph N-1 times, N = no of Nodes
			for(int i = 0; i < V-1; i++) {	
				for(auto it : edges) {    
					int u = it[0];
					int v = it[1];
					int wt = it[2];

					if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
						dist[v] = dist[u] + wt;
					}
				}
			}
			
			// after N-1 relaxation, if still edge weight reduces means Negative weight cycle present
			for(auto it: edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];

				if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {	
					return false;
				}
			}
			
			return true;
		}
};

int main() {
	int n, m;
	cout << "Enter the no of vertex and edges: ";
	cin >> n >> m;
	
	vector<vector<int>> edges;

	cout << "Enter the edge details: (v1, v2, weight) " << endl;	
	for(int i = 0; i < m; i++) {        
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({u, v, wt});
	}
	
	int src;
	cin >> src;
	
	Solution s1;
	vector<int> dist(n, 1e8);
	
	if(!s1.bellmanFord(src, n, dist, edges)) 
		cout << "Negative weight cycle found";	
	
	cout << "Distance from " << src << " to: " << endl;
	for(int i = 0; i < n; i++) {
		cout << i << " -> " << dist[i] << endl;
	}
        
	return 0;
}

