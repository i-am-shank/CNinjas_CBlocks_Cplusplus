#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

class Solution {
	bool isValid(int x, int y, int n, int m) {
		return (x>=0 && x<n && y>=0 && y<m);
	}

	void bfs(vector<vector<char>>& grid, int n, int m, int x, int y, vector<vector<bool>>& visited) {
		queue<pp> q;
		q.push(mp(x,y));
		visited[x][y] = true;
		while(!q.empty()) {
			pp front = q.front();
			q.pop();
			int x1=front.fi, y1=front.se;
			int dx[8] = {1,1,1,-1,-1,-1,0,0};
			int dy[8] = {-1,0,1,-1,0,1,-1,1};
			for(int k=0; k<8; k++) {
				int x2=x1+dx[k], y2=y1+dy[k];
				if(isValid(x2,y2,n,m) && !visited[x2][y2] && grid[x2][y2]=='1') {
					visited[x2][y2] = true;
					q.push(mp(x2,y2));
				}
			}
		}
		return;
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int n=grid.size(), m=grid[0].size();
		vector<vector<bool>> visited(n, vector<bool>(m,false));
		int count = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(!visited[i][j] && grid[i][j]=='1') {
					count++;
					bfs(grid, n, m, i, j, visited);
				}
			}
		}
		return count;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m,0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	Solution solve;
	int ans = solve.numIslands(grid);
	cout << ans << "\n";
	return 0;
}