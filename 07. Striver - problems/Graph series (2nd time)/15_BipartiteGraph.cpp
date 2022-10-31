#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
#define mp make_pair

class Solution {
	bool bfs(vector<vector<int>>& adj, int node, int color, vector<int>& colors) {
		queue<pp> q;
		q.push(mp(node, color));
		colors[node] = color;
		while(!q.empty()) {
			pp front = q.front();
			q.pop();
			int n1=front.first, c1=front.second;
			int c2 = (c1 ^ 1); // flip between 0 & 1
			for(auto it: adj[n1]) {
				if(colors[it] == -1) {
					colors[it] = c2;
					q.push(mp(it,c2));
				}
				else if(colors[it] != c2) {
					// Predicted color != actual color
					return false;
				} 
			}
		}
		return true;
	}

public:
	bool isBipartite(int v, vector<vector<int>>& adj){
	    vector<int> colors(v, -1); // initially -1
	    // .. have to do 0 or 1
	    for(int i=0; i<v; i++) {
	    	if(colors[i] == -1) {
	    		bool smallAns = bfs(adj, i, 0, colors);
	    		// color = 0 & 1
	    		if(smallAns == false) {
	    			return false;
	    		}
	    	}
	    }
	    return true;
	}
};

int main() {
	Solution solve;
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	bool ans = solve.isBipartite(v, adj);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}