#include <bits/stdc++.h>
using namespace std;

bool isValid(int xnew, int ynew, int n, int m) {
	if((xnew>=0 && xnew<n)  &&  (ynew>=0 && ynew<m)) {
		return true;
	}
	return false;
}

void DFS(vector<vector<char>> &board, int n, int m, int x, int y, int xprev, int yprev, char c, bool** visited, bool& ans) {
	if(isValid(x, y, n, m) == false) {
		return;
	}
	if(board[x][y] != c) {
		return;
	}
	if(visited[x][y]) {
		ans = true;
		return;
	}
	visited[x][y] = true;
	int x_dir[4] = {0, 0, 1, -1};
	int y_dir[4] = {1, -1, 0, 0};
	for(int i=0; i<4; i++) {
		int xnew = x + x_dir[i];
		int ynew = y + y_dir[i];
		if(xnew == xprev && ynew == yprev) {
			continue;  // Avoid to-and-fro motion
		}
		DFS(board, n, m, xnew, ynew, x, y, c, visited, ans);
	}
	return;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool** visited = new bool*[n];
    for(int i=0; i<n; i++) {
    	visited[i] = new bool[m];
    	for(int j=0; j<m; j++) {
    		visited[i][j] = false;
    	}
    }
    bool ans = false;
    for(int i=0; i<n; i++) {
    	for(int j=0; j<m; j++) {
    		if(visited[i][j] == false) {
    			char c = board[i][j];
    			DFS(board, n, m, i, j, -1, -1, c, visited, ans);
    		}
    	}
    }
    return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board;
	for(int i=0; i<n; i++) {
		vector<char> temp;
		for(int j=0; j<m; j++) {
			char c;
			cin >> c;
			temp.push_back(c);
		}
		board.push_back(temp);
	}
	bool ans = hasCycle(board, n, m);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}