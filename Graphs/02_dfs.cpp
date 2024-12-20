/**
 *	TC - O(V + E) / SC - O(3*V) ~ O(V) 
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
		storeDfs.push_back(node);
		vis[node] = 1;
		
		for(auto it : adj[node]) {
			if(!vis[it]) {
				dfs(it, vis, adj, storeDfs);
			}
		}
	}
	public:
		vector<int> dfsOfGraph(int v, vector<int> adj[]) {
			vector<int> storeDfs;
			vector<int> vis(v+1,0);
			
			for(int i = 1; i <= v; i++) {
				if(!vis[i]) {
					dfs(i, vis, adj, storeDfs);
				}
			}

			return storeDfs;
		}
};

int main() {
	int n, m;
	cout << "Enter the no of vertex and edges: ";
	cin >> n >> m;
	
	vector<int> adj[n+1];
	
	cout << "Enter the edge details:" << endl;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}	

	Solution s1;
	for(int x : s1.dfsOfGraph(n, adj))
        cout << x << " ";
        
	return 0;
}


