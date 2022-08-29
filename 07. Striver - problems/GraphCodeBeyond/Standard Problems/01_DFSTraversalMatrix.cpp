#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(vector<vector<int>>& adjMatrix, int i, int n, vector<int>& ans, vector<bool>& visited) {
	ans.push_back(i);
	visited[i] = true;
	for(int j=0; j<n; j++) {
		if(adjMatrix[i][j]==1 && !visited[j]) {
			dfsTraversal(adjMatrix, j, n, ans, visited);
		}
	}
	return;
}

vector<int> dfs(vector<vector<int>>& adjMatrix, int n) {
	vector<bool> visited(n, false);
	vector<int> ans;
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			dfsTraversal(adjMatrix, i, n, ans, visited);
		}
	}
	return ans;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjMatrix[f][s] = 1;
		adjMatrix[s][f] = 1;
	}
	vector<int> ans = dfs(adjMatrix, n);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}