#include <iostream>
#include <vector>
using namespace std;

/***
	TC - O(4a) / SC - O(N)
***/

class DisjointSet {
    vector<int> parent, rank;
    
    public:
		DisjointSet(int n) {
        	parent.resize(n+1,0);
        	rank.resize(n+1,0);
        
	        for(int i = 0; i < n; i++) {
	            parent[i] = i;
	            rank[i] = 1;
	        }
	    }
    
	    int findUParent(int node) {
	        if(node == parent[node])
	            return node;
	        return parent[node] = findUParent(parent[node]);
	    }
	    
	    void unionByRank(int u, int v) {
	        int uparentU = findUParent(u);
	        int uparentV = findUParent(v);
	        
	        if(rank[uparentU] > rank[uparentV]) {
	            parent[uparentV] = uparentU;
	
	        } else if(rank[uparentU] < rank[uparentV]){
	            parent[uparentU] = uparentV;
	
	        } else {
	            parent[uparentU] = uparentV;
	            rank[uparentV]++;
	        }       
	    }
};

int main() {
	DisjointSet dsu(6);
	
    dsu.unionByRank(0, 5);
    dsu.unionByRank(4, 2);
    dsu.unionByRank(2, 1);
   
    (dsu.findUParent(5) == dsu.findUParent(1)) ? cout << "True\n" : cout << "False\n";
    (dsu.findUParent(2) == dsu.findUParent(4)) ? cout << "True\n" : cout << "False\n";
    (dsu.findUParent(1) == dsu.findUParent(4)) ? cout << "True\n" : cout << "False\n";

	return 0;
}
