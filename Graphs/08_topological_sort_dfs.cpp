/**
 *	Topological sort : Linear indexing of vertices such that if there is 
 *	an edge u -> v, u appers before v in that ordering.
 *
 *	TC - O(V + E) / SC - O(V)
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
			vis[node] = 1;

			for(auto it: adj[node]) {
				if(!vis[it])
					dfs(it, st, vis, adj);
			}

			st.push(node);
		}
		
		vector<int> topoSort(int v, vector<int> adj[]) {
			vector<int> vis(v,0);
			vector<int> ans;
			stack<int> st;
			
			for(int i = 0; i < v; i++) {
				if(!vis[i]) {
					dfs(i, st, vis, adj);
				}
			}
			
			while(!st.empty()) { 
				ans.push_back(st.top());
				st.pop();

			}
			return ans;	
		}
};

int main() {
	int n, m;
	cout << "Enter the no of vertex and edges: ";
	cin >> n >> m;
	
	vector<int> adj[n+1];
	
	cout << "Enter the edge details: " << endl;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}	

	Solution s1;
	for(auto it: s1.topoSort(n, adj))	// topological ordering
		cout << it << " ";
        
	return 0;
}
