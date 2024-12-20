/**
 *	TC - O(V + E) / SC - O(V)
**/ 

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool checkForCycle(int i, vector<int> &vis, vector<int> adj[]) {
			queue<pair<int,int>> q;
			
			q.push({i, -1});
			vis[i] = 1;

			while(!q.empty()) {
				int node = q.front().first;
				int parent = q.front().second;
				
				q.pop();
				
				for(auto it : adj[node]) {
					if(!vis[it]) {
						vis[it] = 1;
						q.push({it, node});
					}
					else if(parent != it) 
						return true;
				}
			}

			return false;
		}
		
		bool isCycle(int v, vector<int> adj[]) {
			vector<int> vis(v+1, 0);
			
			for(int i = 1; i <= v; i++) {
				if(!vis[i])
					if(checkForCycle(i, vis, adj))
						return true;
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
	if(s1.isCycle(n, adj))
		cout << "Cycle found";
	else
		cout << "No cycle found";
        
	return 0;
}


