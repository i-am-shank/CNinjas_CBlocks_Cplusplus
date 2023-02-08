#include <bits/stdc++.h>
using namespace std;

class Solution {
	void bfs(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<int>& ans) {
		queue<int> q;
		q.push(node);
		visited[node] = true;
		while(!q.empty()) {
			int front = q.front();
			ans.push_back(front);
			q.pop();
			for(auto it: adj[front]) {
				if(!visited[it]) {
					visited[it] = true;
					q.push(it);
				}
			}
		}
		return;
	}

public:
	vector<int> bfsOfGraph(int v, vector<vector<int>> adj) {
		vector<int> ans;
		vector<bool> visited(v, false);
		for(int i=0; i<v; i++) {
			if(!visited[i]) {
				visited[i] = true;
				bfs(adj, i, visited, ans);
			}
		}
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
		adj[f].push_back(s); // f --> s
	}
	Solution solve;
	vector<int> ans = solve.bfsOfGraph(v, adj);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}