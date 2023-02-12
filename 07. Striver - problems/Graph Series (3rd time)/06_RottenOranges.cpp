#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && x<m && y>=0 && y<n);
	}

public:
	int orangesRotting(vector<vector<int>>& grid) {
		int m=grid.size(), n=grid[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n,false));
		queue<pp> q;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(grid[i][j] == 2) {
					visited[i][j] = true;
					q.push(mp(i,j));
				}
			}
		}
		int time = 0;
		while(!q.empty()) {
			int s = q.size();
			time++; // 1-level traversed
			for(int i=0; i<s; i++) {
				pp front = q.front();
				q.pop();
				int x1=front.fi, y1=front.se;
				int dx[4] = {1,-1,0,0};
				int dy[4] = {0,0,1,-1};
				for(int k=0; k<4; k++) {
					int x2=x1+dx[k], y2=y1+dy[k];
					if(isValid(x2,y2,m,n) && grid[x2][y2]==1 && !visited[x2][y2]) {
						// Unvisited good orange
						visited[x2][y2] = true;
						q.push(mp(x2,y2));
					}
				}
			}
		}
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(grid[i][j]==1 && !visited[i][j]) {
					// Fresh unvisited orange.. not rotten
					return -1;
				}
			}
		}
		if(time != 0) {
			return (time-1);
		}
		return time;
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int>(n,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> grid[i][j];
		}
	}
	Solution solve;
	int ans = solve.orangesRotting(grid);
	cout << ans << "\n";
	return 0;
}