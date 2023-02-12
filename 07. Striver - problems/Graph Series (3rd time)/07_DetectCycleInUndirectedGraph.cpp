#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

class Solution {
	bool bfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
		queue<pp> q;
		q.push(mp(node,-1)); // As -1 is no-node
		// Parent of starting node of a component is -1.
		visited[node] = true;
		while(!q.empty()) {
			pp front = q.front();
			q.pop();
			int x1=front.fi, p1=front.se;
			for(auto it: adj[x1]) {
				if(!visited[it]) {
					visited[it] = true;
					q.push(mp(it,x1)); // node-parent
				}
				else {
					if(it != p1) {
						// Visited node isn't parent of node
						// So, must be visited by any other path
						// Cycle exists
						return true;
					}
				}
			}
		}
		return false; // If cycle not found till here --> false
	}

public:
	bool isCycle(int v, vector<vector<int>> adj) {
		queue<pp> q;
		vector<bool> visited(v, false);
		for(int i=0; i<v; i++) {
			if(!visited[i]) {
				bool smallAns = bfs(adj, i, visited);
				if(smallAns == true) {
					// Cycle found in sub-graph
					return true;
				}
			}
		}
		return false;
	}
};

int main() {
	int v, e;
	cin >> v >> e;
	vector<pp> edges(e);
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		edges[i] = mp(f,s); // f -- s
	}
	vector<vector<int>> adj(v, vector<int>());
	for(int i=0; i<e; i++) {
		pp curr = edges[i];
		int f=curr.fi, s=curr.se;
		adj[f].push_back(s);
		adj[s].push_back(f); // f -- s
	}
	Solution solve;
	bool ans = solve.isCycle(v, adj);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}