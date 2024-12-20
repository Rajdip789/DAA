/**
 *	TC - O(V + E) / SC - O(3*V) ~ O(V) 
**/ 

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> bfs(int v, vector<int> adj[]) {
			vector<int> bfs;
			vector<int> vis(v+1, 0);
			
			for(int i = 1; i <= v; i++) {	// need this as graph can have many components 
				if(!vis[i]) {
					
					//BFS Algo start
					queue<int> q;
					q.push(i); 		 		
					
					vis[i] = 1;

					while(!q.empty()) {
						int node = q.front();
						q.pop();
						
						bfs.push_back(node);
						
						for(auto it : adj[node]) {
							if(!vis[it]) {
								q.push(it);
								vis[it] = 1;
							}
						}
					}
				}
			}
			
			return bfs;
		}
};

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> adj[n+1];

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}	

	Solution s1;
	for(int x : s1.bfs(n, adj))
        cout << x <<" ";
        
	return 0;
}


