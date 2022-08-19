#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

	// Twisted bfs
	void bfs(vector<vector<int>> &maze, int sx, int sy, vector<vector<bool>>& visited) {
		int m=maze.size(), n=maze[0].size();
		queue<pair<int,int>> q;
		q.push(make_pair(sx,sy));
		visited[sx][sy] = true;
		while(!q.empty()) {
			pair<int,int> front = q.front();
			q.pop();
			int cx[4] = {0,1,0,-1};
			int cy[4] = {1,0,-1,0};
			for(int k=0; k<4; k++) {
				int x=front.first , y=front.second;
				if(isValid(x+cx[k],y+cy[k],m,n) && maze[x+cx[k]][y+cy[k]]==0) {
					// Can move in this direction
					while(isValid(x+cx[k],y+cy[k],m,n) && maze[x+cx[k]][y+cy[k]]==0) {
						// while wall not reached, keep moving
						x = x+cx[k];
						y = y+cy[k];
					}
					// Wall reached.. check if visited before
					if(!visited[x][y]) {
						visited[x][y] = true;
						q.push(make_pair(x,y));
					}
				}
			}
		}
		return;
	}

public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        int m=maze.size(), n=maze[0].size();
        int sx=start[0], sy=start[1];
        int dx=destination[0], dy=destination[1];
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        bfs(maze, sx, sy, visited);
        return (visited[dx][dy]);
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	vector<vector<int>> maze(m, vector<int>(n,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> maze[i][j];
		}
	}
	vector<int> start(2,0);
	for(int i=0; i<2; i++) {
		cin >> start[i];
	}
	vector<int> destination(2,0);
	for(int i=0; i<2; i++) {
		cin >> destination[i];
	}
	bool ans = solve.hasPath(maze, start, destination);
	cout << (ans==true ? "true" : "false") << endl;
	return 0;
}