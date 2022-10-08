#include <bits/stdc++.h>
using namespace std;

bool detectCycle(vector<vector<int>>& adjList, int src, vector<bool>& visited) {
	queue<pair<int,int>> q;
	q.push(make_pair(src, -1));
	visited[src] = true;
	while(!q.empty()) {
		pair<int,int> front = q.front();
		q.pop();
		int n1=front.first, par1=front.second;
		for(auto it: adjList[n1]) {
			if(!visited[it]) {
				visited[it] = true;
				q.push(make_pair(it, n1));
				// n1 is parent of it
			}
			else if(it != par1) {
				// Visited, & isn't equal to current's parent
				// Should've been visited by some other path
				// Cycle exists
				return true;
			}
		}
	}
	// No cycle found till here
	return false;
}

bool isCyclicUG(vector<vector<int>>& adjList, int n) {
	vector<bool> visited(n, false);
	bool ans = false;
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			bool smallAns = detectCycle(adjList, i, visited);
			if(smallAns == true) {
				// Any 1-cycle means -> Cyclic graph
				return true;
			}
		}
	}
	// No cycle found
	return false;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s);
		adjList[s].push_back(f);
	}
	bool ans = isCyclicUG(adjList, n);
	cout << (ans == true ? "YES" : "NO") << "\n";
	return 0;
}