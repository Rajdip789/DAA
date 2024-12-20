#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
		    vis[node] = 1;

		    for(auto it: adj[node]) {
		        if(!vis[it]) {
		            dfs(it, st, vis, adj);
		        }
		    }

		    st.push(node);
		}
		
		void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
			cout << node << " ";

		    vis[node] = 1;

		    for(auto it : transpose[node]) {
		        if(!vis[it]) {
		            revDfs(it, vis, transpose);
		        }
		    }
		}
	
	public:
	    int kosaraju(int V, vector<int> adj[]) {
	        vector<int> vis(V,0);
	        stack<int> st;

	        for(int i = 0; i < V; i++) {
	            if(!vis[i]) {
	                dfs(i, st, vis, adj);
	            }
	        }
	        
	        vector<int> transpose[V];
	        
	        for(int i = 0; i < V; i++) {
	            vis[i] = 0;	// mark the array unvisited for reuse	

	            for(auto it: adj[i]) {
	                transpose[it].push_back(i);
	            }
	        }
	        
			int count = 0;

	        cout << "SCC's: \n";
	        while(!st.empty()) {
	            int node = st.top();	
	            st.pop();
	            
	            if(!vis[node]) {
					count++;
	                revDfs(node, vis, transpose);
	                cout << endl;
	            }
	        }

			return count;
	    }
};

int main() {
	int n, m;
	cout << "Enter the no of vertex and edges: ";
	cin >> n >> m;
	
	vector<int> adj[n];
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	Solution s1;
	int count = s1.kosaraju(n, adj);

	cout << "No of SCC: " << count;

	return 0;
}
