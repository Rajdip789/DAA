/**
 *  Kruskal's Alrogithm
 *  TC - O(V + E) + O(E*logE) + O(E*4α*2) / SC - O(V) + O(V) + O(E) ~ O(V)
**/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;
    
    public:
        DisjointSet(int n) {
            parent.resize(n+1);
            size.resize(n+1, 1);
            
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
    
        int getSize(int node) {
            return size[node];
        }
        
        int findUParent(int node) {
            if(parent[node] == node) return node;
            return parent[node] = findUParent(parent[node]);
        }
        
        void unionBySize(int u, int v) {
            int uparentU = findUParent(u);
            int uparentV = findUParent(v);
            
            if(size[uparentU] > size[uparentV]) {
                parent[uparentV] = uparentU;
                size[uparentU] += size[uparentV];
            } else {
                parent[uparentU] = uparentV;
                size[uparentV]+= size[uparentU];
            }       
        }
};

class Solution {
	public:
		int spanningTree(int V, vector<pair<int, int>> adj[], vector<pair<int, int>> &mstEdges) {
			vector<pair<int, pair<int, int>>> edges;

            for(int i = 0; i < V; i++) {
                for(auto it : adj[i]) {
                    int node = i;
                    int wt = it.second;
                    int adjNode = it.first;

                    edges.push_back({wt, {node, adjNode}});
                }
            }

            sort(edges.begin(), edges.end());

            int mstWt = 0;
            DisjointSet dsu(V);
            
            for (auto it : edges) {
                int wt = it.first;
                int u = it.second.first;
                int v = it.second.second;

                if (dsu.findUParent(u) != dsu.findUParent(v)) {
                    mstWt += wt;
                    dsu.unionBySize(u, v);

                    mstEdges.push_back({u, v});
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
	for(int i = 0; i < m; i++) {        // we can also make the edgeList from here
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}
	
	Solution s1;
	vector<pair<int, int>> mstEdges;    // To store the edges of the MST, no need if only weight wanted
	int mstWeight = s1.spanningTree(n, adj, mstEdges);
	
	cout << "Weight of the MST: " << mstWeight << endl;
	
	cout << "Edges in the MST:" << endl;
	for(auto &edge : mstEdges) {
		cout << edge.first << " - " << edge.second << endl;
	}

	return 0;
}