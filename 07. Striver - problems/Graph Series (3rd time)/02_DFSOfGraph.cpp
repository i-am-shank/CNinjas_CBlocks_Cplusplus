#include <bits/stdc++.h>
using namespace std;

class Solution {
	void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<int>& ans) {
		ans.push_back(node);
		for(auto it: adj[node]) {
			if(!visited[it]) {
				visited[it] = true;
				dfs(adj, it, visited, ans);
			}
		}
		return;
	}

public:
	vector<int> dfsOfGraph(int v, vector<vector<int>>& adj) {
		vector<bool> visited(v, false);
		vector<int> ans;
		visited[0] = true;
		dfs(adj, 0, visited, ans);
		return ans;
	}
};

int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s); // f -- s
		adj[s].push_back(f);
	}
	Solution solve;
	vector<int> ans = solve.dfsOfGraph(v, adj);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}