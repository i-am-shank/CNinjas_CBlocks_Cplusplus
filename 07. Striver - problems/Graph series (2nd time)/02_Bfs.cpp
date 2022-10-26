#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adjList, int node, int n, vector<bool>& visited) {
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		for(int i=0; i<adjList[front].size(); i++) {
			if(!visited[adjList[front][i]]) {
				visited[adjList[front][i]] = true;
				q.push(adjList[front][i]);
			}
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
		// as undirected graph
	}
	vector<bool> visited(n+1, false);
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			bfs(adjList, i, n, visited);
		}
	}
	cout << "\n";
	return 0;
}