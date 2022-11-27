#include <bits/stdc++.h>
using namespace std;

void movePlayer(vector<vector<char>>& board, int position, char c) {
	position--;
	int row = position/3, col = position%3;
	if(board[row][col]=='X' || board[row][col]=='O') {
		// already marked position
		cout << "You wasted your chance, better luck next time." << "\n";
	}
	else {
		board[row][col] = c;
		return;
	}
}

void printBoard(vector<vector<char>>& board) {
	for(int i=0; i<board.size(); i++) {
		for(int j=0; j<board[i].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

void checkPlayerWin(vector<vector<char>>& board, char c, bool &gameFinished) {
	// Check rows
	for(int i=0; i<3; i++) {
		bool won = true;
		for(int j=0; j<3; j++) {
			if(board[i][j] != c) {
				won = false;
				break;
			}
		}
		if(won == true) {
			gameFinished = true;
			if(c == 'O') {
				cout << "!!!!  Player 1 won  !!!!" << "\n";
			}
			else {
				cout << "!!!!  Player 2 won  !!!!" << "\n";
			}
			return;
		}
	}
	// Check columns
	for(int j=0; j<3; j++) {
		bool won = true;
		for(int i=0; i<3; i++) {
			if(board[i][j] != c) {
				won = false;
				break;
			}
		}
		if(won == true) {
			gameFinished = true;
			if(c == 'O') {
				cout << "!!!!  Player 1 won  !!!!" << "\n";
			}
			else {
				cout << "!!!!  Player 2 won  !!!!" << "\n";
			}
			return;
		}
	}
	// Check 2 diagonals
	if(board[0][0]==c&&board[1][1]==c&&board[2][2]==c || board[2][0]==c&&board[1][1]==c&&board[0][2]==c) {
		gameFinished = true;
		if(c == 'O') {
			cout << "!!!!  Player 1 won  !!!!" << "\n";
		}
		else {
			cout << "!!!!  Player 2 won  !!!!" << "\n";
		}
		return;
	}
}

int main() {
	cout << "TIC-TAC-TOE game :-" << "\n";
	string p1, p2;
	cout << "Enter player-1 name : " << "\n";
	cin >> p1;
	cout << "Enter player-2 name : " << "\n";
	cin >> p2;
	cout << "THE RULES :-" << "\n";
	cout << "In a player turns, player enters the cell to place their marker." << "\n";
	cout << "If an already marked position is given, the chance is lost." << "\n";
	vector<vector<char>> board(3, vector<char>(3,'0'));
	char num = '1';
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			board[i][j] = num;
			num++;
		}
	}
	cout << "The cell nos. are given here for reference" << "\n";
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cout << board[i][j] << " ";
			if(j != 2) {
				cout << "| ";
			}
		}
		cout << "\n";
	}
	bool gameFinished = false;
	if(gameFinished == false) {
		for(int chance=0; chance<9 && gameFinished!=true; chance++) {
			if(chance % 2 == 0) {
				cout << "Player 1's turn ----" << "\n";
				int position;
				cin >> position;
				movePlayer(board, position, 'O');
				printBoard(board);
				cout << "------------------------" << "\n";
				checkPlayerWin(board, 'O', gameFinished); // Player1 - 'O'
			}
			else {
				cout << "Player 2's turn ----" << "\n";
				int position;
				cin >> position;
				movePlayer(board, position, 'X');
				printBoard(board);
				cout << "------------------------" << "\n";
				checkPlayerWin(board, 'X', gameFinished);
			}
		}
	}
	return 0;
}