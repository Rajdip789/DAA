/**
 *	A spanning tree of a graph is a tree which have N nodes and N-1 edges. And every node is reachable from every other nodes.
 * 	A minimum spanning tree of a graph is the spanning tree for which the sum of all the edge weights is the minimum.
 *	
 *	TC - O(E*logE) + O(E*logE)~ O(E*logE) / SC - O(E) + O(V)
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int spanningTree(int V, vector<pair<int, int>> adj[], vector<pair<int, int>> &mstEdges) {
			vector<bool> vis(V, false);
			
			priority_queue<pair<int, pair<int, int>>, 
			vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
			
			pq.push({0, {0, -1}});	// {weight, {node, parent}} - parent only needed when mst edges are required
			int mstWt = 0;

			while(!pq.empty()) {
				auto it = pq.top();
				pq.pop();

				int parent = it.second.second;
				int node = it.second.first;
				int wt = it.first;

				// If already part of mst then continue;
				if(vis[node]) continue;

				vis[node] = true;	// else add to the mst
				mstWt += wt;

				// If not the root node, add the edge to MST
				if(parent != -1) {
					mstEdges.push_back({node, parent});
				}

				for(auto it : adj[node]) {
					int adjNode = it.first;
					int edgeWeight = it.second;

					if(!vis[adjNode]) {
						pq.push({edgeWeight, {adjNode, node}});
					}
				}
			}

			return mstWt;
		}
};

int main() {
	int n, m;
	cout << "Enter the number of vertices and edges: ";
	cin >> n >> m;
	
	vector<pair<int, int>> adj[n];    // 0-indexed adjacency list for the graph
	
	cout << "Enter the edge details: (v1, v2, weight) " << endl;	
	for(int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}
	
	Solution s1;
	vector<pair<int, int>> mstEdges;	// To store the edges of the MST, no need if only weight wanted
	int mstWeight = s1.spanningTree(n, adj, mstEdges);
	
	cout << "Weight of the MST: " << mstWeight << endl;
	
	cout << "Edges in the MST:" << endl;
	for(auto &edge : mstEdges) {
		cout << edge.first << " - " << edge.second << endl;
	}

	return 0;
}

