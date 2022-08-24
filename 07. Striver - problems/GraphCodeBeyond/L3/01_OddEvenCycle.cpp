#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> adjList, int i, int parColor, vector<int>& color) {
	color[i] = (1 ^ parColor); // Reverses (0 -> 1  ..  1 -> 0)
	for(auto it: adjList[i]) {
		if(color[it] == -1) {
			bool smallAns = dfs(adjList, it, color[i], color);
			if(smallAns == false) {
				return false; // Adjacent same color
			}
		}
		else {
			if(color[it] == color[i]) {
				return false; // Adjacent same color (possible only in cycle)
			}
		}
	}
	return true; // pass all same color evaluation
}

bool isEvenCycle(vector<vector<int>> adjList, int n) {
	vector<int> color(n+1,-1);
	for(int i=1; i<=n; i++) {
		if(color[i] == -1) {
			bool smallAns = dfs(adjList, i, 0, color); // Default color = 0
			if(smallAns == false) {
				return false; // adjacent nodes same color
			}
		}
	}
	return true;
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
	// Is Bipartite graph ?
	bool ans = isEvenCycle(adjList, n);
	cout << (ans == true ? "yes" : "no") << endl;
	return 0;
}