#include <bits/stdc++.h>
using namespace std;

class Solution {
	void bfs(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<int>& ans) {
		queue<int> q;
		q.push(node);
		visited[node] = true;
		while(!q.empty()) {
			int front = q.front();
			q.pop();
			ans.push_back(front);
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
		bfs(adj, 0, visited, ans);
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
	int v;
	cin >> v;
	vector<vector<int>> adj(v, vector<int>());
	for(int i=0; i<v; i++) {
		int m;
		cin >> m;
		for(int j=0; j<m; j++) {
			int ele;
			cin >> ele;
			adj[i].push_back(ele);
		}
	}
	Solution solve;
	vector<int> ans = solve.bfsOfGraph(v, adj);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}