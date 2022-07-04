#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
    // Time : O(n^3)
    // Space : O(n^2)
	int maxProfit_dp_space(int n, vector<int>& prices) {
		vector<vector<int>> nextIter(2, vector<int>(3,0));
		vector<vector<int>> currIter(2, vector<int>(3,0));
		for(int i=n-1; i>=0; i--) {
			for(int buy=0; buy<2; buy++) {
				for(int cap=1; cap<3; cap++) {
					if(buy == 1) {
						int profit1 = nextIter[0][cap] - prices[i];
						int profit2 = nextIter[1][cap];
						currIter[buy][cap] = max(profit1, profit2);
					}
					else if(buy == 0) {
						int profit1 = nextIter[1][cap-1] + prices[i];
						int profit2 = nextIter[0][cap];
						currIter[buy][cap] = max(profit1, profit2);
					}
				}
			}
			nextIter = currIter;
		}
		return nextIter[1][2]; // Sending index 0 to buy(1) with (2) caps.
	}

	// Tabulation
	// Time : O(n^3)
	// Space : O(n^3)
	int maxProfit_dp(int n, vector<int>& prices) {
		vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
		// Base case  ->  no need as 0 is set by default
		/*
		for(int j=0; j<=1; j++) { // i==n
			for(int k=0; k<=2; k++) {
				dp[n][j][k] = 0;
			}
		}
		for(int i=0; i<=n; i++) { // cap==0
			for(int j=0; j<=1; j++) {
				dp[i][j][0] = 0;
			}
		}
		*/
		for(int i=n-1; i>=0; i--) {
			for(int buy=0; buy<2; buy++) {
				for(int cap=1; cap<3; cap++) {
					if(buy == 1) {
						int profit1 = dp[i+1][0][cap] - prices[i];
						int profit2 = dp[i+1][1][cap];
						dp[i][buy][cap] = max(profit1, profit2);
					}
					else if(buy == 0) {
						int profit1 = dp[i+1][1][cap-1] + prices[i];
						int profit2 = dp[i+1][0][cap];
						dp[i][buy][cap] = max(profit1, profit2);
					}
				}
			}
		}
		return dp[0][1][2]; // Sending index 0 to buy(1) with (2) caps.
	}

	// Memoization
	// Time : O(n^3)
	// Space : O(n^3)  + O(n) .. Recursion stack
	int maxProfit_mem_help(int n, int i, vector<int>& prices, int buy, int cap, vector<vector<vector<int>>>& dp) {
		// Base case
		if(i==n || cap==0) {
			return 0;
		}
		if(dp[i][buy][cap] != -1) {
			return dp[i][buy][cap];
		}
		if(buy) {
			int profit1 = maxProfit_mem_help(n, i+1, prices, 0, cap, dp) - prices[i];
			int profit2 = maxProfit_mem_help(n, i+1, prices, 1, cap, dp);
			dp[i][buy][cap] = max(profit1, profit2);
		}
		else {
			int profit1 = maxProfit_mem_help(n, i+1, prices, 1, cap-1, dp) + prices[i];
			int profit2 = maxProfit_mem_help(n, i+1, prices, 0, cap, dp);
			dp[i][buy][cap] = max(profit1, profit2);
		}
		return dp[i][buy][cap];
	}

	int maxProfit_mem(int n, int i, vector<int>& prices, int buy, int cap) {
		vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,-1)));
		return maxProfit_mem_help(n, i, prices, buy, cap, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n)  .. Auxiliary recursion stack
	int maxProfit_rec(int n, int i, vector<int>& prices, int buy, int cap) {
		// Base case
		if(i==n || cap==0) {
			return 0;
		}
		if(buy == 1) {
			int profit1 = maxProfit_rec(n, i+1, prices, 0, cap) - prices[i];
			int profit2 = maxProfit_rec(n, i+1, prices, 1, cap);
			return max(profit1, profit2);
		}
		else {
			int profit1 = maxProfit_rec(n, i+1, prices, 1, cap-1) + prices[i];
			int profit2 = maxProfit_rec(n, i+1, prices, 0, cap);
			return max(profit1, profit2);
		}
	}

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int ans1 = maxProfit_rec(n, 0, prices, 1, 2);
        // int ans2 = maxProfit_mem(n, 0, prices, 1, 2);
        // int ans3 = maxProfit_dp(n, prices);
        int ans4 = maxProfit_dp_space(n, prices);
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