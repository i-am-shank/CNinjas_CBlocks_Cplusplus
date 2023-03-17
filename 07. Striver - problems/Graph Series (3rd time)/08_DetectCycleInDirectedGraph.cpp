#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Time : O(N + 2E)  ..  graph-traversal
	//     nodes  &  edges (2 times each)
	// Space : O(N) + O(2*N)   .. 1st O(N) recursion-stack
	//   ..  : O(N) + O(N)   .. for 1-visited array

	bool dfs2(vector<vector<int>>& adjList, int node, vector<bool>& visited, vector<bool>& pathVisit) {
		pathVisit[node] = true;
		for(auto it: adjList[node]) {
			if(!visited[it]) {
				visited[it] = true;
				bool check = dfs2(adjList, it, visited, pathVisit);
				if(check == true) {
					return true;
				}
			}
			else if(pathVisit[it]) {
				// visited in same path
				// --> Cycle found
				return true;
			}
		}
		pathVisit[node] = false; // all paths traversed
		return false; // No cycle found
	}

public:
	// Using 2-visited arrays (visited, pathVisit)
	bool isCyclic2(int n, vector<vector<int>>& adjList) {
        vector<bool> visited(n, false);
        vector<bool> pathVisit(n, false);
        for(int i=0; i<n; i++) {
        	if(!visited[i]) {
        		visited[i] = true;
        		bool check = dfs2(adjList, i, visited, pathVisit);
        		if(check == true) {
        			return true;
        		}
        	}
        }
        return false; // No cycle found in graph
    }

    // Using 1-visited array
    bool dfs(vector<vector<int>>& adjList, int node, vector<int>& visited) {
    	visited[node] = 2; // path-visited
    	for(auto it: adjList[node]) {
    		if(visited[it] == 0) {
    			// not visited
    			visited[it] = true;
    			bool check = dfs(adjList, it, visited);
    			if(check == true) {
    				return true;
    			}
    		}
    		else if(visited[it] == 2) {
    			// Already Path-visited
    			return true; // cycle found
    		}
    	}
    	visited[node] = 1; // All paths traversed
    	return false;
    }

    bool isCyclic(int n, vector<vector<int>>& adjList) {
    	vector<int> visited(n, 0);
    	// visited[i] = 0  -->  Not-visited
    	//            = 1  -->  Visited
    	//            = 2  -->  Path-visited
    	for(int i=0; i<n; i++) {
    		if(visited[i] == 0) {
    			visited[i] = 1;
    			bool check = dfs(adjList, i, visited);
    			if(check == true) {
    				return true;
    			}
    		}
    	}
    	return false; // No cycle found
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<n; i++) {
		int m;
		cin >> m;
		for(int j=0; j<m; j++) {
			int ele;
			cin >> ele;
			adjList[i].push_back(ele);
		}
	}
	bool ans = solve.isCyclic(n, adjList);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}