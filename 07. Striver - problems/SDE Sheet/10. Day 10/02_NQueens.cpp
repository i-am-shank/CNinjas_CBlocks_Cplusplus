#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(int x, int y, int n, vector<vector<char>>& board) {
		// Check in yth column..
		for(int i=0; i<n; i++) {
			if(board[i][y] == 'Q') {
				return false; // Found a queen here
			}
		}
		// Check in xth row.. not needed (as only filled 1)
		// Check in 2-diagonals
		for(int i=x, j=y; i<n && j<n; i++, j++) {
			if(board[i][j] == 'Q') {
				return false;
			}
		}
		for(int i=x, j=y; i>=0 && j>=0; i--, j--) {
			if(board[i][j] == 'Q') {
				return false;
			}
		}
		for(int i=x, j=y; i<n && j>=0; i++, j--) {
			if(board[i][j] == 'Q') {
				return false;
			}
		}
		for(int i=x, j=y; i>=0 && j<n; i--, j++) {
			if(board[i][j] == 'Q') {
				return false;
			}
		}
		return true; // If all checks passed
	}

	bool nQueens(int n, int idx, vector<vector<char>>& board, vector<vector<string>>& boards) {
		if(idx == n) {
			vector<string> curr(n);
			for(int i=0; i<n; i++) {
				string row = "";
				for(int j=0; j<n; j++) {
					row += board[i][j];
				}
				curr[i] = row;
			}
			boards.push_back(curr);
			return true; // board must be filled
			// ..so reached here
		}
		for(int j=0; j<n; j++) {
			// iterating in (idx) row..
			if(isValid(idx, j, n, board)) {
				board[idx][j] = 'Q';
				bool smallAns = nQueens(n, idx+1, board, boards);
				// For all solutions.. no need to return true
				board[idx][j] = '.'; // backtrack
			}
		}
		return false; // Iterated entire row.. can't find valid space
		// so returned false
	}

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> boards;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        bool ans = nQueens(n, 0, board, boards);
        return boards;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<vector<string>> ans = solve.solveNQueens(n);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}