#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n^2)
	// Space : O(n)
	int count_dp_space(int n, int amount, vector<int>& coins) {
		vector<int> prevRow(amount+1,0);
		// Base case
		for(int i=0; i<=amount; i++) {
			if(i % coins[0] == 0) {
				prevRow[i] = 1;
			}
			else {
				prevRow[i] = 0;
			}
		}
		for(int i=1; i<=n; i++) {
			vector<int> currRow(amount+1, 0);
			for(int j=0; j<=amount; j++) {
				int notTake = prevRow[j];
				int take = 0;
				if(coins[i] <= j) {
					take = currRow[j-coins[i]];
				}
				currRow[j] = (notTake + take);
			}
			prevRow = currRow;
		}
		return prevRow[amount];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int count_dp(int n, int amount, vector<int>& coins) {
		vector<vector<int>> dp(n+1, vector<int>(amount+1,0));
		// Base case
		for(int i=0; i<=amount; i++) {
			if(i % coins[0] == 0) {
				dp[0][i] = 1;
			}
			else {
				dp[0][i] = 0;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=amount; j++) {
				int notTake = dp[i-1][j];
				int take = 0;
				if(coins[i] <= j) {
					take = dp[i][j-coins[i]];
				}
				dp[i][j] = (notTake + take);
			}
		}
		return dp[n][amount];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + Linear .. complex recursion stack
	int count_mem_help(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
		if(n == 0) {
			if(amount % coins[n] == 0) {
				return 1;
			}
			return 0;
		}
		if(dp[n][amount] != -1) {
			return dp[n][amount];
		}
		int notTake = count_mem_help(n-1, amount, coins, dp);
		int take = 0;
		if(coins[n] <= amount) {
			take = count_mem_help(n, amount-coins[n], coins, dp);
		}
		dp[n][amount] = (notTake + take);
		return dp[n][amount];
	}

	int count_mem(int n, int amount, vector<int>& coins) {
		vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
		return count_mem_help(n, amount, coins, dp);
	}

	// Recursion
	// Time : Exponential
	// Space : Linear  .. both complex
	int count_rec(int n, int amount, vector<int>& coins) {
		if(n == 0) {
			if(amount % coins[n] == 0) {
				return 1;
			}
			return 0;
		}
		int notTake = count_rec(n-1, amount, coins);
		int take = 0;
		if(coins[n] <= amount) {
			take = count_rec(n, amount-coins[n], coins);
		}
		return (notTake + take);
	}

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // int ans1 = count_rec(n-1, amount, coins);
        // int ans2 = count_mem(n-1, amount, coins);
        // int ans3 = count_dp(n-1, amount, coins);
        int ans4 = count_dp_space(n-1, amount, coins);
        return ans4;
    }
};

int main() {
	Solution solve;
	int n, amount;
	cin >> n >> amount;
	vector<int> coins;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		coins.push_back(ele);
	}
	int ans = solve.change(amount, coins);
	cout << ans << endl;
	return 0;
}