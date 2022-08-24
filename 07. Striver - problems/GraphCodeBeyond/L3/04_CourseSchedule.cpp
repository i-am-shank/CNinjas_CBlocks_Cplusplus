#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool bfs(vector<vector<int>>& adjList, int i, vector<bool>& visited, vector<bool>& visited2) {
		queue<int> q;
		q.push(i);
		visited[i] = true;
		visited2[i] = true;
		while(!q.empty()) {
			int front = q.front();
			q.pop();
			for(auto it: adjList[front]) {
				if(!visited[it]) {
					q.push(it);
					visited[it] = true;
                    visited2[it] = true;
				}
				else {
					if(visited2[it]) {
						// Visited during current path
						return true; // Cycle
					}
				}
			}
		}
		visited2[i] = false; // Paths including node (i) traversed
		return false; // No cycle found
	}

	bool dfs(vector<vector<int>>& adjList, int i, vector<bool>& visited, vector<bool>& visited2) {
		visited[i] = true;
		visited2[i] = true;
		for(auto it: adjList[i]) {
			if(!visited[it]) {
				bool smallAns = dfs(adjList, it, visited, visited2);
				if(smallAns == true) {
					return true;
				}
			}
			else {
				if(visited2[it] == true) {
					// Visited during current path
					return true;
				}
			}
		}
		visited2[i] = false; // All paths from i over.
		return false;
	}

	bool isCyclic(vector<vector<int>>& adjList, int n) {
		vector<bool> visited(n, false); // checks if visited
		vector<bool> visited2(n, false); // checks if same-path
		for(int i=0; i<n; i++) {
			if(!visited[i]) {
				// bool ans = dfs(adjList, i, visited, visited2);
				bool ans = bfs(adjList, i, visited, visited2);
				if(ans == true) {
					return true; // Even if 1 cycle found
				}
			}
		}
		return false; // No cycle found
	}

public:
	// Time : O(n + e) .. max. time is of traversal only
	//      -> Adjacency list takes O(e) to create max.
	// Space : O(e + (3*n)) .. AdjList & 2-Visited-arrays & Recursion stack (DFS)
	// Space : O(e + (3*n)) .. AdjList & 2-Visited-arrays & Queue (BFS)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        int n = prerequisites.size();
        for(int i=0; i<n; i++) {
        	int f=prerequisites[i][0], s=prerequisites[i][1];
        	// For taking f, first take s
			// Edge is   :   s --> f
			adjList[s].push_back(f);
        }
        bool ans = isCyclic(adjList, numCourses);
        // If Cyclic -> can't finish
        return (ans == false);
    }
};

int main() {
	Solution solve;
	int numCourses, n;
	cin >> numCourses >> n;
	vector<vector<int>> prerequisites(n, vector<int>());
	for(int i=0; i<n; i++) {
		int f, s;
		cin >> f >> s;
		// For taking f, first take s
		// Edge is   :   s --> f
		prerequisites[i].push_back(f);
		prerequisites[i].push_back(s);
	}
	bool ans = solve.canFinish(numCourses, prerequisites);
	cout << (ans==true ? "true" : "false") << endl;
	return 0;
}