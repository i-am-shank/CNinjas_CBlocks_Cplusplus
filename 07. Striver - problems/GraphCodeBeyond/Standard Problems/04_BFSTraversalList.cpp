#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<vector<int>>& adjList, int i, int n, vector<bool>& visited, vector<int>& ans) {
	queue<int> q;
	q.push(i);
	visited[i] = true;
	while(!q.empty()) {
		int front = q.front();
		ans.push_back(front);
		q.pop();
		for(int j=0; j<adjList[front].size(); j++) {
			if(!visited[adjList[front][j]]) {
				q.push(adjList[front][j]);
				visited[adjList[front][j]] = true;
			}
		}
	}
	return;
}

vector<int> bfs(vector<vector<int>>& adjList, int n) {
	vector<bool> visited(n, false);
	vector<int> ans;
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			bfsTraversal(adjList, i, n, visited, ans);
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
	vector<int> ans = bfs(adjList, n);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}