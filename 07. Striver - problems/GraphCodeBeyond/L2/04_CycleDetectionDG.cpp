#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adjList, int i, vector<bool>& visited1, vector<bool>& visited2) {
	visited1[i] = true;
	visited2[i] = true;
	for(auto it: adjList[i]) {
		if(!visited1[it]) {
			bool smallAns = dfs(adjList, it, visited1, visited2);
			if(smallAns == true) {
				return true;
			}
		}
		else if(visited2[it]) {
			// Visited during current path only
			return true;
		}
	}
	visited2[i] = false; // Backtrack to explore other paths
	// As i will not be part of other paths.. mark visited2 false
	return false;
}

bool isCycleDFS(vector<vector<int>>& adjList, int n) {
	vector<bool> visited1(n+1, false);
	vector<bool> visited2(n+1, false);
	// visited1 -> checks if visited
	// visited2 -> checks if visited during current path
	for(int i=1; i<=n; i++) {
		if(!visited1[i]) {
			bool smallAns = dfs(adjList, i, visited1, visited2);
			if(smallAns == true) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n+1, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s; //  f --> s
		cin >> f >> s;
		adjList[f].push_back(s);
		// Don't mark vice versa
	}
	bool ans1 = isCycleDFS(adjList, n);
	cout << (ans1==true ? "true" : "false") << endl;
	return 0;
}