#include <bits/stdc++.h>
using namespace std;

void solveSudoku(int sudoku[][9], int n) {
	
}

int main() {
	int sudoku[9][9];
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cin >> sudoku[i][j];
		}
	}
	solveSudoku(sudoku, 9);
	return 0;
}