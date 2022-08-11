#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

	void bfs(vector<vector<int>>& grid, int& time) {
		int m=grid.size(), n=grid[0].size();
		queue<pair<int,int>> q;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(grid[i][j] == 2) {
					q.push(make_pair(i,j));
					visited[i][j] = true;
				}
			}
		}
		while(!q.empty()) {
			int s = q.size();
			time++; // At each depth .. 1-time added (0th depth  ->  time becomes 1)
			    //  .. had to deduct 1 from time at last
			for(int i=0; i<s; i++) { // Travel 1-depth whole at once
				pair<int,int> front = q.front();
				q.pop();
				int dx[4] = {0, 0, 1, -1};
				int dy[4] = {1, -1, 0, 0};
				for(int k=0; k<4; k++) {
					int x_new = front.first + dx[k] , y_new = front.second + dy[k];
					if(isValid(x_new,y_new,m,n) && !visited[x_new][y_new] && grid[x_new][y_new]==1) {
						visited[x_new][y_new] = true; // No need to edit grid
						q.push(make_pair(x_new, y_new));
					}
				}
			}
		}
		time--; // As all oranges at 1st level are rotten (by default)
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(!visited[i][j] && grid[i][j]==1) { // A good orange not got rotten
					time = -1;
					break;
				}
			}
		}
		return;
	}

public:
	// We've to find min. time  ->  for all oranges to get rotten
	// And rottening starts simultaneously from all rotten oranges
	//    -> BFS will work  (DFS will fail .. as it won't go simultaneously in all direction)
	
	// Time : O(m*n) .. BFS Traversal will take relatively less time
	//      -> this is taken by  (Rotten oranges check)  &  (Good-unrotten oranges check)
	// Space : O(m*n) + O(m*n)  ..  visited-array & Queue
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        bfs(grid, time);
        return time;
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
	cout << ans << endl;
	return 0;
}