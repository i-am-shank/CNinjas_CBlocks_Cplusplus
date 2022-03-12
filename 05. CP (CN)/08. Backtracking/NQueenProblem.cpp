#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int col) {
	// Check position .. board[row][col] .. possible or not
	// Same row condition ..already checked (as moving row wise)
	// Inserting elements row-wise .. So check only upper places
	//   If element will be placed.. will be on upper half

	// Same column condition
	for(int i=row-1; i>=0; i--) {
		if(board[i][col] == 1) {
			return false;
		}
	}
	// Left-top to Right-bottom diagonal
	for(int i=row-1, j=col-1 ; i>=0, j>=0 ; i--, j--) {
		if(board[i][j] == 1) {
			return false;
		}
	}
	// Right-top to Left-bottom diagonal
	for(int i=row-1, j=col+1 ; i>=0, j<n ; i--, j++) {
		if(board[i][j] == 1) {
			return false;
		}
	}
	// All test conditions passed
	return true;
}

void nQueenHelper(int n, int row) {
	if(row == n) {
		// We have reached some solution
		// Print the matrix.
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << board[i][j] << " ";
			}
		}
		cout << endl;
		// return
		return;
	}
	// Place at all possible positions, move to small-problem
	for(int j=0; j<n; j++) {  //  Check jth column of row-th row
		if(isPossible(n, row, j)) {
			board[row][j] = 1;  //  If possible, insert 1
			nQueenHelper(n, row+1);  // Recursion called
			// If reaches here, means recursion not successful
			// ----  Backtrack !!  ----    but first :-
			board[row][j] = 0;  // Refresh jth col of row-th row
		}
	}
	return;
}

void placeNQueens(int n) {
	memset(board, 0, 11*11*sizeof(int));  // Initialise board
	nQueenHelper(n, 0);
}

int main() {
	int n;
	cin >> n;
	placeNQueens(n);
	return 0;
}