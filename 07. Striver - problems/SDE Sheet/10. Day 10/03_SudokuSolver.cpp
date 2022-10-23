#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool sudoku(int row, vector<vector<char>>& board) {
		if(row == 9) {
			return true;
		}
		bool found = false; // is empty space present ?
		for(int col=0; col<9; col++) {
			if(board[row][col] == '.') {
				// empty, have to fill it
				found = true;
				for(char c='1'; c<='9'; c++) {
					if(isValid(row, col, c, board)) {
						// Fill it .. recursion call
						board[row][col] = c;
						if(col)
					}
				}
			}
		}
		if(found == false) {
			bool ans = sudoku(row+1, board);
			return ans;
		}
	}

public:
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = sudoku(0, board);
        return board;
    }
};

int main() {
	vector<vector<char>> board(9, vector<char>(9,'.'));
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cin >> board[i][j];
		}
	}
	Solution solve;
	solve.solveSudoku(board);
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}