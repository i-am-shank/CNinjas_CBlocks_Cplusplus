#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

// Time : O(N + 2E) + O(N)  ..  Go to every node, & every edge (2 times)
//     .. Extra O(N) component-loop.
// Space : O(N) + O(N)  ..  Worst case (all N nodes will be in queue)
//     .. queue , visited-array

class Solution {
	bool dfs(vector<vector<int>>& adjList, int node, int parent, vector<bool>& visited) {
		for(auto it: adjList[node]) {
			if(!visited[it]) {
				visited[it] = true;
				bool check = dfs(adjList, it, node, visited);
				if(check == true) {
					// If any cyclic sub-graph
					return true; // graph is cyclic
				}
			}
			else if(it != parent) {
				// cycle found
				return true;
			}
		}
		return false; // If no cycle found
	}

	bool bfs(vector<vector<int>>& adjList, int node, vector<bool>& visited) {
		queue<pp> q;
		q.push(mp(node,-1)); // node, parent
		visited[node] = true;
		while(!q.empty()) {
			pp front = q.front();
			q.pop();
			int n1=front.fi, p1=front.se;
			for(auto it: adjList[n1]) {
				if(!visited[it]) {
					visited[it] = true;
					q.push(mp(it,n1));
				}
				else if(it != p1) {
					// visited & that node isn't parent
					// so, got visited from some other path
					return true; // cycle found
				}
			}
		}
		return false; // no cycle found in current component
	}

public:
	bool isCycle(int n, vector<vector<int>>& adjList) {
		vector<bool> visited(n, false);
		for(int i=0; i<n; i++) {
			if(!visited[i]) {
				// bool check = bfs(adjList, i, visited);
				visited[i] = true;
				bool check2 = dfs(adjList, i, -1, visited);
				if(check2 == true) {
					return true;
				}
			}
		}
		return false; // If no cycle found in whole-graph
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
	bool ans = solve.isCycle(n, adjList);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}