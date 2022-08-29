#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<vector<int>>& adjMatrix, int i, int n, vector<bool>& visited, vector<int>& ans) {
	queue<int> q;
	q.push(i);
	visited[i] = true;
	while(!q.empty()) {
		int front = q.front();
		ans.push_back(front);
		q.pop();
		for(int j=0; j<n; j++) {
			if(!visited[j] && adjMatrix[front][j]==1) {
				q.push(j);
				visited[j] = true;
			}
		}
	}
	return;
}

vector<int> bfs(vector<vector<int>>& adjMatrix, int n) {
	vector<bool> visited(n, false);
	vector<int> ans;
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			bfsTraversal(adjMatrix, i, n, visited, ans);
		}
	}
	return ans;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjMatrix(n, vector<int>(n,0));
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjMatrix[f][s] = 1;
		adjMatrix[s][f] = 1;
	}
	vector<int> ans = bfs(adjMatrix, n);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}