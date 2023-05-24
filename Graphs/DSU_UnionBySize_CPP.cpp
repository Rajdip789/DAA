#include <iostream>
#include <vector>
using namespace std;

/***
	TC - O(4a) / SC - O(N)
***/

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

int main() {
	DisjointSet dsu(6);
	
    dsu.unionBySize(0, 5);
    dsu.unionBySize(4, 2);
    dsu.unionBySize(2, 1);
   
    (dsu.findUParent(5) == dsu.findUParent(1)) ? cout << "True\n" : cout << "False\n";
    (dsu.findUParent(2) == dsu.findUParent(4)) ? cout << "True\n" : cout << "False\n";
    (dsu.findUParent(1) == dsu.findUParent(4)) ? cout << "True\n" : cout << "False\n";

	return 0;
}
