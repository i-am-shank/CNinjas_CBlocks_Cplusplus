#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n^2)
	// Space : O(n)
	int maxProfit_dp_space(int n, int i, vector<int>& prices) {
		vector<int> nextRow(2,0);
		// Base case
		nextRow[0] = nextRow[1] = 0;
		for(int i=n-1; i>=0; i--) {
			vector<int> currRow(2,0);
			for(int buy=0; buy<2; buy++) {
				if(buy) {
					int profit1 = nextRow[0] - prices[i];
					int profit2 = nextRow[1];
					currRow[buy] = max(profit1, profit2);
				}
				else {
					int profit1 = nextRow[1] + prices[i];
					int profit2 = nextRow[0];
					currRow[buy] = max(profit1, profit2);
				}
			}
			nextRow = currRow;
		}
		return nextRow[1];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int maxProfit_dp(int n, int i, vector<int>& prices) {
		vector<vector<int>> dp(n+1, vector<int>(2,0));
		// Base case
		dp[n][0] = dp[n][1] = 0;
		for(int i=n-1; i>=0; i--) {
			for(int buy=0; buy<2; buy++) {
				if(buy) {
					int profit1 = dp[i+1][0] - prices[i];
					int profit2 = dp[i+1][1];
					dp[i][buy] = max(profit1, profit2);
				}
				else {
					int profit1 = dp[i+1][1] + prices[i];
					int profit2 = dp[i+1][0];
					dp[i][buy] = max(profit1, profit2);
				}
			}
		}
		return dp[0][1];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2)  + O(n) .. Recursion stack
	int maxProfit_mem_help(int n, int i, vector<int>& prices, int buy, vector<vector<int>>& dp) {
		// Base case
		if(i > n) {
			return 0;
		}
		if(dp[i][buy] != -1) {
			return dp[i][buy];
		}
		if(buy) {
			int profit1 = maxProfit_mem_help(n, i+1, prices, 0, dp) - prices[i];
			int profit2 = maxProfit_mem_help(n, i+1, prices, 1, dp);
			dp[i][buy] = max(profit1, profit2);
		}
		else {
			int profit1 = maxProfit_mem_help(n, i+1, prices, 1, dp) + prices[i];
			int profit2 = maxProfit_mem_help(n, i+1, prices, 0, dp);
			dp[i][buy] = max(profit1, profit2);
		}
		return dp[i][buy];
	}

	int maxProfit_mem(int n, int i, vector<int>& prices, int buy) {
		vector<vector<int>> dp(n+1, vector<int>(2, -1));
		return maxProfit_mem_help(n, i, prices, buy, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n)  .. Auxiliary stack space
	int maxProfit_rec(int n, int i, vector<int>& prices, int buy) {
		// Base case
		if(i > n) {
			return 0;
		}
		if(buy) {
			int profit1 = maxProfit_rec(n, i+1, prices, 0) - prices[i];
			int profit2 = maxProfit_rec(n, i+1, prices, 1);
			return max(profit1, profit2);
		}
		else {
			int profit1 = maxProfit_rec(n, i+1, prices, 1) + prices[i];
			int profit2 = maxProfit_rec(n, i+1, prices, 0);
			return max(profit1, profit2);
		}
	}

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int ans1 = maxProfit_rec(n-1, 0, prices, 1);
        // int ans2 = maxProfit_mem(n-1, 0, prices, 1);
        // int ans3 = maxProfit_dp(n, 0, prices);
        int ans4 = maxProfit_dp_space(n, 0, prices);
        return ans4;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> prices;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		prices.push_back(ele);
	}
	int ans = solve.maxProfit(prices);
	cout << ans << endl;
	return 0;
}