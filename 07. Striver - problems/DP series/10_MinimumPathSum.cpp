#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(m*n)
	// Space : O(n)
	int minPath_dp_space(vector<vector<int>>& grid, int m, int n) {
		vector<int> prevRow(n+1, 0);
		for(int i=0; i<=m; i++) {
			vector<int> currRow(n+1, 0);
			for(int j=0; j<=n; j++) {
				if(i==0 && j==0) {
					currRow[j] = grid[i][j];
				}
				else {
					int choice1 = INT_MAX, choice2 = INT_MAX;
					if(i > 0) {
						choice1 = prevRow[j];
					}
					if(j > 0) {
						choice2 = currRow[j-1];
					}
					currRow[j] = grid[i][j] + min(choice1, choice2);
				}
			}
			prevRow = currRow;  // Updating for next iteration
		}
		return prevRow[n];  // last updated entry
	}

	// Tabulation
	// Time : O(m*n)
	// Space : O(m*n)
	int minPath_dp(vector<vector<int>>& grid, int m, int n) {
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for(int i=0; i<=m; i++) {
			for(int j=0; j<=n; j++) {
				if(i==0 && j==0) {
					dp[i][j] = grid[i][j];
				}
				else {
					int choice1 = INT_MAX, choice2 = INT_MAX;
					if(i > 0) {
						choice1 = dp[i-1][j];
					}
					if(j > 0) {
						choice2 = dp[i][j-1];
					}
					dp[i][j] = grid[i][j] + min(choice1, choice2);
				}
			}
		}
		return dp[m][n];
	}

	// Memoization
	// Time : O(m*n)
	// Space : O(m*n)  +  O(m+n) .. Recursion stack
	int minPath_mem_help(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
		if(m<0 || n<0) {
			return INT_MAX;
		}
		if(dp[m][n] != -1) {
			return dp[m][n];
		}
		int ans1 = minPath_mem_help(grid, m-1, n, dp);
		int ans2 = minPath_mem_help(grid, m, n-1, dp);
		dp[m][n] = (grid[m][n] + min(ans1, ans2));
		return dp[m][n];
	}

	int minPath_mem(vector<vector<int>>& grid, int m, int n) {
		vector<vector<int>> dp (m+1, vector<int>(n+1, -1));
		dp[0][0] = grid[0][0];
		return minPath_mem_help(grid, m, n, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(2^n) .. Recursion stack
	int minPath_rec(vector<vector<int>>& grid, int m, int n) {
		if(m==0 && n==0) {
			return grid[m][n];
		}
		if(m<0 || n<0) { // Invalid .. finding minimum
			return INT_MAX; // So, return maximum value
		}
		int ans1 = minPath_rec(grid, m-1, n);
		int ans2 = minPath_rec(grid, m, n-1);
		return (grid[m][n] + min(ans1, ans2));
	}

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        /*
        int ans1 = minPath_rec(grid, m-1, n-1);
        int ans2 = minPath_mem(grid, m-1, n-1);
        int ans3 = minPath_dp(grid, m-1, n-1);
        */
        int ans4 = minPath_dp_space(grid, m-1, n-1);
        return ans4;
    }
};

int main() {
	int m, n;
	cin >> m >> n;
	Solution solve;
	vector<vector<int>> grid;
	for(int i=0; i<m; i++) {
		vector<int> row;
		for(int j=0; j<n; j++) {
			int ele;
			cin >> ele;
			row.push_back(ele);
		}
		grid.push_back(row);
	}
	int ans = solve.minPathSum(grid);
	cout << ans << endl;
	return 0;
}