//Topological sort bfs (Kahn's alogrithm)

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		vector<int> topoSort(int N, vector<int> adj[]) {
			queue<int> q;
			vector<int> ans;
			vector<int> indegree(N,0);
			
			for(int i = 0; i < N; i++){
				for(auto it : adj[i]){
					indegree[it]++;
				}
			}
			
			for(int i = 0; i < N; i++){
				if(indegree[i] == 0){
					q.push(i);
				}
			}
			
			
			while(!q.empty()) {
				int node = q.front();
				q.pop();
				ans.push_back(node);
				for(auto it : adj[node]){
					indegree[it]--;
					if(indegree[it] == 0){
						q.push(it);	
					}
				}
			}
			return ans;	
		}
		
};

int main() {
	int n, m;
	cout << "Enter the no of vertex and edges: ";
	cin >> n >> m;
	
	//vector<pair<int,int>> adj[n+1];    //add this for weighted graph
	vector<int> adj[n+1];
	cout<<"Enter the edge details: "<<endl;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}	

	Solution s1;
	for(auto it: s1.topoSort(n, adj))
		cout<<it<<" ";
        
	return 0;
}
