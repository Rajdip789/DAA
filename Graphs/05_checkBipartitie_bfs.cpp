/**
 * 	A Bipartite graph is a graph whose vertices can be divided into two independent set, 
 * 	U and V such that every edge (u, v) either connects a vertex from U to V or vertex from V to U. 
 * 	i.e. there should be no edge that connects vertices of same set.
 * 	
 * 	A Bipartite graph can be colored using 2 colors such that no two adjacent nodes have same color.
 * 	If a graph has any odd length cycle then it is not bipartite else bipartite (i.e. even length cycle)
 * 	All acyclic graphs are bipartite.
 * 	
 *	TC - O(V + E) / SC - O(V)
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool bipartiteBfs(int src, vector<int> &color, vector<int> adj[]) {
			queue<int> q;
			color[src] = 1;
			q.push(src);
			
			while(!q.empty()) {
				int node = q.front();
				q.pop();
				
				for(auto it : adj[node]) {
					if(color[it] == -1) {
						color[it] = 1-color[node];
						q.push(it);
					} 
					else if(color[it] == color[node]) 
						return false;
				}
			}

			return true;
		}
		
		bool isBipartite(int v, vector<int> adj[]) {
			vector<int> color(v,-1);

			for(int i = 0; i < v; i++) {
				if(color[i] == -1) {
					if(!bipartiteBfs(i, color, adj))
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
	
	vector<int> adj[n];

	cout << "Enter the edge details: " << endl;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	Solution s1;
	if(s1.isBipartite(n, adj))
		cout << "Bipartite";
	else
		cout << "Not Bipartite";
        
	return 0;
}


