#include <bits/stdc++.h>
using namespace std;

class Solution {
	void dfs(vector<vector<int>>& isConnected, int node, int n, vector<bool>& visited) {
		for(int i=0; i<n; i++) {
			if(isConnected[node][i] && !visited[i] && (i!=node)) {
				visited[i] = true;
				dfs(isConnected, i, n, visited);
			}
		}
		return;
	}

public:
	// Time : O(n)  +  O(n + (2*e))
	//  .. outer-loop   overall-dfs
	// Space : O(n)  +  O(n)
	//  ...  visited   rec-stack
    int findCircleNum(vector<vector<int>>& isConnected) {
    	int n = isConnected.size();
    	vector<bool> visited(n, false);
    	int count = 0;
    	for(int i=0; i<n; i++) {
    		if(!visited[i]) {
    			count++;
    			dfs(isConnected, i, n, visited);
    		}
    	}
    	return count;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<vector<int>> isConnected(n, vector<int>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> isConnected[i][j];
		}
	}
	int ans = solve.findCircleNum(isConnected);
	cout << ans << "\n";
	return 0;
}