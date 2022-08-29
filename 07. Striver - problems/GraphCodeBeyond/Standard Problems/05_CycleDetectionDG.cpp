#include <bits/stdc++.h>
using namespace std;

// BFS will not work in this case
bool isCycleDfs(vector<vector<int>>& adjList, int n, int i, vector<bool>& visited, vector<bool>& visited2) {
	visited[i] = true;
	visited2[i] = true; // Explore paths emerging from i (till depth .. dfs)
	for(int j=0; j<adjList[i].size(); j++) {
		if(!visited[adjList[i][j]]) {
			bool smallAns = isCycleDfs(adjList, n, adjList[i][j], visited, visited2);
			if(smallAns == true) {
				return true; // Component detected cycle
			}
		}
		else if(visited2[adjList[i][j]]) {
			// Visited .. And also by same-path (traveled cycle .. came back to origin)
			return true; // Detected cycle
		}
	}
	visited2[i] = false; // Other paths.. will not have i as member
	return false;
}

bool isCyclic(vector<vector<int>>& adjList, int n) {
	vector<bool> visited(n, false); // check if visited
	vector<bool> visited2(n, false); // check if same path
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			bool smallAns = isCycleDfs(adjList, n, i, visited, visited2);
			if(smallAns == true) {
				return true;
			}
		}
	}
	return false; // No component has cycle
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s); // f --> s
	}
	bool ans = isCyclic(adjList, n);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}