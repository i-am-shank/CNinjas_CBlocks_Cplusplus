#include <bits/stdc++.h>
using namespace std;

// Time : O(n + (2*e))
// Space : O(2*e)

void dfsTraversal(vector<vector<int>> adjList, int n, vector<bool>& visited, int i) {
	cout << i << " ";
	visited[i] = true;
	for(auto it: adjList[i]) {
		if(!visited[it]) {
			dfsTraversal(adjList, n, visited, it);
		}
	}
	return;
}

void dfs(vector<vector<int>> adjList, int n) {
	vector<bool> visited(n+1, false);
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			dfsTraversal(adjList, n, visited, i);
		}
	}
	return;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n+1, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s);
		adjList[s].push_back(f);
	}
	for(int i=1; i<=n; i++) {
		sort(adjList[i].begin(), adjList[i].end());
		// Only if neighbors are required in ascending order
	}
	dfs(adjList, n);
	return 0;
}