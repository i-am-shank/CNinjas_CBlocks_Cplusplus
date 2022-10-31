#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool dfs(vector<vector<int>>& graph, int node, vector<int>& visited, vector<bool>& safeSet) {
		visited[node] = 2; // same-path
		safeSet[node] = false; // Till traversed paths having node
		// node is in danger-zone.. don't know where cycle will be found
		// Marked not-safe  -->  false
		for(auto it: graph[node]) {
			if(visited[it] == 0) {
				// Not-visited
				visited[it] = 1;
				bool ans = dfs(graph, it, visited, safeSet);
				if(ans == true) {
					// Path from node .. adj[node] has cycle
					safeSet[node] = false; // node isn't safe
					return true;
				}
			}
			else if(visited[it] == 2) {
				// Cycle found
				safeSet[node] = false; // node is itself in cycle
				return true; // node isn't safe
			}
		}
		visited[node] = 1; // Paths having current node traversed
		safeSet[node] = true;
		return false; // Just dummy boolean value (of no use)
	}

public:
	// Safe-nodes -> All nodes, that aren't part of any path with cycle

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> safeSet(n, true);
        vector<int> visited(n, 0);
        // 0 -> not-visited
        // 1 -> visited
        // 2 -> visited & same-path
        for(int i=0; i<n; i++) {
        	if(visited[i] == 0) {
        		visited[i] = 1;
        		bool ans = dfs(graph, i, visited, safeSet);
        	}
        }
        vector<int> safeNodes;
        for(int i=0; i<n; i++) {
        	if(safeSet[i] == true) {
        		safeNodes.push_back(i);
        	}
        }
        return safeNodes;
    }
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>());
	for(int i=0; i<n; i++) {
		int m;
		cin >> m;
		for(int j=0; j<m; j++) {
			int x;
			cin >> x;
			graph[i].push_back(x);
		}
	}
	Solution solve;
	vector<int> ans = solve.eventualSafeNodes(graph);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}