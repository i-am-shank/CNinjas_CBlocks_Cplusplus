#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool dfs(vector<vector<int>>& graph, int node, int color, vector<int>& colors) {
		int c2 = (1^color);
		for(auto it: graph[node]) {
			if(colors[it] == -1) {
				// color it
				colors[it] = c2;
				bool ans = dfs(graph, it, c2, colors);
				if(ans == false) {
					return false;
				}
			}
			else if(colors[it] != c2) {
				// Expected & actual colors are different
				return false;
			}
		}
		return true;
	}

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i=0; i<n; i++) {
        	if(colors[i] == -1) {
        		colors[i] = 0;
        		bool smallAns = dfs(graph, i, 0, colors);
        		if(smallAns == false) {
        			return false;
        		}
        	}
        }
        return true;
    }
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>());
	for(int i=0; i<n; i++) {
		int m;
		cin >> m;
		for(int j=0; j<m; j++) {
			int x;
			cin >> x;
			graph[i].push_back(x);
		}
	}
	Solution solve;
	bool ans = solve.isBipartite(graph);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}