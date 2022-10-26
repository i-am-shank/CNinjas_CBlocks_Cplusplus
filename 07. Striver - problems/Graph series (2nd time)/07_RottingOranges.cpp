#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && x<m && y>=0 && y<n);
	}

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pp> q;
        int m = grid.size(), n = grid[0].size();
        int time = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		// Push all rotten oranges (initially)
        		if(grid[i][j] == 2) {
        			visited[i][j] = true;
        			q.push(make_pair(i,j));
        			// Start BFS from these (simultaneously)
        		}
        	}
        }
        while(!q.empty()) {
        	int s = q.size();
        	time++; // At each layer (+1 at 0-time too)
        	// So do -1 at end
        	for(int i=0; i<s; i++) {
        		pp front = q.front();
        		q.pop();
        		int x1=front.first, y1=front.second;
        		int dx[4] = {0,0,1,-1};
        		int dy[4] = {1,-1,0,0};
        		for(int k=0; k<4; k++) {
        			int x2=x1+dx[k], y2=y1+dy[k];
        			if(isValid(x2,y2,m,n) && !visited[x2][y2] && grid[x2][y2]==1) {
        				// Rotten only fresh oranges
        				visited[x2][y2] = true;
        				grid[x2][y2] = 2; // marking rottened
        				q.push(make_pair(x2,y2));
        			}
        		}
        	}
        }
        if(time > 0) {
        	time--; // don't decrease if not increased at level 0
        }
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(grid[i][j] == 1) {
        			// A fresh orange remained
        			return -1;
        		}
        	}
        }
        return time; // If all oranges rottened
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int>(n,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> grid[i][j];
		}
	}
	int ans = solve.orangesRotting(grid);
	cout << ans << "\n";
	return 0;
}