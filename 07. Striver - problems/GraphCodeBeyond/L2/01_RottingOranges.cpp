#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Time : O(1)
	// Space : O(1)
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && x<m && y>=0 && y<n);
	}

public:
	// Time : O(n^2)
	// Space : O(n^2)
    int orangesRotting(vector<vector<int>>& grid) {
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
        int time = 0;
        while(!q.empty()) {
        	time++;
        	int s = q.size();
        	for(int i=0; i<s; i++) {
        		pair<int,int> front = q.front();
        		q.pop();
        		int x=front.first , y=front.second;
        		int dx[4] = {0, 0, 1, -1};
        		int dy[4] = {1, -1, 0, 0};
        		for(int k=0; k<4; k++) {
        			int xnew = x+dx[k] , ynew = y+dy[k];
        			if(isValid(xnew,ynew,m,n) && !visited[xnew][ynew] && grid[xnew][ynew]==1) {
        				q.push(make_pair(xnew,ynew));
        				visited[xnew][ynew] = true;
        			}
        		}
        	}
        }
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(!visited[i][j] && grid[i][j]==1) {
        			return -1;
        		}
        	}
        }
        if(time > 0) {
        	time--;
        }
        return time;
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int>(n, 0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> grid[i][j];
		}
	}
	int ans = solve.orangesRotting(grid);
	cout << ans << endl;
	return 0;
}