#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

	// BFS traversal
	void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
		queue<pair<int,int>> q;
		q.push(make_pair(i,j));
		visited[i][j] = true;
		while(!q.empty()) {
			pair front = q.front();
			q.pop();
			int dx[4] = {1, -1, 0, 0};
			int dy[4] = {0, 0, 1, -1};
			for(int k=0; k<4; k++) {
				int x_new = front.first + dx[k];
				int y_new = front.second + dy[k];
				if(isValid(x_new, y_new, m, n)) {
					if(!visited[x_new][y_new] && grid[x_new][y_new]=='1') {
						q.push(make_pair(x_new, y_new));
						visited[x_new][y_new] = true;
					}
				}
			}
		}
		return;
	}

	// DFS traversal
	void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
		visited[i][j] = true;
		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};
		for(int k=0; k<4; k++) {
			int x_new = i+dx[k] , y_new = j+dy[k];
			if(isValid(x_new, y_new, m, n)) {
				if(!visited[x_new][y_new] && grid[x_new][y_new]=='1') {
					dfs(grid, visited, x_new, y_new, m, n);
				}
			}
		}
		return;
	}

public:
	// Time : O(m*n + m*n) .. overall traversal -> O(m*n) approx
	// Space : O(m*n) + O(m*n) .. visited array && Queue/recursion stack
    int numIslands(vector<vector<char>>& grid) {
    	int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int count = 0;
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(!visited[i][j]) {
        			if(grid[i][j] == '1') {
        				count++;
        				// dfs(grid, visited, i, j, m, n);
        				bfs(grid, visited, i, j, m, n);
        			}
        			else { // No need to do traversal
        				visited[i][j] = true;
        			}
        		}
        	}
        }
        return count;
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	vector<vector<char>> grid(m, vector<char>(n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> grid[i][j];
		}
	}
	int ans = solve.numIslands(grid);
	cout << ans << endl;
	return 0;
}