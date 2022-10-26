#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

class Solution {
	// Time : O(n+(2*e)) + O(n)
	// ..   overall-dfs    outer-loop
	// Space : O(n)
	bool dfs(vector<vector<int>>& adjList, int node, int parent, vector<bool>& visited) {
		for(auto it: adjList[node]) {
			if(!visited[it]) {
				visited[it] = true;
				bool ans = dfs(adjList, it, node, visited);
				if(ans == true) {
					return true;
				}
			}
			else {
				// Visited already
				if(it != node) { // & isn't the parent
					return true; // Visited by any other path
					// Cycle !!!!
				}
			}
		}
		return false;
	}

	bool bfs(vector<vector<int>>& adjList, int node, int parent, vector<bool>& visited) {
		queue<pp> q;
		q.push(make_pair(node, parent));
		visited[node] = true;
		while(!q.empty()) {
			pp front = q.front();
			q.pop();
			int n1=front.first, p1=front.second;
			for(auto it: adjList[n1]) {
				if(!visited[it]) {
					visited[it] = true;
					q.push(make_pair(it, n1));
				}
				else {
					// Visited already
					if(it != p1) { // & isn't the parent
						return true; // Visited by any other path
						// Cycle !!!!
					}
				}
			}
		}
		return false;
	}

public:
	bool isCycle(int n, vector<vector<int>>& adjList) {
		vector<bool> visited(n, false);
		for(int i=0; i<n; i++) {
			if(!visited[i]) {
				// bool ans = bfs(adjList, i, -1, visited);
				visited[i] = true;
				bool ans = dfs(adjList, i, -1, visited);
				if(ans == true) {
					return true; // If 1-component has cycle
					// --> Graph has cycle !
				}
			}
		}
		return false;
	}
};

int main() {
	Solution solve;
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s);
		adjList[s].push_back(f);
	}
	bool ans = solve.isCycle(n, adjList);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}