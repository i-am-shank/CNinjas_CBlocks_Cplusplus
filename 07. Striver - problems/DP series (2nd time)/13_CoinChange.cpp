#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
	// Tabulation -> space optimization
	// Time : O(n^2)
	// Space : O(n)
	ll count_dp_space(vector<int>& coins, int n, int sum) {
		vector<ll> prev(sum+1,0);
		for(int j=0; j<=sum; j++) { // Base case
			if(j % coins[0] == 0) {
				prev[j] = 1;
			}
		}
		for(int i=1; i<=n; i++) {
			vector<ll> curr(sum+1,0);
			for(int j=0; j<=sum; j++) {
				ll notTake = prev[j];
				ll take = 0;
				if(j >= coins[i]) {
					take = curr[j-coins[i]];
				}
				curr[j] = (take + notTake);
			}
			prev = curr;
		}
		return prev[sum];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	ll count_dp(vector<int>& coins, int n, int sum) {
		vector<vector<ll>> dp(n+1, vector<ll>(sum+1,0));
		for(int j=0; j<=sum; j++) { // Base case
			if(j % coins[0] == 0) {
				dp[0][j] = 1;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=sum; j++) {
				ll notTake = dp[i-1][j];
				ll take = 0;
				if(j >= coins[i]) {
					take = dp[i][j-coins[i]];
				}
				dp[i][j] = (take + notTake);
			}
		}
		return dp[n][sum];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. Recursion stack
	ll count_mem_help(vector<int>& coins, int n, int sum, vector<vector<ll>>& dp) {
		if(n == 0) {
			return (sum % coins[n] == 0);
		}
		ll notTake = count_mem_help(coins, n-1, sum, dp);
		ll take = 0;
		if(sum >= coins[n]) {
			take = count_mem_help(coins, n, sum-coins[n], dp);
		}
		return dp[n][sum] = (take + notTake);
	}

	ll count_mem(vector<int>& coins, int n, int sum) {
		// n , sum
		vector<vector<ll>> dp(n+1, vector<ll>(sum+1,-1));
		return count_mem_help(coins, n, sum, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	ll count_rec(vector<int>& coins, int n, int sum) {
		if(n == 0) {
			return (sum % coins[n] == 0);
		}
		ll notTake = count_rec(coins, n-1, sum);
		ll take = 0;
		if(sum >= coins[n]) {
			take = count_rec(coins, n, sum-coins[n]);
		}
		return (take + notTake);
	}

public:
	ll count(vector<int>& coins, int n, int sum) {
		// ll ans1 = count_rec(coins, n-1, sum);
		// ll ans2 = count_mem(coins, n-1, sum);
		// ll ans3 = count_dp(coins, n-1, sum);
		ll ans4 = count_dp_space(coins, n-1, sum);
		return ans4;
	}
};

int main() {
	Solution solve;
	int n, sum;
	cin >> n >> sum;
	vector<int> coins(n);
	for(int i=0; i<n; i++) {
		cin >> coins[i];
	}
	ll ans = solve.count(coins, n, sum);
	cout << ans << "\n";
	return 0;
}