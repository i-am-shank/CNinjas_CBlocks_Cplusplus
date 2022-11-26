#include <bits/stdc++.h>
using namespace std;

bool gameWithComputer() {
	cout << "Playing with Computer !" << "\n";
	cout << "Let's start !!" << "\n";
	cout << "Enter :-\n1 for Stone, \n2 for Paper, \n3 for Scissor" << "\n";
	int computer, player;
	computer = (rand()%3) + 1; // 1, 2, or 3
	cin >> player; // 1, 2, or 3
	if(player<0 || player>3) { // Invalid input
		cout << "Press 0 to exit, else 1 to restart !!" << "\n";
		int playAgain;
		cin >> playAgain;
		if(playAgain == 0) {
			return false; // End game
		}
		else {
			return true; // continuing infinite loop
		}
	}
	if(computer == 1) {
		if(player == 1) {
			cout << "COMPUTER - Stone  |  PLAYER - Stone" << "\n";
			cout << "Game Draw !" << "\n";
		}
		else if(player == 2) {
			cout << "COMPUTER - Stone  |  PLAYER - Paper" << "\n";
			cout << "######---- Player Wins ----######" << "\n";
		}
		else { // player = 3
			cout << "COMPUTER - Stone  |  PLAYER - Scissor" << "\n";
			cout << "######---- Computer Wins ----######" << "\n";
		}
	}
	else if(computer == 2) {
		if(player == 1) {
			cout << "COMPUTER - Paper  |  PLAYER - Stone" << "\n";
			cout << "######---- Computer Wins ----######" << "\n";
		}
		else if(player == 2) {
			cout << "COMPUTER - Paper  |  PLAYER - Paper" << "\n";
			cout << "Game Draw !" << "\n";
		}
		else { // player = 3
			cout << "COMPUTER - Paper  |  PLAYER - Scissor" << "\n";
			cout << "######---- Player Wins ----######" << "\n";
		}
	}
	else { // computer = 3
		if(player == 1) {
			cout << "COMPUTER - Scissor  |  PLAYER - Stone" << "\n";
			cout << "######---- Player Wins ----######" << "\n";
		}
		else if(player == 2) {
			cout << "COMPUTER - Scissor  |  PLAYER - Paper" << "\n";
			cout << "######---- Computer Wins ----######" << "\n";
		}
		else { // player = 3
			cout << "COMPUTER - Scissor  |  PLAYER - Scissor" << "\n";
			cout << "Game Draw !" << "\n";
		}
	}
	// Play Again OR EXIT  ..  process :-
	cout << "Press 0 to exit, else 1 to restart !!" << "\n";
	int playAgain;
	cin >> playAgain;
	if(playAgain == 0) {
		return false; // End game
	}
	else {
		return true; // continuing infinite loop
	}
}

bool twoPlayerGame() {
	cout << "Playing in 2-player mode !" << "\n";
	cout << "Let's start !!" << "\n";
	cout << "Player 1 chance :" << "\n";
	cout << "Enter :-\n1 for Stone, \n2 for Paper, \n3 for Scissor" << "\n";
	int player1, player2;
	cin >> player1; // 1, 2, or 3
	cout << "Player 2 chance :" << "\n";
	cout << "Enter :-\n1 for Stone, \n2 for Paper, \n3 for Scissor" << "\n";
	cin >> player2; // 1, 2, or 3
	if(player1<0 || player1>3 || player2<0 || player2>3) {
		// Play Again OR EXIT  ..  process :-
		cout << "Press 0 to exit, else 1 to restart !!" << "\n";
		int playAgain;
		cin >> playAgain;
		if(playAgain == 0) {
			return false; // End game
		}
		else {
			return true; // continuing infinite loop
		}
	}
	if(player1 == 1) {
		if(player2 == 1) {
			cout << "PLAYER1 - Stone  |  PLAYER2 - Stone" << "\n";
			cout << "Game Draw !" << "\n";
		}
		else if(player2 == 2) {
			cout << "PLAYER1 - Stone  |  PLAYER2 - Paper" << "\n";
			cout << "######---- Player2 Wins ----######" << "\n";
		}
		else { // player2 == 3
			cout << "PLAYER1 - Stone  |  PLAYER2 - Scissor" << "\n";
			cout << "######---- Player1 Wins ----######" << "\n";
		}
	}
	else if(player1 == 2) {
		if(player2 == 1) {
			cout << "PLAYER1 - Paper  |  PLAYER2 - Stone" << "\n";
			cout << "######---- Player1 Wins ----######" << "\n";
		}
		else if(player2 == 2) {
			cout << "PLAYER1 - Paper  |  PLAYER2 - Paper" << "\n";
			cout << "Game Draw !" << "\n";
		}
		else { // player2 == 3
			cout << "PLAYER1 - Paper  |  PLAYER2 - Scissor" << "\n";
			cout << "######---- Player2 Wins ----######" << "\n";
		}
	}
	else { // player1 == 3
		if(player2 == 1) {
			cout << "PLAYER1 - Scissor  |  PLAYER2 - Stone" << "\n";
			cout << "######---- Player2 Wins ----######" << "\n";
		}
		else if(player2 == 2) {
			cout << "PLAYER1 - Scissor  |  PLAYER2 - Paper" << "\n";
			cout << "######---- Player1 Wins ----######" << "\n";
		}
		else { // player2 == 3
			cout << "PLAYER1 - Scissor  |  PLAYER2 - Scissor" << "\n";
			cout << "Game Draw !" << "\n";
		}
	}
	cout << "Press 0 to exit, else 1 to restart !!" << "\n";
	int playAgain;
	cin >> playAgain;
	if(playAgain == 0) {
		return false; // End game
	}
	else {
		return true; // continuing infinite loop
	}
}

int main() {
	cout << "WELCOME TO THE GAME OF STONE PAPER SCISSOR !!!" << "\n";
	cout << "*******************************************\n";
	cout << "To Play with computer, Press 1" << "\n";
	cout << "To Play in 2-player mode, Press 2" << "\n";
	int gameType;
	cin >> gameType;
	if(gameType == 1) {
		bool gameOn = true; // initially game-on
		while(gameOn == true) {
			gameOn = gameWithComputer();
		}
		cout << "************** GAME OVER **************" << "\n";
	}
	else if(gameType == 2) {
		bool gameOn = true;
		while(gameOn == true) {
			gameOn = twoPlayerGame();
		}
		cout << "************** GAME OVER **************" << "\n";
	}
	else {
		cout << "Wrong Game-choice" << "\n";
	}
	return 0;
}