#include <bits/stdc++.h>
using namespace std;

class Solution{
	// Tabulation -> space optimization (1 1D array)
	// Time : O(n^2)
	// Space : O(n) .. Even better
	int maxPrice_dp_space2(vector<int>& price, int n, int sum) {
		vector<int> dp(sum+1, 0);
		for(int j=0; j<=sum; j++) {
			dp[j] = (j*price[0]);
		}
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=sum; j++) {
				int notTake = dp[j];
				int take = 0;
				if(i+1 <= j) {
					// Infinite supply of pieces of each length
					take = price[i] + dp[j-(i+1)];
				}
				// Rewrite over dp[j] .. using old value of dp[j] too.
				dp[j] = max(notTake, take);
			}
		}
		return dp[sum];
	}

	// Tabulation -> space optimization (2 1D arrays)
	// Time : O(n^2)
	// Space : O(n)
	int maxPrice_dp_space(vector<int>& price, int n, int sum) {
		vector<int> prev(sum+1, 0);
		for(int j=0; j<=sum; j++) {
			prev[j] = (j*price[0]);
		}
		for(int i=1; i<=n; i++) {
			vector<int> curr(sum+1, 0);
			for(int j=0; j<=sum; j++) {
				int notTake = prev[j];
				int take = 0;
				if(i+1 <= j) {
					// Infinite supply of pieces of each length
					take = price[i] + curr[j-(i+1)];
				}
				curr[j] = max(notTake, take);
			}
			prev = curr;
		}
		return prev[sum];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int maxPrice_dp(vector<int>& price, int n, int sum) {
		vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
		for(int j=0; j<=sum; j++) {
			dp[0][j] = (j*price[0]);
		}
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=sum; j++) {
				int notTake = dp[i-1][j];
				int take = 0;
				if(i+1 <= j) {
					// Infinite supply of pieces of each length
					take = price[i] + dp[i][j-(n+1)];
				}
				dp[i][j] = max(notTake, take);
			}
		}
		return dp[n][sum];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. Recursion stack
	int maxPrice_mem_help(vector<int>& price, int n, int sum, vector<vector<int>>& dp) {
		if(n == 0) {
			// break into pieces of length 1 --> price[0]
			return (sum*price[0]);
		}
		if(dp[n][sum] != -1) {
			return dp[n][sum];
		}
		int notTake = maxPrice_mem_help(price, n-1, sum, dp);
		int take = 0;
		if(n+1 <= sum) {
			// Infinite supply of pieces of each length
			take = price[n] + maxPrice_mem_help(price, n, sum-(n+1), dp);
		}
		return dp[n][sum] = max(notTake, take);
	}

	int maxPrice_mem(vector<int>& price, int n, int sum) {
		vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
		return maxPrice_mem_help(price, n, sum, dp);
	}


	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Auxiliary recursion stack
	int maxPrice_rec(vector<int>& price, int n, int sum) {
		if(n == 0) {
			// break into pieces of length 1 --> price[0]
			return (sum*price[0]);
		}
		int notTake = maxPrice_rec(price, n-1, sum);
		int take = 0;
		if(n+1 <= sum) {
			// Infinite supply of pieces of each length
			take = price[n] + maxPrice_rec(price, n, sum-(n+1));
		}
		return max(notTake, take);
	}

public:
    int cutRod(vector<int>& price, int n) {
        // int ans1 = maxPrice_rec(price, n-1, n);
        // int ans2 = maxPrice_mem(price, n-1, n);
        // int ans3 = maxPrice_dp(price, n-1, n);
        // int ans4 = maxPrice_dp_space(price, n-1, n);
        int ans5 = maxPrice_dp_space2(price, n-1, n);
        return ans5;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> price(n);
	for(int i=0; i<n; i++) {
		cin >> price[i];
	}
	int ans = solve.cutRod(price, n);
	cout << ans << "\n";
	return 0;
}