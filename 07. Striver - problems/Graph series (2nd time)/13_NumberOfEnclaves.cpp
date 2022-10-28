#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(int x, int y, int n, int m) {
		return (x>=0 && y>=0 && x<n && y<m);
	}

	void dfs(vector<vector<int>>& grid, int x, int y, int n, int m, vector<vector<bool>>& visited) {
		int dx[4] = {0,0,-1,1};
		int dy[4] = {1,-1,0,0};
		for(int k=0; k<4; k++) {
			int x2=x+dx[k], y2=y+dy[k];
			if(isValid(x2,y2,n,m) && !visited[x2][y2] && grid[x2][y2]==1) {
				visited[x2][y2] = true;
				dfs(grid, x2, y2, n, m, visited);
			}
		}
		return;
	}

  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		if(i==0 || j==0 || i==n-1 || j==m-1) {
        			if(!visited[i][j] && grid[i][j]==1) {
        				// These 1's are not enclaves
        				visited[i][j] = true;
        				dfs(grid, i, j, n, m, visited);
        			}
        		}
        	}
        }
        // Now count no. of lands remaining (i.e. un-visited)
        int count = 0;
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		if(!visited[i][j] && grid[i][j]==1) {
        			count++;
        		}
        	}
        }
        return count;
    }
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m,0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	Solution solve;
	int ans = solve.numberOfEnclaves(grid);
	cout << ans << "\n";
	return 0;
}