#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation -> space optimization
	// Time : O(m*n)
	// Space : O(n)
	int count_dp_space(int m, int n) {
		vector<int> prev(n+2,0);
		// shift of index.. for m<0 .. n<0 base cases
		for(int i=1; i<=m+1; i++) {
			vector<int> curr(n+2,0);
			for(int j=1; j<=n+1; j++) {
				if(i==1 && j==1) {
					curr[j] = 1;
					continue;
				}
				int left = prev[j];
				int right = curr[j-1];
				curr[j] = (left+right);
			}
			prev = curr;
		}
		return prev[n+1];
	}

	// Tabulation
	// Time : O(m*n)
	// Space : O(m*n)
	int count_dp(int m, int n) {
		vector<vector<int>> dp(m+2, vector<int>(n+2,0));
		// shift of index.. for m<0 .. n<0 base cases
		for(int i=1; i<=m+1; i++) {
			for(int j=1; j<=n+1; j++) {
				if(i==1 && j==1) {
					dp[i][j] = 1;
					continue;
				}
				int left = dp[i-1][j];
				int right = dp[i][j-1];
				dp[i][j] = (left+right);
			}
		}
		return dp[m+1][n+1];
	}

	// Memoization
	// Time : O(m*n)
	// Space : O(m*n) + O(m+n) .. Recursion stack
	int count_mem_help(int m, int n, vector<vector<int>>& dp) {
		if(m==0 && n==0) {
			return 1;
		}
		if(m<0 || n<0) {
			return 0;
		}
		if(dp[m][n] != -1) {
			return dp[m][n];
		}
		int left = count_mem_help(m-1, n, dp);
		int right = count_mem_help(m, n-1, dp);
		return dp[m][n] = (left+right);
	}

	int count_mem(int m, int n) {
		vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
		return count_mem_help(m, n, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	int count_rec(int m, int n) {
		if(m==0 && n==0) {
			return 1;
		}
		if(m<0 || n<0) {
			return 0;
		}
		int left = count_rec(m-1, n);
		int right = count_rec(m, n-1);
		return (left+right);
	}

public:
    int uniquePaths(int m, int n) {
        // int ans1 = count_rec(m-1, n-1);
        // int ans2 = count_mem(m-1, n-1);
        // int ans3 = count_dp(m-1, n-1);
        int ans4 = count_dp_space(m-1, n-1);
        return ans4;
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	int ans = solve.uniquePaths(m, n);
	cout << ans << "\n";
	return 0;
}