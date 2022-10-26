#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && x<m && y>=0 && y<n);
	}

	void dfs(vector<vector<int>>& grid, int c, int x, int y, int color, int m, int n, vector<vector<bool>>& visited) {
		grid[x][y] = color;
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};
		for(int k=0; k<4; k++) {
			int x2=x+dx[k], y2=y+dy[k];
			if(isValid(x2,y2,m,n) && grid[x2][y2]==c && !visited[x2][y2]) {
				visited[x2][y2] = true;
				dfs(grid, c, x2, y2, color, m, n, visited);
			}
		}
		return;
	}

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c = image[sr][sc];
        int m=image.size(), n=image[0].size();
        vector<vector<int>> grid(m, vector<int>(n,0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		grid[i][j] = image[i][j]; // creating copy
        	}
        }
        visited[sr][sc] = true;
        dfs(grid, c, sr, sc, color, m, n, visited);
        return grid;
    }
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> image(m, vector<int>(n,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> image[i][j];
		}
	}
	Solution solve;
	int sr, sc, color;
	cin >> sr >> sc >> color;
	vector<vector<int>> ans = solve.floodFill(image, sr, sc, color);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}