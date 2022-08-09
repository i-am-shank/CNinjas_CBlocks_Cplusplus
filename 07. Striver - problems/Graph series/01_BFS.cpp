#include <bits/stdc++.h>
using namespace std;

// Using Adjacency list
// Time : O(n) + O(e) .. For each node, traversing all its edges
// Space : O(e)  ..  almost O(2*e)
//   .. in Adjacency matrix  O(n^2) space is required

void bfs(vector<vector<int>>& adjList, int n, vector<bool>& visited, int i) {
	visited[i] = true;
	queue<int> q;
	q.push(i);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		vector<int> neighbors = adjList[front];
		for(int j=0; j<neighbors.size(); j++) {
			if(visited[neighbors[j]] == false) {
				q.push(neighbors[j]);
				visited[neighbors[j]] = true;
			}
		}
	}
	return;
}

void bfsTraversal(vector<vector<int>> adjList, int n) {
	vector<bool> visited(n+1, false);
	for(int i=0; i<n; i++) {
		if(visited[i] == false) {
			bfs(adjList, n, visited, i);
		}
	}
	cout << endl;
	return;
}

// For adjacency list preparation  
//     ->  Time : O((e^2) * loge)
// All edges traversed .. and also sorted

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n,vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s);
		adjList[s].push_back(f);
	}
	for(int i=0; i<n; i++) { // Neighbors-list sorted
		sort(adjList[i].begin(), adjList[i].end());
	}
	bfsTraversal(adjList, n);
	return 0;
}