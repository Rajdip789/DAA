/**
 *	Bridge: If the removal of an edge in a graph, makes the graph disconnected, then it's called a Bridge.
 *	Tarjans Algorithm - find all the bridges in a graph.
 *
 *	TC - O(V + E) / SC - O(3*V)
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int timer = 1;

		void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[], vector<vector<int>> &bridges) {
			vis[node] = 1;
			tin[node] = low[node] = timer++;


			for(auto it : adj[node]) {
				if (it == parent) continue;

				if(vis[it] == 0) {
					dfs(it, node, vis, tin, low, adj, bridges);
					
					low[node] = min(low[node], low[it]);

					if (low[it] > tin[node])
						bridges.push_back({it, node});
				} else {
					low[node] = min(low[node], low[it]);
				}
			}
		}

	public:
		void findBridges(int n, vector<int> adj[], vector<vector<int>> &bridges) {
			vector<int> tin(n, -1);	  // time of insertion
			vector<int> low(n, -1);   // lowest time of insertion
			vector<int> vis(n, 0);

			for(int i = 0 ; i < n; i++) {
				if(!vis[i]) {
					dfs(i, -1, vis, tin, low, adj, bridges);
				}
			}
		}
};

int main() {
	int n, m;
	cout << "Enter the no of vertex and edges: ";
	cin >> n >> m;

	vector<int> adj[n];    //0-indexed adjacency list for the graph
	
	cout << "Enter the edge details: (u, v)" << endl;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	Solution s1;
	vector<vector<int>> bridges;

	s1.findBridges(n, adj, bridges);

	cout << "Bridges: \n";
	for(auto it : bridges) {
		int u = it[0];
		int v = it[1];

		cout << u << " - " << v << endl;
	}

	return 0;
}
