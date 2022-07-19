#include <bits/stdc++.h>
using namespace std;

bool isValid(int x_new, int y_new, int n, int m) {
	return (x_new>=0 && x_new<n && y_new>=0 && y_new<m);
}

bool BFS(vector<vector<char>> &board, int x, int y, string &s, int index, bool** visited) {
	if(index == 11) {
		return true;
	}
	visited[x][y] = true;
	bool ans = false;
	int n = board.size(), m = board[0].size();
	int x_dir[8] = {0, 0, 1, 1, 1, -1, -1, -1};
	int y_dir[8] = {1, -1, 0, 1, -1, 0, 1, -1};
	for(int i=0; i<8; i++) {
		int x_new = x+x_dir[i] , y_new = y+y_dir[i];
		bool validMove = isValid(x_new, y_new, n, m);
		if(validMove && board[x_new][y_new]==s[index] && visited[x_new][y_new]==false) {
			bool smallAns = BFS(board, x_new, y_new, s, index+1, visited);
			ans = (ans || smallAns);
			if(ans == true) {
				break;
			}
		}
	}
	return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    string s = "CODINGNINJA";
    bool **visited = new bool*[n];
    for(int i=0; i<n; i++) {
    	visited[i] = new bool[m];
    	for(int j=0; j<m; j++) {
    		visited[i][j] = false;
    	}
    }
    bool ans = false;
    for(int i=0; i<n; i++) {
    	for(int j=0; j<m; j++) {
    		if(board[i][j]=='C') {
    			bool smallAns = BFS(board, i, j, s, 1, visited);
    			ans = (ans || smallAns);
    			if(ans == true) {
    				break;
    			}
    		}
    	}
    	if(ans == true) {
    		break;
    	}
    }
    return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m,'\0'));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> board[i][j];
		}
	}
	bool ans = hasPath(board, n, m);
	cout << ans << endl;
	return 0;
}