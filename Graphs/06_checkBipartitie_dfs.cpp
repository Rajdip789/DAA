 /**
  * TC - O(V + E) / SC - (V)
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool bipartiteDfs(int node, vector<int> &color, vector<int> adj[]) {
			if(color[node] == -1) color[node] = 1;  // Executed only first time when dfs called

            for(auto it : adj[node]) {
                if(color[it] == -1) {
                    color[it] = 1 - color[node];    // assign alternate colors

                    if(!bipartiteDfs(it, color, adj)) {
                        return false;
                    }
                } else if(color[it] == color[node]) 
                    return false;
            }

			return true;
		}
		
		bool isBipartite(int v, vector<int> adj[]) {
			vector<int> color(v,-1);

			for(int i = 0; i < v; i++) {
				if(color[i] == -1) {
					if(!bipartiteDfs(i, color, adj))
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


