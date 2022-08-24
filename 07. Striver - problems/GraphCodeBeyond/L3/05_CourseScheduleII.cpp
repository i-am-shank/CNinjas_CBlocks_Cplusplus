#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool dfs(vector<vector<int>>& adjList, int i, vector<bool>& visited, vector<bool>& visited2) {
		visited[i] = true;
		visited2[i] = true;
		for(auto it: adjList[i]) {
			if(!visited[it]) {
				bool smallAns = dfs(adjList, it, visited, visited2);
				if(smallAns == true) { // If anyone finds cycle
					return true; // Its a cyclic graph
				}
			}
			else {
				if(visited2[it] == true) {
					// Same path .. visited by some other way
					return true; // Cycle found
				}
			}
		}
		visited2[i] = false; // For exploring other paths (not having i included)
		return false; // No cycle found
	}

	bool canFinish(vector<vector<int>>& adjList, int n) {
		// Detect cycle in directed graph
		// If Cyclic  ->  can't finish
		vector<bool> visited(n, false); // check if visited
		vector<bool> visited2(n, false); // check if same path
		for(int i=0; i<n; i++) {
			if(!visited[i]) {
				bool smallAns = dfs(adjList, i, visited, visited2);
				if(smallAns == true) { // Cycle found
					return false; // return false
				}
			}
		}
		return true; // No cycle found
	}

	vector<int> topoSort(vector<vector<int>>& adjList, int n) {
		vector<int> inDegree(n, 0);
		for(int i=0; i<n; i++) {
			for(auto it: adjList[i]) {
				// i  -->  it
				inDegree[it]++;
			}
		}
		// InDegrees found
		queue<int> q;
		vector<int> ans;
		for(int i=0; i<n; i++) {
			if(inDegree[i] == 0) {
				q.push(i);
			}
		}
		while(!q.empty()) {
			int front = q.front();
			ans.push_back(front); // Toposort creation
			q.pop();
			for(auto it: adjList[front]) {
				inDegree[it]--;
				if(inDegree[it] == 0) {
					q.push(it);
				}
			}
		}
		return ans;
	}

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<vector<int>> adjList(numCourses, vector<int>());
    	int n = prerequisites.size();
    	for(int i=0; i<n; i++) {
    		int f = prerequisites[i][0], s=prerequisites[i][1];
    		// For f, first do s   ..    s --> f
    		adjList[s].push_back(f);
    	}
        bool ans = canFinish(adjList, numCourses);
        if(ans == false) {
        	vector<int> arr;
        	return arr;
        }
        else {
        	vector<int> arr = topoSort(adjList, numCourses);
        	return arr;
        }
    }
};

int main() {
	int numCourses, n;
	cin >> numCourses >> n;
	Solution solve;
	vector<vector<int>> prerequisites(n, vector<int>(2,0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<2; j++) {
			cin >> prerequisites[i][j];
		}
	}
	vector<int> ans = solve.findOrder(numCourses, prerequisites);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}