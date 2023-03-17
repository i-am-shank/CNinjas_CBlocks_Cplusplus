#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(V+E) .. all nodes & edges traversed
	// Space : O(V) .. max all nodes in queue
	bool isCyclic(int n, vector<vector<int>>& adj) {
        int cnt=0;
        queue<int> q;
        vector<int> inDegree(n, 0);
        for(int i=0; i<n; i++) {
        	for(auto it: adj[i]) {
        		// i --> it
        		inDegree[it]++;
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
        	cnt++;
        	for(auto it: adj[front]) {
        		// front -> it
        		inDegree[it]--;
        		if(inDegree[it] == 0) {
        			// All before are used in toposort
        			q.push(it);
        		}
        	}
        }
        return (cnt < n); // All nodes came in toposort
        // If cycle will be there, there is contradiction
        // All nodes can't come in toposort(indegree won't be 0)
        // cnt will be less than n (in that case)
    }
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n, vector<int>());
	for(int i=0; i<n; i++) {
		int m;
		cin >> m;
		for(int j=0; j<m; j++) {
			int ele;
			cin >> ele;
			adj[i].push_back(ele);
		}
	}
	Solution solve;
	bool ans = solve.isCyclic(n, adj);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}