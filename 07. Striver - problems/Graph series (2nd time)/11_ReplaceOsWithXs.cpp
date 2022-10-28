#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(int x, int y, int n, int m) {
		return (x>=0 && y>=0 && x<n && y<m);
	}

	void dfs(vector<vector<char>>& mat, int x, int y, int n, int m, vector<vector<bool>>& visited) {
		int dx[4] = {0,0,1,-1};
		int dy[4] = {1,-1,0,0};
		for(int k=0; k<4; k++) {
			int x2=x+dx[k], y2=y+dy[k];
			if(isValid(x2,y2,n,m) && !visited[x2][y2] && mat[x2][y2]=='O') {
				visited[x2][y2] = true;
				dfs(mat, x2, y2, n, m, visited);
			}
		}
		return;
	}

public:
	vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		// Start traversing only from boundary O's
        		if(i==0 || j==0 || i==n-1 || j==m-1) {
        			if(!visited[i][j] && mat[i][j]=='O') {
        				// cout << i << " " << j << "\n";
        				visited[i][j] = true;
        				dfs(mat, i, j, n, m, visited);
        			}
        			// All O's with boundary attached marked true in visited
        			// Replace all other O's to X's
        		}
        	}
        }
        for(int i=0; i<n; i++) {
        	for(int j=0; j<m; j++) {
        		if((!visited[i][j]) && (mat[i][j]=='O')) {
        			// Replace these O's
        			mat[i][j] = 'X';
        		}
        	}
        }
        return mat;
    }
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mat(n, vector<char>(m,'0'));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> mat[i][j];
		}
	}
	Solution solve;
	vector<vector<char>> ans = solve.fill(n, m, mat);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}