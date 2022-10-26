#include <bits/stdc++.h>
using namespace std;

// Time : O(summation of degree)  =  O(2*e)
// Space : O(n) + O(n) + O(n)
//     .. nodes  visited  rec-stack
void dfs(vector<vector<int>>& adjList, int node, int n, vector<bool>& visited) {
	cout << node << " ";
	for(auto it: adjList[node]) {
		if(!visited[it]) {
			visited[it] = true;
			dfs(adjList, it, n, visited);
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
	vector<bool> visited(n+1, false);
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			visited[i] = true;
			dfs(adjList, i, n, visited);
		}
	}
	cout << "\n";
	return 0;
}