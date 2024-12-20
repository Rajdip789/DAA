/**
 *	TC - O(V + E) / SC - O(2V) + O(V) ~ O(V) 
**/ 

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool checkForCycle(int node, vector<int> &vis, vector<int> adj[]) {
			vis[node] = 1;

			for(auto it : adj[node]) {
				if(!vis[it]) {
					if(checkForCycle(it, vis, adj)) {
						return true;
					}
				} else if(vis[it] == 1) 
					return true;
			}

			vis[node] = 2;
			
			return false;
		}
		
		bool isCycle(int v, vector<int> adj[]) {
			vector<int> vis(v, 0);

			for(int i = 0; i < v; i++) {
				if(!vis[i]) {
					if(checkForCycle(i, vis, adj))
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
	}	

	Solution s1;
	if(s1.isCycle(n, adj))
		cout << "Cycle found";
	else
		cout << "No cycle found";
        
	return 0;
}
