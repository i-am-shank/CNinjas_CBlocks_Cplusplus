#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n^2)
	// Space : O(n)
	int count_dp_space(int n, int amount, vector<int>& coins) {
		vector<int> prevRow(amount+1, 0);
		// Base case
		for(int i=0; i<=amount; i++) {
			if(i % coins[0] == 0) {
				prevRow[i] = (i / coins[0]);
			}
			else {
				prevRow[i] = INT_MAX;
			}
		}
		for(int i=1; i<=n; i++) {
			vector<int> currRow(amount+1, 0);
			for(int j=0; j<=amount; j++) {
				int notTake = prevRow[j];
				int take = 1e9;
				if(coins[i] <= j) {
					// We have infinite supply of 1 type of coin.
					// So after take.. call recursion at same index.
					// Next time.. it will have a choice of take/notTake further
					// Recursion calls will do terminate !!  (at base case)
					take = 1 + currRow[j-coins[i]];
				}
				currRow[j] = min(take, notTake);
			}
			prevRow = currRow;
		}
		return prevRow[amount];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int count_dp(int n, int amount, vector<int>& coins) {
		vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
		// Base case
		for(int i=0; i<=amount; i++) {
			if(i % coins[0] == 0) {
				dp[0][i] = (i / coins[0]);
			}
			else {
				dp[0][i] = INT_MAX;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=amount; j++) {
				int notTake = dp[i-1][j];
				int take = 1e9;
				if(coins[i] <= j) {
					// We have infinite supply of 1 type of coin.
					// So after take.. call recursion at same index.
					// Next time.. it will have a choice of take/notTake further
					// Recursion calls will do terminate !!  (at base case)
					take = 1 + dp[i][j-coins[i]];
				}
				dp[i][j] = min(take, notTake);
			}
		}
		return dp[n][amount];
	}

	// Memoization sometimes becomes faster than tabulation
	// Because test cases are designed as very less no. of possiblities checked in memoization
	// Whereas tabulation visits all the possible test cases.
	// Speed of memoization  ->  depends a lot on test cases.
	
	// Memoization
	// Time : O(n^2)
	// Space : O(n^2)  + Linear.. complex recursion stack
	int count_mem_help(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
		// Base case
		if(n == 0) {
			if(amount % coins[n] == 0) {
				return (amount / coins[n]);
			}
			return 1e9; // to avoid heap-overflow
		}
		if(dp[n][amount] != -1) {
			return dp[n][amount];
		}
		int notTake = count_mem_help(n-1, amount, coins, dp);
		int take = 1e9;
		if(coins[n] <= amount) {
			// We have infinite supply of 1 type of coin.
			// So after take.. call recursion at same index.
			// Next time.. it will have a choice of take/notTake further
			// Recursion calls will do terminate !!  (at base case)
			take = 1 + count_mem_help(n, amount-coins[n], coins, dp);
		}
		dp[n][amount] = min(take, notTake);
		return dp[n][amount];
	}

	int count_mem(int n, int amount, vector<int>& coins) {
		vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
		return count_mem_help(n, amount, coins, dp);
	}

	// Recursion
	// Time : O(a^n) .. Exponential (very complex)
	// Space : Linear .. complex recursion (stack)
	int count_rec(int n, int amount, vector<int>& coins) {
		// Base case
		if(n == 0) {
			if(amount % coins[n] == 0) {
				return (amount / coins[n]);
			}
			return 1e9; // to avoid heap-overflow
		}
		int notTake = count_rec(n-1, amount, coins);
		int take = 1e9;
		if(coins[n] <= amount) {
			// We have infinite supply of 1 type of coin.
			// So after take.. call recursion at same index.
			// Next time.. it will have a choice of take/notTake further
			// Recursion calls will do terminate !!  (at base case)
			take = 1 + count_rec(n, amount-coins[n], coins);
		}
		return min(take, notTake);
	}

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans1 = count_rec(n-1, amount, coins);
        // int ans2 = count_mem(n-1, amount, coins);
        // int ans3 = count_dp(n-1, amount, coins);
        int ans4 = count_dp_space(n-1, amount, coins);
        if(ans4 >= 1e8) {
        	return -1;
        }
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
	int ans = solve.coinChange(coins, amount);
	cout << ans << endl;
	return 0;
}