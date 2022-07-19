#include <bits/stdc++.h>
using namespace std;

bool isValid(int x_new, int y_new, int n, int m) {
	if((x_new>=0 && x_new<n)  &&  (y_new>=0 && y_new<m)) {
		return true;
	}
	return false;
}

bool DFS(vector<vector<char>>& board, int x, int y, int n, int m, string word, int index, bool** visited) {
	if(index == 11) {  // found till end of  "CODINGNINJA"  (size = 11)
		return true;
	}
	visited[x][y] = true;
	int x_dir[8] = {0, 1, 1, 1, -1, -1, -1, 0};
	int y_dir[8] = {1, 0, 1, -1, 0, 1, -1, -1};
	bool ans = false;
	for(int i=0; i<8; i++) {
		int x_new = x + x_dir[i];
		int y_new = y + y_dir[i];
		if(isValid(x_new,y_new,n,m) && board[x_new][y_new]==word[index] && !visited[x_new][y_new]) {
			bool smallAns = DFS(board, x_new, y_new, n, m, word, index+1, visited);
			ans = (ans || smallAns);
		}
		if(ans == true) {
			break;
		}
	}
	return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    string word = "CODINGNINJA";
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
    		if(board[i][j] == word[0]) {
    			bool smallAns = DFS(board, i, j, n, m, word, 1, visited);
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
	bool ans = hasPath(board, n, m);
	cout << ans << endl;
	return 0;
}