#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isCyclic(int v, vector<vector<int>>& adj) {
		vector<int> inDegree(v, 0);
		for(int i=0; i<v; i++) {
			for(auto it: adj[i]) {
				inDegree[it]++; // i --> it
			}
		}
		queue<int> q;
		for(int i=0; i<v; i++) {
			if(inDegree[i] == 0) {
				q.push(i);
			}
		}
		int count = 0; // Count of elements in toposort
		while(!q.empty()) {
			int front = q.front();
			q.pop();
			count++;
			for(auto it: adj[front]) {
				inDegree[it]--; // remove edge front --> it
				if(inDegree[it] == 0) {
					q.push(it);
				}
			}
		}
		return (count < v); // If count == v.. Acyclic graph
    }
};

int main() {
	Solution solve;
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adj(v, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s); // f --> s
	}
	bool ans = solve.isCyclic(v, adj);
	cout << (ans == true ? "true": "false") << "\n";
	return 0;
}