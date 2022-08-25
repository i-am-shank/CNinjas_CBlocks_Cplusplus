#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int,int>, int> pp;

class Solution {
	bool isValid(int x, int y, vector<vector<int>>& maze) {
		int n=maze.size(), m=maze[0].size();
		return (x>=0 && x<n && y>=0 && y<m && maze[x][y]==0);
	}

public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // 1 -> wall  ..  0 -> space
        set<pp> q;
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        int sx=start[0], sy=start[1], dx=destination[0], dy=destination[1];
        if(maze[sx][sy]==1 || maze[dx][dy]==1) {
        	return -1; // Wall at start-position or destination
        }
        dist[sx][sy] = 0;
        pp ele;
        ele.first.first=sx, ele.first.second=sy, ele.second=0;
        q.insert(ele);
        while(!q.empty()) {
        	auto front = q.begin();
        	int x=front->first.first, y=front->first.second, d1=front->second;
        	q.erase(front);
        	int dx[4] = {0,0,1,-1};
        	int dy[4] = {1,-1,0,0};
        	for(int k=0; k<4; k++) {
        		int tx=x, ty=y, d2=0;
        		while(tx>=0 && tx<n && ty>=0 && ty<m && maze[tx][ty]!=1) {
        			// Can move in this direction
        			tx += dx[k], ty += dy[k];
        			d2++;
        		}
        		tx -= dx[k] , ty -= dy[k] , d2--; // Ended at invalid place
        		if(d2 != 0) { // Atleast moved 1-place
        			// Should have reached to wall or edge of maze
        			pp curr;
        			curr.first.first=tx, curr.first.second=ty;
        			curr.second = (d2+d1);
        			if(dist[tx][ty] > (d2+d1)) {
        				dist[tx][ty] = (d2+d1);
        				q.insert(curr);
        			}
        		}
        	}
        }
        if(dist[dx][dy] == INT_MAX) {
        	return -1; // Not able to visit destination
        }
        return dist[dx][dy];
    }
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> maze(n, vector<int>(m, 0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> maze[i][j];
		}
	}
	vector<int> start(2), destination(2);
	for(int i=0; i<2; i++) {
		cin >> start[i];
	}
	for(int i=0; i<2; i++) {
		cin >> destination[i];
	}
	Solution solve;
	int ans = solve.shortestDistance(maze, start, destination);
	cout << ans << endl;
	return 0;
}