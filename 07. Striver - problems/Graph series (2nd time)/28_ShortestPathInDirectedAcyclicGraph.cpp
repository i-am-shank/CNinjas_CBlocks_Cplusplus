#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
#define fi first
#define se second
#define mp make_pair

class Solution {
	// Time : O(n+e)
	void dfs(vector<vector<pp>>& adj, int node, vector<bool>& visited, stack<int>& stk) {
		for(auto it: adj[node]) {
			int n1=it.fi, w1=it.se;
			if(!visited[n1]) {
				visited[n1] = true;
				dfs(adj, n1, visited, stk);
			}
		}
		stk.push(node); // nodes succeeding node already pushded into stack
		return;
	}

public:
	vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<vector<pp>> adj(n, vector<pp>());
        int e=edges.size();
        for(int i=0; i<e; i++) {
        	int f=edges[i][0], s=edges[i][1], w=edges[i][2];
        	adj[f].push_back(mp(s,w)); // f --w--> s
        }
        vector<bool> visited(n, false);
        stack<int> stk;
        for(int i=0; i<n; i++) {
        	if(!visited[i]) {
        		visited[i] = true;
        		dfs(adj, i, visited, stk);
        	}
        }
        // Topological sort stored in stack (reverse order)
        vector<int> dist(n, 1e8);
        dist[0] = 0; // 0 is source node
        // Time : O(n+e)
        while(!stk.empty()) {
        	int top = stk.top();
        	stk.pop();
        	for(auto it: adj[top]) {
        		int n1=it.fi, w1=it.se;
        		int d2 = dist[top]+w1; // dist to n1 from top
        		if(dist[n1] > d2) {
        			dist[n1] = d2;
        		}
        	}
        }
        // Those nodes, which are not reachable..
        // dist is marked 1e8 on them still
        for(int i=0; i<n; i++) {
        	if(dist[i] == 1e8) {
        		dist[i] = -1; // not reachable
        	}
        }
        return dist;
    }
};

int main() {
	int n, m, e;
	cin >> n >> m >> e;
	vector<vector<int>> edges(e, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		vector<int> edge;
		edge.push_back(f);
		edge.push_back(s);
		edge.push_back(w);
		edges[i] = edge;
	}
	Solution solve;
	vector<int> ans = solve.shortestPath(n, m, edges);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}