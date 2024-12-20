/**
 *	Graph representation using Adjacency List (directed, undirected, weighted, unweighted)
 *	N / V = no of vertices
 *	E = no of edges 
**/

#include<bits/stdc++.h>
using namespace std;

void print_graph(int V, vector<int> adj[]) {
	for(int i = 0; i < V; i++) {
		
		cout << i << " -> ";
		for(auto it : adj[i]) {
			cout << it << " ";
		}
		
		cout << endl;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	//vector<pair<int,int>> adj[n+1];    // add this for weighted graph
	vector<int> adj[n+1];                // take n+1, in case graph is 1-indexed

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	// ommit this line in case of a directed graph
	}	

	print_graph(n, adj);

	return 0;
}
