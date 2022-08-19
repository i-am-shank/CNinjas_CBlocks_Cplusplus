#include <bits/stdc++.h>
using namespace std;

// Time : O(n + (2*e))
// Space : O(2*e)

void bfsTraversal(vector<vector<int>> adjList, int n, vector<bool>& visited, int i) {
	queue<int> q;
	q.push(i);
	visited[i] = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		for(auto it: adjList[front]) {
			if(!visited[it]) {
				q.push(it);
				visited[it] = true;
			}
		}
	}
	cout << endl;
	return;
}

void bfs(vector<vector<int>> adjList, int n) {
	vector<bool> visited(n+1, false);
	for(int i=1; i<=n; i++) {
		if(visited[i] == false) {
			bfsTraversal(adjList, n, visited, i);
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
		// Required only if you want to traverse neighbors in increasing order
		sort(adjList[i].begin(), adjList[i].end());
	}
	bfs(adjList, n);
	return 0;
}