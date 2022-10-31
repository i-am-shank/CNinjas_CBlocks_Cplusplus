#include <bits/stdc++.h>
using namespace std;

class Solution {
	void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited, stack<int>& stk) {
		for(auto it: adj[node]) {
			if(!visited[it]) {
				visited[it] = true;
				dfs(adj, it, visited, stk);
			}
		}
		stk.push(node); // When all paths from node traversed
		return;
	}

public:
	vector<int> topoSort_kahnsAlgo(int v, vector<vector<int>>& adj) {
		queue<int> q;
		vector<int> inDegree(v, 0);
		for(int i=0; i<v; i++) {
			for(auto it: adj[i]) {
				inDegree[it]++; // i --> it
			}
		}
		for(int i=0; i<v; i++) {
			if(inDegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> ans;
		while(!q.empty()) {
			int front = q.front();
			ans.push_back(front);
			q.pop();
			for(auto it: adj[front]) {
				inDegree[it]--; // front --> it (removing edge)
				if(inDegree[it] == 0) {
					q.push(it);
				}
			}
		}
		return ans;
	}

	vector<int> topoSort(int v, vector<vector<int>>& adj) {
	    stack<int> stk;
	    vector<bool> visited(v, false);
	    for(int i=0; i<v; i++) {
	    	if(!visited[i]) {
	    		visited[i] = true;
	    		dfs(adj, i, visited, stk);
	    	}
	    }
	    vector<int> ans;
	    while(!stk.empty()) {
	    	ans.push_back(stk.top());
	    	stk.pop();
	    }
	    return ans;
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
		adj[f].push_back(s); // f-->s  directed edge
	}
	vector<int> ans = solve.topoSort(v, adj);
	vector<int> ans2 = solve.topoSort_kahnsAlgo(v, adj);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	for(int i=0; i<ans2.size(); i++) {
		cout << ans2[i] << " ";
	}
	cout << "\n";
	cout << "\n";
	return 0;
}