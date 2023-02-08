#include <bits/stdc++.h>
using namespace std;

class Solution {
	void bfs(vector<vector<int>>& adj, int node, vector<bool>& visited, int &v) {
		queue<int> q;
		q.push(node);
		visited[node] = true;
		while(!q.empty()) {
			int front = q.front();
			q.pop();
			for(int i=0; i<v; i++) {
				if(adj[i][front] && !visited[i]) {
					q.push(i);
					visited[i] = true;
				}
			}
		}
		return; // whole component visited
	}
	
public:
	int numProvinces(vector<vector<int>> adj, int v) {
		vector<bool> visited(v, false);
		int count = 0;
		for(int i=0; i<v; i++) {
			if(!visited[i]) {
				count++;
				bfs(adj, i, visited, v);
			}
		}
		return count;
	}
};

int main() {
	int v;
	cin >> v;
	vector<vector<int>> adj(v, vector<int>(v,0));
	for(int i=0; i<v; i++) {
		for(int j=0; j<v; j++) {
			cin >> adj[i][j]; // f -- s
		}
	}
	Solution solve;
	int ans = solve.numProvinces(adj, v);
	cout << ans << "\n";
	return 0;
}