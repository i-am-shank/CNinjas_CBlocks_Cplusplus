#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, int n, vector<bool>& visited, int i) {
	cout << i << " ";
	visited[i] = true;
	vector<int> neighbors = adjList[i];
	for(int j=0; j<neighbors.size(); j++) {
		if(visited[neighbors[j]] == false) {
			dfs(adjList, n, visited, neighbors[j]);
		}
	}
	return;
}

void DFSTraversal(vector<vector<int>> adjList, int n) {
	vector<bool> visited(n, false);
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			dfs(adjList, n, visited, i);
		}
	}
	cout << endl;
	return;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s);
		adjList[s].push_back(f);
	}
	for(int i=0; i<n; i++) {
		sort(adjList[i].begin(), adjList[i].end());
	}
	DFSTraversal(adjList, n);
	return 0;
}