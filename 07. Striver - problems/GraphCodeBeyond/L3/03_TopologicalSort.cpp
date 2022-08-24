// Topo Sort :
//   -> Not applicable for :
//        - Undirected Graph
//        - Cyclic Graph

// -> For Acyclic Directed Graph

// Toposort  -  DFS (Vector / Stack)
//           -  Kahn's algorithm (BFS)

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, int i, vector<bool>& visited, stack<int>& stk) {
	visited[i] = true;
	vector<int> edges = adjList[i];
	for(int j=0; j<edges.size(); j++) {
		if(!visited[edges[j]]) {
			visited[edges[j]] = true;
			dfs(adjList, edges[j], visited, stk);
		}
	}
	stk.push(i);
	return;
}

// Using Kahn's algorithm & BFS
vector<int> topoSort2(vector<vector<int>>& adjList, int n) {
	queue<int> q;
	vector<int> visited(n+1, false);
	vector<int> inDegree(n+1, 0);
	for(int i=1; i<=n; i++) {
		for(auto it: adjList[i]) {
			inDegree[it]++; // An edge towards it (from node i)
		}
	} // InDegree array built
	for(int i=1; i<=n; i++) {
		if(inDegree[i] == 0) { // Push all starting nodes
			q.push(i); // ..Having no-inside edge
		}
	}
	vector<int> ans;
	// This will automatically sort nodes..
	// .. in increasing order of their in-degrees
	// ----->  That's what is TopoSort
	while(!q.empty()) {
		int front = q.front();
		ans.push_back(front);
		q.pop();
		for(auto it: adjList[front]) {
			inDegree[it]--; // Consuming inDegree 1-by-1
			if(inDegree[it] == 0) {
				q.push(it);
			}
		}
	}
	return ans;
}

// Using DFS & Stack
// Intuition  ->  think in terms of edges
// What is TopoSort ?   a -> b  (a before b)
// ....So first push all possible b .. then a
// ....Stack reverses the output

// Time : O(n + (2*e))
// Space : O(n) + O(n) + O(n)  ..  Visited-array + Recursion-stack + Stack
vector<int> topoSort(vector<vector<int>>& adjList, int n) {
	vector<bool> visited(n+1, false);
	stack<int> stk;
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			dfs(adjList, i, visited, stk);
		}
	}
	vector<int> ans;
	while(!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}
	return ans;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n+1, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adjList[f].push_back(s);
	}
	vector<int> ans = topoSort(adjList, n);
	vector<int> ans2 = topoSort2(adjList, n);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	for(int i=0; i<ans2.size(); i++) {
		cout << ans2[i] << " ";
	}
	cout << endl;
	return 0;
}