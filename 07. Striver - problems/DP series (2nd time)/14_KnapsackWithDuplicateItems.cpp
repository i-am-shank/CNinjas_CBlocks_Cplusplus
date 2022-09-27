#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation --> space optimization
	// Time : O(n^2)
	// Space : O(n)
	int knapsack_dp_space(int W, vector<int>& wt, vector<int>& val, int n) {
		vector<int> prev(W+1,0);
		// 0th row, dp[0][i] = 0 .. for base case n<0 (shift of index)
		for(int i=1; i<=n+1; i++) {
			vector<int> curr(W+1,0);
			for(int j=0; j<=W; j++) {
				int notTake = prev[j];
				int take = -1e7;
				if(wt[i-1] <= j) {
					take = val[i-1] + curr[j-wt[i-1]];
				}
				curr[j] = max(notTake, take);
			}
			prev = curr;
		}
		return prev[W];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int knapsack_dp(int W, vector<int>& wt, vector<int>& val, int n) {
		vector<vector<int>> dp(n+2, vector<int>(W+1,0));
		// 0th row, dp[0][i] = 0 .. for base case n<0 (shift of index)
		for(int i=1; i<=n+1; i++) {
			for(int j=0; j<=W; j++) {
				int notTake = dp[i-1][j];
				int take = -1e7;
				if(wt[i-1] <= j) {
					take = val[i-1] + dp[i][j-wt[i-1]];
				}
				dp[i][j] = max(notTake, take);
			}
		}
		return dp[n+1][W];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. recursion stack
	int knapsack_mem_help(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp) {
		if(n < 0) {
			return 0;
		}
		if(dp[W][n] != -1) {
			return dp[W][n];
		}
		int notTake = knapsack_mem_help(W, wt, val, n-1, dp);
		int take = -1e7;
		if(wt[n] <= W) {
			take = val[n] + knapsack_mem_help(W-wt[n], wt, val, n, dp);
		}
		return dp[W][n] = max(notTake, take);
	}

	int knapsack_mem(int W, vector<int>& wt, vector<int>& val, int n) {
		// W , n
		vector<vector<int>> dp(W+1, vector<int>(n+1,-1));
		return knapsack_mem_help(W, wt, val, n, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	int knapsack_rec(int W, vector<int>& wt, vector<int>& val, int n) {
		if(n < 0) {
			return 0;
		}
		int notTake = knapsack_rec(W, wt, val, n-1);
		int take = -1e7;
		if(wt[n] <= W) {
			take = val[n] + knapsack_rec(W-wt[n], wt, val, n);
		}
		return max(notTake, take);
	}

public:
	int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
		// int ans1 = knapsack_rec(W, wt, val, n-1);
		// int ans2 = knapsack_mem(W, wt, val, n-1);
		// int ans3 = knapsack_dp(W, wt, val, n-1);
		int ans4 = knapsack_dp_space(W, wt, val, n-1);
		return ans4;
	}
};

int main() {
	Solution solve;
	int n, w;
	cin >> n >> w;
	vector<int> wt(n), val(n);
	for(int i=0; i<n; i++) {
		cin >> val[i];
	}
	for(int i=0; i<n; i++) {
		cin >> wt[i];
	}
	int ans = solve.knapSack(w, wt, val, n);
	cout << ans << "\n";
	return 0;
}