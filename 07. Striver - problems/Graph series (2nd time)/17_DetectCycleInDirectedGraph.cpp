#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Time : O(v+e)
	// Space : O(2*n)
	bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited) {
		pathVisited[node] = true;
		for(auto it: adj[node]) {
			if(!visited[it]) {
				visited[it] = true;
				bool ans = dfs(it, adj, visited, pathVisited);
				if(ans == true) {
					return true;
				}
			}
			else if(pathVisited[it]) {
				// Visited already in current path
				return true;
			}
		}
		pathVisited[node] = false; // Paths having node traversed
		return false;
	}

	bool dfs2(vector<vector<int>>& adj, int node, vector<int>& visited) {
		visited[node] = 2; // Same-path
		for(auto it: adj[node]) {
			if(visited[it] == 0) {
				// Not visited till yet
				visited[it]++;
				bool ans = dfs2(adj, it, visited);
				if(ans == true) {
					return true; // 1-cyclic component
				}
			}
			else if(visited[it] == 2) {
			    // Visited already in same path
			    return true;
			}
		}
		visited[node] = 1; // All paths including node traversed
		return false; // No cycle found
	}

public:
	bool isCycle_1Array(int v, vector<vector<int>>& adj) {
		vector<int> visited(v, 0);
		// 0 -> not-visited , 1 -> visited , 2 -> visited(same path)
		for(int i=0; i<v; i++) {
			if(visited[i] == 0) {
				// Not visited
				visited[i]++;
				bool smallAns = dfs2(adj, i, visited);
				if(smallAns == true) {
					// 1-component cyclic --> Graph cyclic
					return true;
				}
			}
		}
		return false;
	}

	bool isCyclic(int v, vector<vector<int>>& adj) {
        vector<bool> visited(v, false);
		vector<bool> pathVisited(v, false);
		for(int i=0; i<v; i++) {
			if(!visited[i]) {
				visited[i] = true;
				bool smallAns = dfs(i, adj, visited, pathVisited);
				if(smallAns == true) {
					return true; // 1-cycle found
				}
			}
		}
		return false;
    }
};

int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s); // Directed edge  f --> s
	}
	Solution solve;
	// bool ans1 = solve.isCyclic(v, adj);
	bool ans2 = solve.isCycle_1Array(v, adj);
	cout << (ans2 == true ? "true" : "false") << "\n";
	return 0;
}