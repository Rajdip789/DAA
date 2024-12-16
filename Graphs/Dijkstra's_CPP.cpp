#include<bits/stdc++.h>
using namespace std;

class Dijkstra {
	public:
	    vector<int> shortestPath(int n, int source, int dest, vector<vector<int>> &edges) {
	        vector<pair<int, int>> adj[n+1];
	        
	        for (auto it : edges) {
	            adj[it[0]].push_back({it[1], it[2]});
	            adj[it[1]].push_back({it[0], it[2]});
	        }
	
			/***
				Dijskstra's stars here
			***/
	        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	        vector<int> dist(n+1, 1e9), parent(n+1);
	        
	        for(int i = 0; i < n; i++)	parent[i] = i;
	        dist[source] = 0;
	        
			pq.push({0, source}); //{distance, node}
	        
	        while(!pq.empty()) {   
	            int node = pq.top().second;
	            int dis = pq.top().first; //1
				pq.pop();
				
	            for(auto it : adj[node]) {
	                int adjNode = it.first;
	                int adjDist = it.second;  //2
	
	                if(dis + adjDist < dist[adjNode]) {
	                    dist[adjNode] = dis + adjDist;
	                    pq.push({dis + adjDist, adjNode});
	
	                    parent[adjNode] = node;
	                }
	            }
	        }
	
			/***
				Dijskstra's ends here
			***/
			
			//distance of every vertex from source node
			for (int i = 0; i < n; i++) {
		        cout << dist[i] << " ";
		    }
		    cout << endl;
			

			/*Computation for finding path from source to destination*/
	        if (dist[dest] == 1e9)
	            return {-1};
	
	        vector<int> path;
	        while (parent[dest] != dest) {
	            path.push_back(dest);
	            dest = parent[dest];
	        }
	        
	        reverse(path.begin(), path.end());
	        return path;
	    }
};

int main() {
	int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {1, 4, 5}, {1, 2, 4}, {0, 3, 1}, {3, 2, 3}, {2, 4, 1}};
    
	Dijkstra dj;
    vector<int> path = dj.shortestPath(V, 0, 4, edges);   //(vertex, source, destination, edges)

	/*path from source to destination*/
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    
    return 0;
}
