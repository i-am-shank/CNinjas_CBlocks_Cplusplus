#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  	// Safe-node : Definition is based on out-Degrees
  	// ..but Kahn's algo is based on In-degree
  	// -->  Reverse edges.. so initial out-degrees convert to in-degrees
    vector<int> eventualSafeNodes(int v, vector<vector<int>>& adj) {
        vector<int> safeNodes;
        vector<int> inDegree(v, 0);
        vector<vector<int>> adj2(v, vector<int>());
        for(int i=0; i<v; i++) {
        	for(auto it: adj[i]) {
        		// i --> it
        		adj2[it].push_back(i); // it --> i
        	}
        }
        for(int i=0; i<v; i++) {
        	for(auto it: adj2[i]) {
        		inDegree[it]++; // i --> it
        	}
        }
        queue<int> q;
        for(int i=0; i<v; i++) {
        	if(inDegree[i] == 0) {
        		q.push(i);
        	}
        }
        while(!q.empty()) {
        	int front = q.front();
        	q.pop();
        	safeNodes.push_back(front);
        	for(auto it: adj2[front]) {
        		inDegree[it]--; // front --> it
        		if(inDegree[it] == 0) {
        			q.push(it);
        		}
        	}
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
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
		adj[f].push_back(s);
	}
	vector<int> ans = solve.eventualSafeNodes(v, adj);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}