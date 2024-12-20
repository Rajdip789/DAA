/*
*	Shortest distance in a non-weighted undirected graph (considering 1 as weight for every node)
*	TC - O(V + E) / SC - O(V)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void findShortestDis(int source, vector<int> &dist, vector<int> adj[]) {
			queue<int> q;
			q.push(source);
			
			dist[source] = 0;
			
			while(!q.empty()) {
				int node = q.front();
				q.pop();

				for(auto it: adj[node]) {
					if(dist[it] > dist[node] + 1) {
						dist[it] = dist[node] + 1;
						q.push(it);	
					}
				}
			}
		}		
};

int main() {
	int n, m, source;
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

	cout << "Enter the source: ";
	cin >> source;

	vector<int> distance(n, INT_MAX);
	
	Solution s1;
	s1.findShortestDis(source, distance, adj);
	
	for(auto it: distance)
		cout << it << " ";
        
	return 0;
}
