#include <bits/stdc++.h>
using namespace std;

class Solution {
	void dfs(vector<vector<int>>& adjList, int node, stack<int>& stk, vector<bool>& visited) {
		for(auto it: adjList[node]) {
			if(!visited[it]) {
				visited[it] = true;
				dfs(adjList, it, stk, visited);
			}
		}
		// Now, all paths from node traversed
		// All outgoing nodes done !
		stk.push(node); // pushed last
		// ..(so that it comes before all outgoing nodes)
		return;
	}

public:
	vector<int> topoSort(int n, vector<vector<int>>& adjList) {
	    stack<int> stk;
	    vector<bool> visited(n, false);
	    for(int i=0; i<n; i++) {
	    	if(!visited[i]) {
	    		visited[i] = true;
	    		dfs(adjList, i, stk, visited);
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
	int n;
	cin >> n;
	vector<vector<int>> adjList(n, vector<int>());
	for(int i=0; i<n; i++) {
		int m;
		cin >> m;
		for(int j=0; j<m; j++) {
			int ele;
			cin >> ele;
			adjList[i].push_back(ele);
		}
	}
	Solution solve;
	vector<int> ans = solve.topoSort(n, adjList);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}