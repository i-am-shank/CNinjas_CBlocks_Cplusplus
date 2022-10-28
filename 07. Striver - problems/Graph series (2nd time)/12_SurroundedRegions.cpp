#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

	void dfs(vector<vector<char>>& board, int x, int y, int m, int n, vector<vector<bool>>& visited) {
		int dx[4] = {0,0,1,-1};
		int dy[4] = {1,-1,0,0};
		for(int k=0; k<4; k++) {
			int x2=x+dx[k], y2=y+dy[k];
			if(isValid(x2,y2,m,n) && !visited[x2][y2] && board[x2][y2]=='O') {
				visited[x2][y2] = true;
				dfs(board, x2, y2, m, n, visited);
			}
		}
		return;
	}

public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(i==0 || j==0 || i==m-1 || j==n-1) {
        			if(!visited[i][j] && board[i][j]=='O') {
        				visited[i][j] = true;
        				dfs(board, i, j, m, n, visited);
        			}
        		}
        	}
        }
        // Now, all O's attached to boundary are marked visited
        // Flip others to X
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(!visited[i][j] && board[i][j]=='O') {
        			board[i][j] = 'X';
        		}
        	}
        }
        return;
    }
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<char>> board(m, vector<char>(n,'0'));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> board[i][j];
		}
	}
	Solution solved;
	solved.solve(board);
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}