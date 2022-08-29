#include <bits/stdc++.h>
using namespace std;

// Bipartite Graph  ->  basically spots all cycles are even or not (no problem with linear nodes)

bool isBipartiteDfs(vector<vector<int>>& adjList, int i, vector<int>& color, int c) {
	color[i] = c;
	for(auto it: adjList[i]) {
		if(color[it] == -1) {
			int newColor = (1^c); // Reverse between 0 & 1
			bool smallAns = isBipartiteDfs(adjList, it, color, newColor);
			if(smallAns == false) {
				return false;
			}
		}
		else if(color[it] == c) {
			// Same-color of adjacent nodes
			return false;
		}
	}
	return true;
}

bool isBipartiteBfs(vector<vector<int>>& adjList, int i, vector<int>& color, int c) {
	queue<pair<int,int>> q;
	q.push(make_pair(i, c));
	color[i] = c;
	while(!q.empty()) {
		pair<int,int> front = q.front();
		q.pop();
		int node1=front.first, c1=front.second;
		for(auto it: adjList[node1]) {
			if(color[it] == -1) {
				int c2 = (1^c1); // Reversal between 0 & 1
				q.push(make_pair(it, c2));
				color[it] = c2;
			}
			else if(color[it] == c1) {
				// Adjacent nodes same color
				return false;
			}
		}
	}
	return true;
}

bool isBipartite(vector<vector<int>>& adjList, int n) {
	vector<int> color(n, -1);
	for(int i=0; i<n; i++) {
		if(color[i] == -1) {
			// bool smallAns = isBipartiteDfs(adjList, i, color, 0);
			bool smallAns = isBipartiteBfs(adjList, i, color, 0);
			if(smallAns == false) {
				return false; // If any 1-component fails .. whole graph will !!
			}
		}
	}
	return true;
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
	bool ans = isBipartite(adjList, n);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}