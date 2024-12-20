/**
 *	Cycle detection in directed graph using Kahn's alogrithm
 *	TC - O(N + E) / SC - O(N)
**/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isCycle(int N, vector<int> adj[]) {
			queue<int> q;
			vector<int> indegree(N,0);
			
			for(int i = 0; i < N; i++) {
				for(auto it : adj[i]) {
					indegree[it]++;
				}
			}
			
			for(int i = 0; i < N; i++) {
				if(indegree[i] == 0) {
					q.push(i);
				}
			}

            int count = 0;

			while(!q.empty()) {
				int node = q.front();
				q.pop();
				
				count++;
				
				for(auto it : adj[node]) {
					indegree[it]--;

					if(indegree[it] == 0) {
						q.push(it);	
					}
				}
			}

            if(count == N) return false;

			return true;	
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
