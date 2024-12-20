/**
 *	TC - O(V + E) / SC - O(V) 
**/ 

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
			vis[node] = 1;

			for(auto it : adj[node]) {
				if(!vis[it]) {
					if(checkForCycle(it, node, vis, adj)) 
						return true;
				}
				else if(it != parent)
					return true;
			}

			return false;
		}
		
		bool isCycle(int v, vector<int> adj[]) {
			vector<int> vis(v+1, 0);

			for(int i = 1; i <= v; i++) {
				if(!vis[i]) {
					if(checkForCycle(i, -1, vis, adj))
						return true;
				}
			}

			return false;
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
		adj[v].push_back(u);	
	}	

	Solution s1;
	if(s1.isCycle(n,adj))
		cout << "Cycle found";
	else
		cout << "No cycle found";
        
	return 0;
}


