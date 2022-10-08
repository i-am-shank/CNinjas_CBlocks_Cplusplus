#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Memoization
	// Time : O(m*v)
	int count_mem_help(vector<int>& coins, int m, int v, vector<vector<int>>& dp) {
		if(v == 0) {
			return 0;
		}
		if(v<0 || m<0) { // coins over.. OR -ve target
			return 1e8; // as min. count is asked
		}
		if(dp[m][v] != -1) {
			return dp[m][v];
		}
		int notTake = count_mem_help(coins, m-1, v, dp);
		int take = 1e8;
		if(coins[m] <= v) {
			take = 1 + count_mem_help(coins, m, v-coins[m], dp);
		}
		return dp[m][v] = min(take, notTake);
	}

	int count_mem(vector<int>& coins, int m, int v) {
		vector<vector<int>> dp(m+1, vector<int>(v+1,-1));
		return count_mem_help(coins, m, v, dp);
	}

	// Recursion
	// Time : O(2^v) .. approx.
	int count_rec(vector<int>& coins, int m, int v) {
		if(v == 0) {
			return 0;
		}
		if(v<0 || m<0) { // coins over.. OR -ve target
			return 1e8; // as min. count is asked
		}
		int notTake = count_rec(coins, m-1, v);
		int take = 1e8;
		if(coins[m] <= v) {
			take = 1 + count_rec(coins, m, v-coins[m]);
		}
		return min(take, notTake);
	}

public:
	int minCoins(vector<int>& coins, int m, int v) {
		// int ans1 = count_rec(coins, m-1, v);
		int ans2 = count_mem(coins, m-1, v);
		if(ans2 >= 1e8) {
			ans2 = -1;
		}
		return ans2;
	}
};

int main() {
	int v, m;
	cin >> v >> m;
	vector<int> coins(m);
	for(int i=0; i<m; i++) {
		cin >> coins[i];
	}
	Solution solve;
	int ans = solve.minCoins(coins, m, v);
	cout << ans << "\n";
	return 0;
}