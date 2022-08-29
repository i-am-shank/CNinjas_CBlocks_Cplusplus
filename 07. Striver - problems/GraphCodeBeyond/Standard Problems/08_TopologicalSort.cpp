#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(vector<vector<int>>& adjList, int i, vector<bool>& visited, vector<bool>& visited2) {
	visited[i] = true;
	visited2[i] = true;
	for(auto it: adjList[i]) {
		if(!visited[i]) {
			bool smallAns = dfsCycle(adjList, it, visited, visited2);
			if(smallAns == true) {
				return true;
			}
		}
		else if(visited2[i]) {
			// Visited in same path (came back to origin)
			return true;
		}
	}
	visited2[i] = false;
	return false;
}

bool isCyclic(vector<vector<int>>& adjList, int n) { // Directed graph
	vector<bool> visited(n, false);
	vector<bool> visited2(n, false);
	for(int i=0; i<n; i++) {
		bool smallAns = dfsCycle(adjList, i, visited, visited2);
		if(smallAns == true) {
			return true; // Component has cycle detected
		}
	}
	return false;
}

// Using DFS & Stack
void dfs(vector<vector<int>>& adjList, int i, vector<bool>& visited, stack<int>& stk) {
	visited[i] = true;
	for(auto it: adjList[i]) {
		if(!visited[it]) {
			visited[it] = true;
			dfs(adjList, it, visited, stk);
		}
	}
	stk.push(i); // First push all inDegree-nodes .. then the source node
	return;
}

vector<int> topoSort2(vector<vector<int>>& adjList, int n) {
	bool flag = isCyclic(adjList, n);
	if(flag == true) { // Topological sort not possible
		vector<int> arr;
		return arr; // Empty array
	}
	stack<int> stk;
	vector<bool> visited(n, false);
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			dfs(adjList, i, visited, stk); // a --> b (insert all b first, then all a .. in stack)
		}
	}
	vector<int> ans; // Topological sort is .. first all a, then b
	while(!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}
	return ans;
}

// Kahn's algorithm
vector<int> topoSort(vector<vector<int>>& adjList, int n) {
	vector<int> inDegree(n, 0);
	for(int i=0; i<n; i++) {
		for(auto it: adjList[i]) {
			inDegree[it]++; // i --> it
		}
	}
	queue<int> q;
	for(int i=0; i<n; i++) {
		if(inDegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> ans;
	int count=0;
	while(!q.empty()) {
		int front = q.front();
		count++;
		q.pop();
		ans.push_back(front);
		for(auto it: adjList[front]) {
			inDegree[it]--;
			if(inDegree[it] == 0) {
				q.push(it);
			}
		}
	}
	if(count != n) { // Cycle doesn't exists
		vector<int> arr;
		return arr;
	}
	return ans;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s; // f --> s
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