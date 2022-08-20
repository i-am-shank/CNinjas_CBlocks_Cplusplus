#include <bits/stdc++.h>
using namespace std;

// Sending parent of a node.. along with child to DFS from child
// If a non-parent visited neighbour is found
//    -> Means visiting that node from 2-ways
// Surely a cycle present

// Time : O(n + (2*e))
// Space : O(n) + O(n) .. visited-array & queue
bool bfs(vector<vector<int>>& adjList, int i, int p, vector<bool>& visited) {
	queue<pair<int,int>> q;
	q.push(make_pair(i,-1));
	visited[i] = true;
	while(!q.empty()) {
		pair<int,int> front = q.front();
		q.pop();
		int node=front.first, parent=front.second;
		for(auto it: adjList[node]) {
			if(!visited[it]) {
				q.push(make_pair(it,node));
				visited[it] = true;
			}
			else if(it != parent) {
				return true;
			}
		}
	}
	return false;
}

bool hasCycleBFS(vector<vector<int>>& adjList, int n) {
	vector<bool> visited(n+1, false);
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			bool smallAns = bfs(adjList, i, -1, visited);
			if(smallAns == true) {
				return true;
			}
		}
	}
	return false;
}

// Time : O(n + (2*e))  ..  using Adjacency list
// Space : O(n) + O(n)  ..  visited array & recursion stack
bool dfs(vector<vector<int>>& adjList, int i, int p, vector<bool>& visited) {
	visited[i] = true;
	for(int j=0; j<adjList[i].size(); j++) {
		if(!visited[adjList[i][j]]) {
			bool smallAns = dfs(adjList, adjList[i][j], i, visited);
			if(smallAns == true) {
				return true;
			}
		}
		else {
			if(adjList[i][j] != p) {
				return true;
			}
		}
	}
	return false;
}

bool hasCycleDFS(vector<vector<int>>& adjList, int n) {
	vector<bool> visited(n+1, false);
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			bool ans = dfs(adjList, i, 0, visited); // 0 -> parent of default node
			if(ans == true) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n+1, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s);
		adjList[s].push_back(f);
	}
	bool ans = hasCycleDFS(adjList, n);
	bool ans2 = hasCycleBFS(adjList, n);
	cout << (ans==true ? "true" : "false") << endl;
	cout << (ans2==true ? "true" : "false") << endl;
	return 0;
}