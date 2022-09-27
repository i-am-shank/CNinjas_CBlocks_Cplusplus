#include <bits/stdc++.h>
using namespace std;

class hd {
public:
    int height;
    int diameter;
    hd(int hi, int di) {
        height = hi;
        diameter = di;
    }
    hd() {
        // default constructor
    }
};

// instead of updating in every node.. maintain an order date
// keep adding diameter every time in a priority queue.

// 2-DFS approach

// select the root
// Do dfs from that node, & find the deepest node
// Make that deepest node root.
// Do dfs from root, & find the deepest node.
// these 2 are end points of diameter.


// 4 Sum .. store sums (pair) in map
// -> Find 

// Binary lifting
// Find k-th ancestor of any node .. in linear time

// Union find

hd diameter(vector<vector<int>>& adjList, int node, vector<bool>& visited) {
    visited[node] = true;
    if(adjList[node].size() == 1) {
        // Leaf node
        hd ans(1, 1);
        return ans;
    }
    int maxHeight=0, maxDia=0, smaxHeight=0;
    for(auto it: adjList[node]) {
        if(!visited[it]) {
            hd ans1 = diameter(adjList, it, visited);
            int hi=ans1.height, di=ans1.diameter;
            if(hi >= maxHeight) {
                smaxHeight = maxHeight;
                maxHeight = hi;
            }
            else if(hi > smaxHeight) {
                smaxHeight = hi;
            }
            if(di > maxDia) {
                maxDia = di;
            }
        }
    }
    hd ans;
    ans.height = 1 + maxHeight;
    ans.diameter = max(maxDia, (1+maxHeight+smaxHeight));
    return ans;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<bool> visited(n+1, false);
	    vector<vector<int>> adjList(n+1, vector<int>());
	    for(int i=0; i<n; i++) {
	        int u, v;
	        cin >> u >> v;
	        adjList[u].push_back(v);
	        adjList[v].push_back(u);
	    }
	    int ans = diameter(adjList, 1, visited).diameter;
	    cout << ans << "\n";
	}
	return 0;
}
