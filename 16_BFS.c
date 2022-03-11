//Time complexity will be O(N+E) and Space complexity will be O(N+E) + O(N) + O(N)                    
#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		vector<int> bfsOfGraph(int v, vector<int> adj[]){
			vector<int> bfs;
			vector<int> vis(v+1,0);
			
			for(int i=1;i<=v;i++){
				if(!vis[i]){
					
					//BFS Algo start
					queue<int> q;
					q.push(i);
					vis[i] = 1;
					while(!q.empty()){
						int node = q.front();
						q.pop();
						bfs.push_back(node);
						
						for(auto it : adj[node]){
							if(!vis[it]){
								q.push(it);
								vis[it] = 1;
							}
						}
					}
				}
			}
			
			return bfs;
		}
};

int main(){
	int n,m;
	cin >> n >> m;
	
	//vector<pair<int,int>> adj[n+1];    //add this for weighted graph
	vector<int> adj[n+1];
	for(int i =0;i<m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); //ommit this line in case of a directed graph
	}	

	Solution s1;
	for(int x : s1.bfsOfGraph(n,adj))
        cout<<x<<" ";
        
	return 0;
}


