#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool bfs(vector<vector<int>>& graph, int i, int parentSet, vector<int>& set) {
		queue<pair<int,int>> q;
		q.push(make_pair(i,parentSet));
		set[i] = (1 ^ parentSet);
		while(!q.empty()) {
			pair<int,int> front = q.front();
			q.pop();
			int node = front.first;
			int pSet = front.second;
			for(auto it: graph[node]) {
				if(set[it] == -1) {
					q.push(make_pair(it,set[node]));
					set[it] = (1 ^ set[node]);
				}
				else {
					if(set[it] == set[node]) {
						// Adjacent node -> same set
						return false;
					}
				}
			}
		}
		return true;
	}

	bool dfs(vector<vector<int>>& graph, int i, int parentSet, vector<int>& set) {
		set[i] = (1 ^ parentSet); // (Opposite set)
		for(auto it: graph[i]) {
			if(set[it] == -1) { // Set not-assigned
				bool smallAns = dfs(graph, it, set[i], set);
				if(smallAns == false) {
					return false;
				}
			}
			else {
				if(set[it] == set[i]) {
					// Adjacent nodes -> same set
					return false;
				}
			}
		}
		return true;
	}

public:
	// Time : O(n + (2*e))  ..  n -> no. of nodes , e -> no. of edges
	// Space : O(n) + O(n) .. Set-array & Recursion-stack
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> set(n, -1); // -1 -> member of no-set
        // 0 & 1  ->  my set-convention
        for(int i=0; i<n; i++) {
        	if(set[i] == -1) {
        		// parentSet = 0 .. childSet -> diff. from parent
        		// bool ans = dfs(graph, i, 0, set);
        		bool ans = bfs(graph, i, 0, set);
        		if(ans == false) {
        			return false; // Adjacent same-set nodes found
        		}
        	}
        }
        return true;
    }
};

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> graph(n, vector<int>());
	for(int i=0; i<e; i++) {
		int f, s;
		cin >> f >> s;
		if(f != s) { // No self-edges included
			graph[f].push_back(s);
			graph[s].push_back(f);
		}
	}
	Solution solve;
	bool ans = solve.isBipartite(graph);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}