#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

class Solution {
	bool isValid(int x, int y, int n, int m) {
		return (x>=0 && x<n && y>=0 && y<m);
	}

public:
	vector<vector<int>> nearest(vector<vector<int>> grid) {
		int n=grid.size(), m=grid[0].size();
		vector<vector<int>> dist(n, vector<int>(m, 0));
		queue<pp> q;
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(grid[i][j] == 1) {
					// Start BFS from here
					dist[i][j] = 0;
					visited[i][j] = true;
					q.push(make_pair(i,j));
				}
			}
		}
		while(!q.empty()) {
			pp front = q.front();
			q.pop();
			int x1=front.first, y1=front.second;
			int dx[4] = {0,0,1,-1};
			int dy[4] = {1,-1,0,0};
			for(int k=0; k<4; k++) {
				int x2=x1+dx[k], y2=y1+dy[k];
				if(isValid(x2,y2,n,m) && !visited[x2][y2]) {
					visited[x2][y2] = true;
					dist[x2][y2] = dist[x1][y1]+1;
					q.push(make_pair(x2,y2));
				}
			}
		}
		return dist;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	Solution solve;
	vector<vector<int>> ans = solve.nearest(grid);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}