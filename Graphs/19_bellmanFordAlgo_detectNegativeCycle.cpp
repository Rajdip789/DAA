#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

struct node{
	int u, v, wt;
	node(int first, int second, int weight){
		u=first;
		v=second;
		wt=weight;
	}
};

bool bellmanFord(int src, int n, vector<int> &dist, vector<node> edges){
	dist[src]=0;
	for(int i=0;i<n-1;i++){
		for(auto it:edges){
			if(dist[it.u] + it.wt < dist[it.v]){
				dist[it.v] = dist[it.u] + it.wt;
			}
		}
	}
	
	for(auto it: edges){
		if(dist[it.u] + it.wt < dist[it.v]){
			return false;
		}
	}
	
	return true;
}

int main(){
	int n,m;
	cout<<"Enter the no of vertex and edges: ";
	cin >> n >> m;
	
	vector<node> edges;
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u >> v >> wt;
		edges.push_back(node(u,v,wt));
	}
	
	int src;
	cin>> src;
	
	vector<int> dist(n,INF);
	
	if(bellmanFord(src,n,dist,edges)){
		for(int i=0;i<n;i++){
			cout<<0<<"-->"<<i<<" "<<dist[i]<<endl;
		}
	}
	else
		cout<<"Negative cycle found";	
        
	return 0;
}
