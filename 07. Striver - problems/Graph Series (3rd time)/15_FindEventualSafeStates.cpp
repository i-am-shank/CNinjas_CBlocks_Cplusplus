#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    	// Get all nodes, with paths ending terminal node
    	// Reverse-graph
    	// Now, nodes with cycle attached won't come in toposort
    	// --> Get the toposort now.
        int n = graph.size();
        // Reversed graph  (f --> s   ==>   s --> f)
        vector<vector<int>> adj(n, vector<int>());
        vector<int> ans;
        vector<int> inDegree(n, 0);
        queue<int> q;
        for(int i=0; i<n; i++) {
        	for(auto it: graph[i]) {
        		// i --> it
        		adj[it].push_back(i); // it --> i
        		inDegree[i]++;
        	}
        }
        for(int i=0; i<n; i++) {
        	if(inDegree[i] == 0) {
        		q.push(i);
        	}
        }
        while(!q.empty()) {
        	int front = q.front();
        	q.pop();
        	ans.push_back(front);
        	for(auto it: adj[front]) {
        		// front --> it
        		inDegree[it]--;
        		if(inDegree[it] == 0) {
        			q.push(it);
        		}
        	}
        }
        sort(ans.begin(), ans.end()); // as required
        return ans;
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
			int ele;
			cin >> ele;
			graph[i].push_back(ele);
		}
	}
	Solution solve;
	vector<int> ans = solve.eventualSafeNodes(graph);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}