#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(int x, int y, int m, int n) {
		return (x>=0 && y>=0 && x<m && y<n);
	}

	// DFS Traversal
	void dfs(vector<vector<int>>& image, int x, int y, vector<vector<bool>>& visited, int color, int newColor, int m, int n) {
		visited[x][y] = true;
		image[x][y] = newColor;
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};
		for(int k=0; k<4; k++) {
			int x_new = x+dx[k] , y_new = y+dy[k];
			if(isValid(x_new, y_new, m, n) && !visited[x_new][y_new] && image[x_new][y_new]==color) {
				dfs(image, x_new, y_new, visited, color, newColor, m, n);
			}
		}
		return;
	}

	// BFS Traversal
	void bfs(vector<vector<int>>& image, int x, int y, vector<vector<bool>>& visited, int color, int newColor, int m, int n) {
		queue<pair<int,int>> q;
		q.push(make_pair(x,y));
		visited[x][y] = true;
		while(!q.empty()) {
			pair<int,int> front = q.front();
			q.pop();
			image[front.first][front.second] = newColor;
			int dx[4] = {0, 0, 1, -1};
			int dy[4] = {1, -1, 0, 0};
			for(int k=0; k<4; k++) {
				int x_new = front.first + dx[k];
				int y_new = front.second + dy[k];
				if(isValid(x_new, y_new, m, n) && !visited[x_new][y_new] && image[x_new][y_new]==color) {
					q.push(make_pair(x_new, y_new));
					visited[x_new][y_new] = true;
				}
			}
		}
		return;
	}

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        int m = image.size(), n=image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // dfs(image, sr, sc, visited, color, newColor, m, n);
        bfs(image, sr, sc, visited, color, newColor, m, n);
        return image;
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	vector<vector<int>> image(m, vector<int>(n,0));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> image[i][j];
		}
	}
	int sr, sc, newColor;
	cin >> sr >> sc >> newColor;
	vector<vector<int>> ans = solve.floodFill(image, sr, sc, newColor);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}