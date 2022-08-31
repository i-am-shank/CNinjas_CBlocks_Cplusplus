#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, int node, int par, vector<bool>& visited, int& timer, vector<int>& tin, vector<int>& low) {
	timer++;
	visited[node] = true;
	tin[node] = timer;
	low[node] = timer;
	for(auto adjNode: adjList[node]) {
		if(adjNode == par) {
			continue;
		}
		else {
			if(!visited[adjNode]) {
				dfs(adjList, adjNode, node, visited, timer, tin, low);
				low[node] = min(low[node], low[adjNode]);
				if(low[adjNode] > tin[node]) {
					// Can never reach back (if edge removed)
					// As it hasn't got any other path, with lower timer
					// Bridge !!
					cout << adjNode << " -> " << node << endl;
				}
			}
			else { // Already visited
				low[node] = min(low[node], low[adjNode]);
			}
		}
	}
	return;
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
	vector<int> tin(n, INT_MAX), low(n, INT_MAX);
	int timer = 0;
	vector<bool> visited(n, false);
	for(int i=0; i<n; i++) {
		dfs(adjList, i, -1, visited, timer, tin, low);
		// Default parent -> -1
	}
	return 0;
}