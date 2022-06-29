#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n^3)
	// Space : O(n^2)
	int count_dp_space(vector<vector<int>>& grid, int m, int n) {
		vector<vector<int>> nextRow(n, vector<int>(n,0));
		for(int i=m-1; i>=0; i--) {
			vector<vector<int>> currRow(n, vector<int>(n,0));
			for(int j1=0; j1<n; j1++) {
				for(int j2=0; j2<n; j2++) {
					if(i == m-1) {  // Base case
						for(int j1=0; j1<n; j1++) {
							for(int j2=0; j2<n; j2++) {
								if(j1 == j2) {
									currRow[j1][j2] = grid[i][j1];
								}
								else {
									currRow[j1][j2] = (grid[i][j1] + grid[i][j2]);
								}
							}
						}
					}
					else {
						int ans = INT_MIN;
						for(int dj1=-1; dj1<=1; dj1++) { // Calculate prev. max.
							for(int dj2=-1; dj2<=1; dj2++) {
								int value;
								if(j1 == j2) {
									value = grid[i][j1];
								}
								else {
									value = grid[i][j1] + grid[i][j2];
								}
								int nj1= (j1+dj1), nj2= (j2+dj2);
								if(nj1>=0 && nj1<n && nj2>=0 && nj2<n) {
									value += nextRow[nj1][nj2];
								}
								else {
									value += -1e8;
								}
								ans = max(ans, value);
							}
						}
						currRow[j1][j2] = ans;
					}
				}
			}
			nextRow = currRow;
		}
		return nextRow[0][n-1];  // stores 0th row, i.e. last iteration current row
	}

	// Tabulation
	// Time : O(n^3)
	// Space : O(n^3)   ->   3D DP
	int count_dp(vector<vector<int>>& grid, int m, int n) {
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,0)));
		// Base case
		for(int j1=0; j1<n; j1++) {
			for(int j2=0; j2<n; j2++) {
				if(j1 == j2) {
					dp[m-1][j1][j2] = grid[m-1][j1];
				}
				else {
					dp[m-1][j1][j2] = (grid[m-1][j1] + grid[m-1][j2]);
				}
			}
		}
		for(int i=m-2; i>=0; i--) { // Except base case row (bottom)
			for(int j1=0; j1<n; j1++) {
				for(int j2=0; j2<n; j2++) {
					int ans = INT_MIN;
					for(int dj1=-1; dj1<=1; dj1++) { // Calculate prev. max.
						for(int dj2=-1; dj2<=1; dj2++) {
							int value;
							if(j1 == j2) {
								value = grid[i][j1];
							}
							else {
								value = grid[i][j1] + grid[i][j2];
							}
							int nj1= (j1+dj1), nj2= (j2+dj2);
							if(nj1>=0 && nj1<n && nj2>=0 && nj2<n) {
								value += dp[i+1][nj1][nj2];
							}
							else {
								value += -1e8;
							}
							ans = max(ans, value);
						}
					}
					dp[i][j1][j2] = ans;
				}
			}
		}
		return (dp[0][0][n-1]); // Both robots starting pnt (i, j1, j2).
	}

	// Memoization
	// Time : O(n^3)
	// Space : O(n^3)   + O(n) .. Recursion stack
	int count_mem_help(vector<vector<int>>& grid, int m, int n, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
		if(j1<0 || j1>=n || j2<0 || j2>=n) { // Edge case
			return -1e8;
		}
		if(i == m-1) { // Base case
			if(j1==j2) {
				return grid[i][j1]; // Both at same place -> take once
			}
			return (grid[i][j1] + grid[i][j2]);
		}
		if(dp[i][j1][j2] != -1) {
			return dp[i][j1][j2];
		}
		int ans = -1e8;
		for(int col1=-1; col1<=1; col1++) {
			for(int col2=-1; col2<=1; col2++) {
				int smallAns;
				if(j1 == j2) {
					smallAns = grid[i][j1] + count_mem_help(grid, m, n, i+1, j1+col1, j2+col2, dp);
				}
				else {
					smallAns = (grid[i][j1]+grid[i][j2]) + count_mem_help(grid, m, n, i+1, j1+col1, j2+col2, dp);
				}
				ans = max(ans, smallAns);
			}
		}
		dp[i][j1][j2] = ans;
		return dp[i][j1][j2];
	}

	int count_mem(vector<vector<int>>& grid, int m, int n, int i, int j1, int j2) {
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
		int ans = count_mem_help(grid, m, n, i, j1, j2, dp);
		return ans;
	}

	// Recursion
	// Time : O(3^n)
	// Space : O(n)  ..  Recursion stack
	// Both robots have same row  ->  only i in function call
	// Only columns differ or can be same
	int count_rec(vector<vector<int>>& grid, int m, int n, int i, int j1, int j2) {
		if(j1<0 || j1>=n || j2<0 || j2>=n) { // Edge case
			return -1e8;
		}
		if(i == m-1) { // Base case
			if(j1==j2) {
				return grid[i][j1]; // Both at same place -> take once
			}
			return (grid[i][j1] + grid[i][j2]);
		}
		int ans = INT_MIN;
		for(int col1=-1; col1<=1; col1++) {
			for(int col2=-1; col2<=1; col2++) {
				int smallAns;
				if(j1 == j2) {
					smallAns = grid[i][j1] + count_rec(grid, m, n, i+1, j1+col1, j2+col2);
				}
				else {
					smallAns = (grid[i][j1]+grid[i][j2]) + count_rec(grid, m, n, i+1, j1+col1, j2+col2);
				}
				ans = max(ans, smallAns);
			}
		}
		return ans;
	}

public:
	// Fixed starting point  ->  Variable ending point
	// Recursion from   start -> end
    int cherryPickup(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size();
        /*
        int ans1 = count_rec(grid, m, n, 0, 0, n-1);
        int ans2 = count_mem(grid, m, n, 0, 0, n-1);
        int ans3 = count_dp(grid, m, n);
        */
        int ans4 = count_dp_space(grid, m, n);
        return ans4;
    }
};

int main() {
	Solution solve;
	vector<vector<int>> grid;
	int row, col;
	cin >> row >> col;
	for(int i=0; i<row; i++) {
		vector<int> rowVal;
		for(int j=0; j<col; j++) {
			int ele;
			cin >> ele;
			rowVal.push_back(ele);
		}
		grid.push_back(rowVal);
	}
	int ans = solve.cherryPickup(grid);
	cout << ans << endl;
	return 0;
}