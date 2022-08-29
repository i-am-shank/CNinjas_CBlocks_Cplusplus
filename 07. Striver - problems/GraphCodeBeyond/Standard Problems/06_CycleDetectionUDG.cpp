#include <bits/stdc++.h>
using namespace std;

bool isCyclicDfs(vector<vector<int>>& adjList,int i, int parent, vector<bool>& visited) {
	visited[i] = true;
	for(auto it: adjList[i]) {
		if(!visited[it]) {
			bool smallAns = isCyclicDfs(adjList, it, i, visited);
			if(smallAns == true) {
				return true; // Cycle detected by sub-component
			}
		}
		else if(it != parent) {
			return true; // Visited (but is not parent .. surely Cycle)
		}
	}
	return false;
}

bool isCyclicBfs(vector<vector<int>>& adjList, int i, int parent, vector<bool>& visited) {
	queue<pair<int,int>> q;
	q.push(make_pair(i, parent));
	visited[i] = true;
	while(!q.empty()) {
		pair<int,int> front = q.front();
		q.pop();
		int node1=front.first, par1=front.second;
		for(auto it: adjList[node1]) {
			if(!visited[it]) {
				q.push(make_pair(it,node1));
				visited[it] = true;
			}
			else if(it != par1) {
				return true; // Visited but is not parent(definitely cycle)
			}
		}
	}
	return false;
}

bool isCyclic(vector<vector<int>>& adjList, int n) {
	vector<bool> visited(n, false);
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			// bool smallAns = isCyclicDfs(adjList, i, -1, visited);
			bool smallAns = isCyclicBfs(adjList, i, -1, visited);
			if(smallAns == true) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s); // f <--> s
		adjList[s].push_back(f);
	}
	bool ans = isCyclic(adjList, n);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}