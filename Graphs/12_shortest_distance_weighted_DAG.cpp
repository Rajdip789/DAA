/**
 *	Shortest distance in a weighted DAG - Toposort + relaxation of vertices
 *	TC - O(3 *(V + E)) ~ O(V + E)
 *	SC - O(3 * V) + O(V + E) ~ O(V)
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void topoSort(int node, stack<int> &st, vector<int> &vis, vector<pair<int,int>> adj[]) {
			vis[node] = 1;

			for(auto it: adj[node]) {
				if(!vis[it.first])
					topoSort(it.first, st, vis, adj);
			}

			st.push(node);
		}
		
		vector<int> shortestPath(int src, int V, vector<pair<int,int>> adj[]) {
			vector<int> vis(V, 0);
			
			// Find the toposort for the weighted DAG
			stack<int> st;
			for(int i = 0; i < V; i++) {
				if(!vis[i]) {
					topoSort(i, st, vis, adj);
				}
			}
			
			// Create a dist array and initialized with 1e9
			vector<int> dist(V);
			for(int i = 0; i < V; i++) {
				dist[i] = 1e9;
			}

			dist[src] = 0;

			while(!st.empty() && st.top() != src) st.pop();	  // pop the stack util stack top is source
			
			while(!st.empty()) {
				int node = st.top();
				st.pop();
				
				for(auto it : adj[node]) {
					int v = it.first;
					int wt = it.second;

					if(dist[node] + wt < dist[v]) {
						dist[v] = dist[node] + wt;
					}
				}
			}
			
			for(int i = 0; i < V; i++) {
				if(dist[i] == 1e9) dist[i] = -1;
			}	

			return dist;		
		}
};

int main() {
	int n, m;
	cout << "Enter the no of vertex and edges: ";
	cin >> n >> m;
	
	vector<pair<int, int>> adj[n];    //for weighted graph
	
	cout << "Enter the edge details: (v1, v2, weight) " << endl;	
	for(int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
	}	

	int src;
	cin >> src;

	Solution s1;
	vector<int> dist = s1.shortestPath(src, n, adj);

	cout << "Distance from " << src << " to: " << endl;
	for(int i = 0; i < n; i++) {
		cout << i << " -> " << dist[i] << endl;
	}
        
	return 0;
}
