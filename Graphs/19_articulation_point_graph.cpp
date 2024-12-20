/**
 *	Articulation Point - removal of which node in a graph, breaks the graph into multiple components.
 *
 *	TC - O(V + E) / SC - O(3*V)
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int timer = 1;

		void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[], vector<int> &points) {
			vis[node] = 1;
			tin[node] = low[node] = timer++;

            int child = 0;
    
			for(auto it : adj[node]) {
				if (it == parent) continue;

				if(vis[it] == 0) {
					dfs(it, node, vis, tin, low, adj, points);
					
					low[node] = min(low[node], low[it]);

					if (low[it] >= tin[node] && parent != -1) {
                        points.push_back(node);
                    }

                    child++;
				} else {
					low[node] = min(low[node], tin[it]);    // if adjacent is visited, then take tin insted of low
				}
			}

            if (child > 1 && parent == -1) {    // if root has multiple children then its a AP
                points.push_back(node);
            }
		}

	public:
		void articulationPoints(int n, vector<int> adj[], vector<int> &points) {
			vector<int> tin(n, -1);	  // time of insertion
			vector<int> low(n, -1);   // lowest time of insertion
			vector<int> vis(n, 0);

			for(int i = 0 ; i < n; i++) {
				if(!vis[i]) {
					dfs(i, -1, vis, tin, low, adj, points);
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
	vector<int> points;

	s1.articulationPoints(n, adj, points);

	cout << "Articulation points: \n";
	for(auto it : points) {
		cout << it << endl;
	}

	return 0;
}
