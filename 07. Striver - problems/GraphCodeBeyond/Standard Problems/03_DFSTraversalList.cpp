#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(vector<vector<int>>& adjList, int n, int i, vector<bool>& visited, vector<int>& ans) {
	ans.push_back(i);
	visited[i] = true;
	for(int j=0; j<adjList[i].size(); j++) {
		if(!visited[adjList[i][j]]) {
			dfsTraversal(adjList, n, adjList[i][j], visited, ans);
		}
	}
	return;
}

vector<int> dfs(vector<vector<int>>& adjList, int n) {
	vector<bool> visited(n, false);
	vector<int> ans;
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			dfsTraversal(adjList, n, i, visited, ans);
		}
	}
	return ans;
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
	vector<int> ans = dfs(adjList, n);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}