// safe node  -->  Every path ends at terminal node
//    i.e. nodes which aren't connected to any cycle.

#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool dfs(vector<vector<int>>& adjList, int node, vector<int>& visited, vector<bool>& isSafe) {
		visited[node] = 2;
		for(auto it: adjList[node]) {
			if(visited[it] == 0) {
				visited[it] = 1;
				bool check = dfs(adjList, it, visited, isSafe);
				if(check == true) {
					// cycle found
					return true;
				}
			}
			else if(visited[it] == 2) {
				// Already path-visited
				return true;
			}
		}
		isSafe[node] = true; // only reaches here for false
		visited[node] = 1;
		return false;
	}

  public:
  	// Time : O(N+2E) .. traverse whole graph
  	// Space : O(N) .. isSafe-aray + Visited
    vector<int> eventualSafeNodes(int n, vector<vector<int>> adjList) {
        vector<int> visited(n, 0);
        vector<bool> isSafe(n, false);
        for(int i=0; i<n; i++) {
        	if(visited[i] == 0) {
        		visited[i] = 1;
        		bool check = dfs(adjList, i, visited, isSafe);
        		// If cycle found, still traverse other components
        	}
        }
        vector<int> ans;
        for(int i=0; i<n; i++) {
        	if(isSafe[i] == true) {
        		ans.push_back(i);
        	}
        }
        return ans;
    }
};

int main() {
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
	Solution solve;
	vector<int> ans = solve.eventualSafeNodes(n, adjList);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}