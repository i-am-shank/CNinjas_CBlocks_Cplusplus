#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

	bool dfs(vector<vector<int>>& maze, int sx, int sy, int dx, int dy, vector<vector<bool>>& visited) {
		int m=maze.size(), n=maze[0].size();
		queue<pair<int,int>> q;
		q.push(make_pair(sx,sy));
		visited[sx][sy] = true;
		while(!q.empty()) {
			// Traverse whole level in 1-step
			int s = q.size();
			for(int i=0; i<s; i++) {
				pair<int,int> front = q.front();
				q.pop();
				int x=front.first, y=front.second;
				int change_x[4] = {0, 0, 1, -1};
				int change_y[4] = {1, -1, 0, 0};
				for(int k=0; k<4; k++) {
					int nx=x, ny=y;
					int xnew=nx+change_x[k], ynew=ny+change_y[k];
					while(isValid(xnew,ynew,m,n) && maze[xnew][ynew]!=1 && !visited[xnew][ynew]) {
						visited[xnew][ynew] = true;
						nx=xnew, ny=ynew;
					}
					if(nx==dx && ny==dy) {
						return true;
					}
					// Only further search from this place if ball stopped
					if((isValid(xnew,ynew,m,n)==false) || (isValid(xnew,ynew,m,n) && maze[xnew][ynew]==1)) {
						visited[x][y] = true;
						q.push(make_pair(x,y));
					}
				}
			}
		}
		return false;
	}

public:
	bool hasPath(vector<vector<int>> maze, vector<int>& start, vector<int>& destination) {
		int m=maze.size(), n=maze[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n,false));
		int sx=start[0], sy=start[1], dx=destination[0], dy=destination[1];
		if(maze[sx][sy]==1 || maze[dx][dy]==1) { // wall
			return false;
		}
		if(sx==dx && sy==dy) {
			return true;
		}
		bool ans = dfs(maze, sx, sy, dx, dy, visited);
		return ans;
	}
};

int main() {
	// Empty space -> 0   ,   Walls -> 1
	int m, n;
	cin >> m >> n;
	vector<vector<int>> maze(m, vector<int>(n,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> maze[i][j];
		}
	}
	vector<int> start , destination;
	int sx, sy, dx, dy;
	cin >> sx >> sy >> dx >> dy;
	start.push_back(sx);
	start.push_back(sy);
	destination.push_back(dx);
	destination.push_back(dy);
	Solution solve;
	bool ans = solve.hasPath(maze, start, destination);
	cout << (ans==true ? "YES" : "NO") << endl;
	return 0;
}