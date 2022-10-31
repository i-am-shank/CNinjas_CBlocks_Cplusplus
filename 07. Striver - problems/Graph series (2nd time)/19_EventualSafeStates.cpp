#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool dfs(vector<vector<int>>& adj, int node, vector<int>& visited, vector<bool>& isSafe) {
		isSafe[node] = false; // While traversing through it
		visited[node] = 2; // Path-visited
		for(auto it: adj[node]) {
			if(visited[it] == 0) {
				visited[it] = 1;
				bool ans = dfs(adj, it, visited, isSafe);
				if(ans == true) {
					// Path through node has cycle
					isSafe[node] = false;
					return true; // cyclic-component
				}
			}
			else if(visited[it] == 2) {
				// node itself is in cycle
				isSafe[node] = false;
				return true; // cycle found
			}
		}
		isSafe[node] = true;
		visited[node] = 1; // Paths having node traversed
		return false; // No cycle found
	}

  public:
    vector<int> eventualSafeNodes(int v, vector<vector<int>> adj) {
        vector<bool> isSafe(v, true); // initially all marked safe
        vector<int> visited(v, 0);
        // 0->unvisited , 1->visited , 2-pathVisited
        for(int i=0; i<v; i++) {
        	if(visited[i] == 0) {
        		visited[i] = 1;
        		bool ans = dfs(adj, i, visited, isSafe);
        	}
        }
        vector<int> safeNodes;
        for(int i=0; i<v; i++) {
        	if(isSafe[i] == true) {
        		safeNodes.push_back(i);
        	}
        }
        return safeNodes;
    }
};

int main() {
	Solution solve;
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s); // f --> s (directed edge)
	}
	vector<int> ans = solve.eventualSafeNodes(v, adj);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}