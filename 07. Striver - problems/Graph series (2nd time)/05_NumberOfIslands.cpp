#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

	void bfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
		queue<pp> q;
		q.push(make_pair(x, y));
		grid[x][y] = '2';
		while(!q.empty()) {
			pp front = q.front();
			q.pop();
			int x1=front.first, y1=front.second;
			// 4-directions
			int dx[4] = {0, 0, 1, -1};
			int dy[4] = {1, -1, 0, 0};
			for(int k=0; k<4; k++) {
				int x2 = x1+dx[k], y2 = y1+dy[k];
				if(isValid(x2,y2,m,n) && grid[x2][y2]=='1') {
					grid[x2][y2] = '2';
					q.push(make_pair(x2, y2));
				}
			}
		}
		return;
	}

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // For checking visited, mark all '1' to '2'
        int count = 0;
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(grid[i][j] == '1') {
        			// An island exists
        			count++;
        			bfs(grid, i, j, m, n);
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
	vector<vector<char>> grid(m, vector<char>(n, '0'));
	// '0' is stored temporarily as default char
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> grid[i][j];
		}
	}
	int ans = solve.numIslands(grid);
	cout << ans << "\n";
	return 0;
}