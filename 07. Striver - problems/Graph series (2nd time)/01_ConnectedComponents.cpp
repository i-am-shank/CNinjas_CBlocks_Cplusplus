#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjMatrix, int i, int n, vector<bool>& visited) {
	for(int j=1; j<=n; j++) {
		if(j!=i && !visited[j] && adjMatrix[i][j]==1) {
			// unvisited neighbour
			visited[j] = true;
			dfs(adjMatrix, j, n, visited);
		}
	}
	return;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjMatrix(n+1, vector<int>(n+1,0));
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjMatrix[f][s] = 1;
		adjMatrix[s][f] = 1;
	}
	vector<bool> visited(n+1, false);
	int count = 0;
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			count++; // 1-new component
			visited[i] = true;
			dfs(adjMatrix, i, n, visited);
		}
	}
	cout << count << "\n";
	return 0;
}