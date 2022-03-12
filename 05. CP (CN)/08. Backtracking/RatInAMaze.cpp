#include <bits/stdc++.h>
using namespace std;

int path[11][11];

void ratInAMazeHelp(int maze[][20], int n, int row, int col) {
	if(row==n-1 && col==n-1) {
		// Assign current position to path array.
		path[row][col] = 1;
		// Print path
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << path[i][j] << " ";
			}
		}
		cout << endl;
		// return
		return;
	}

	// Call recursion .. for further movement of rat
	path[row][col] = 1;  //  Building path array
	maze[row][col] = 0;  //  Indicating that the box traversed .. so that we don't come back
	if(row!=n-1 && maze[row+1][col] == 1) {	 //  Explore downward
		ratInAMazeHelp(maze, n, row+1, col);
	}
	if(col!=n-1 && maze[row][col+1] == 1) {  //  Explore rightward
		ratInAMazeHelp(maze, n, row, col+1);
	}
	if(row!=0 && maze[row-1][col] == 1) {  //  Explore upward
		ratInAMazeHelp(maze, n, row-1, col);
	}
	if(col!=0 && maze[row][col-1] == 1) {  //  Explore leftward
		ratInAMazeHelp(maze, n, row, col-1);
	}
	// All possible paths from [row][col] explored.
	// Backtrack !!
	maze[row][col] = 1;  //  Maze refreshed to un-passed
	path[row][col] = 0;  //  Path refreshed
	return;
}

void ratInAMaze(int maze[][20], int n) {
	memset(path, 0, 11*11*sizeof(int));
	ratInAMazeHelp(maze, n, 0, 0);
	return;
}

int main() {
	int n;
	cin >> n;
	int maze[20][20];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> maze[i][j];
		}
	}
	ratInAMaze(maze, n);
	return 0;
}