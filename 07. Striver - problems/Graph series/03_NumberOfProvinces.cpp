#include <bits/stdc++.h>
using namespace std;

class Solution {
	// BFS Traversal
	void bfs(vector<vector<int>>& isConnected, int n, int i, vector<bool>& visited) {
		queue<int> q;
		q.push(i);
		visited[i] = true;
		while(!q.empty()) {
			int front = q.front();
			q.pop();
			for(int j=0; j<n; j++) {
				if(isConnected[front][j] && !visited[j] && front!=j) {
					q.push(j);
					visited[j] = true;
				}
			}
		}
		return;
	}

	// DFS Traversal
	void dfs(vector<vector<int>>& isConnected, int n, int i, vector<bool>& visited) {
		visited[i] = true;
		for(int j=0; j<n; j++) {
			if(isConnected[i][j]==1 && i!=j && !visited[j]) {
				dfs(isConnected, n, j, visited);
			}
		}
		return;
	}

public:
	// Counting no. of components of graph
	//    ->  By doing traversals (BFS/DFS -> use either)
	
	// Time : O(n + n + (2*e))  .. not exact complexity
	//    .. Traversal done for each node   ->  O(n)
	//    .. And overall complexity of all traversals  ->  O(n+(2*e))
	// Space : O(n)  + O(n) .. queue OR recursion stack (BFS/DFS)

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
        	if(!visited[i]) {
        		count++;
        		// bfs(isConnected, n, i, visited);
        		dfs(isConnected, n, i, visited);
        	}
        }
        return count;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<vector<int>> isConnected(n, vector<int>(n, 0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> isConnected[i][j];
		}
	}
	int ans = solve.findCircleNum(isConnected);
	cout << ans << endl;
	return 0;
}