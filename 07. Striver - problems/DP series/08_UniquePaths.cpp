#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation -> Space optimization
	// Time : O(m*n)
	// Space : O(n)
	int uniquePaths_dp_space(int m, int n) {
		vector<int> dp(n, 0); // Values of prev rows
		for(int i=0; i<m; i++) {
			vector<int> temp(n, 0); // Curr row
			for(int j=0; j<n; j++) {
				if(i==0 && j==0) {
					temp[j] = 1;
				}
				else {
					if(i >= 1) {
						temp[j] += dp[j]; // Upper value (prev row)
					}
					if(j >= 1) {
						temp[j] += temp[j-1]; // Left value (curr row)
					}
				}
			}
			dp = temp; // For next row, curr is prev row
		}
		return dp[n-1]; // Right-most value of bottom row
	}

	// Tabulation
	// Time : O(m*n)
	// Space : O(m*n)
	int uniquePaths_dp(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = 1;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(i >= 1) {
					dp[i][j] += dp[i-1][j];
				}
				if(j >= 1) {
					dp[i][j] += dp[i][j-1];
				}
			}
		}
		return dp[m-1][n-1];
	}

	// Memoization
	// Time : O(m * n)
	// Space : O(m * n)
	int uniquePaths_mem_help(int m, int n, int i, int j, vector<vector<int>>& dp) {
		if(i<0 || j<0) {
			return 0;
		}
		if(dp[i][j] != -1) {
			return dp[i][j];
		}
		int ans1 = uniquePaths_mem_help(m, n, i-1, j, dp);
		int ans2 = uniquePaths_mem_help(m, n, i, j-1, dp);
		dp[i][j] = (ans1 + ans2);
		return dp[i][j];
	}

	int uniquePaths_mem(int m, int n, int i, int j) {
		vector<vector<int>> dp(m, vector<int> (n, -1));
		dp[0][0] = 1;
		return uniquePaths_mem_help(m, n, i, j, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(1)
	int uniquePaths_rec(int m, int n, int i, int j) {
		if(i==0 && j==0) {
			return 1;
		}
		if(i<0 || j<0) {
			return 0;
		}
		int ans1 = uniquePaths_rec(m, n, i-1, j);
		int ans2 = uniquePaths_rec(m, n, i, j-1);
		return (ans1 + ans2);
	}

public:
    int uniquePaths(int m, int n) {
        int i=m-1, j=n-1;  // Row no. & Column no.
        /*
        int ans1 = uniquePaths_rec(m, n, i, j);
        int ans2 = uniquePaths_mem(m, n, i, j);
        int ans3 = uniquePaths_dp(m, n);
        */
        int ans4 = uniquePaths_dp_space(m, n);
        return ans4;
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	int ans = solve.uniquePaths(m, n);
	cout << ans << endl;
	return 0;
}