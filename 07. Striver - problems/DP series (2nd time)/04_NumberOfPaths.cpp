#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
	// Tabulation -> space optimization
	// Time : O(m*n)
	// Space : O(n)
	ll count_dp_space(int m, int n) {
		vector<ll> prev(n+2, 0);
		for(int i=1; i<=m+1; i++) {
			vector<ll> curr(n+2, 0); // 0th entry.. edge case
			for(int j=1; j<=n+1; j++) {
				if(i==1 && j==1) {
					curr[j] = 1;
				}
				else {
					ll up=0, left=0;
					if(i > 1) { // 0th row .. edge case
						up = prev[j];
					}
					if(n > 1) { // 0th col .. edge case
						left = curr[j-1];
					}
					curr[j] = (up + left);
				}
			}
			prev = curr;
		}
		return prev[n+1]; // curr of last iteration stored here
	}

	// Tabulation
	// Time : O(m*n)
	// Space : O(m*n)
	ll count_dp(int m, int n) {
		vector<vector<ll>> dp(m+2, vector<ll>(n+2, 0));
		dp[1][1] = 1; // Shifting of origin.. for edge case
		for(int i=1; i<=m+1; i++) {
			for(int j=1; j<=n+1; j++) {
				ll up=0, left=0;
				if(i > 1) { // 0th row .. edge case
					up = dp[i-1][j];
				}
				if(n > 1) { // 0th col .. edge case
					left = dp[i][j-1];
				}
				dp[i][j] = (up + left);
			}
		}
		return dp[m+1][n+1];
	}

	// Memoization
	// Time : O(m*n)
	// Space : O(m+n) .. Recursion stack
	ll count_mem_help(int m, int n, vector<vector<ll>>& dp) {
		if(m<0 || n<0) {
			return 0; // Edge case
		}
		if(m==0 && n==0) {
			return 1; // Base case
		}
		if(dp[m][n] != -1) {
			return dp[m][n];
		}
		ll up=0, left=0;
		if(m > 0) {
			up = count_mem_help(m-1, n, dp);
		}
		if(n > 0) {
			left = count_mem_help(m, n-1, dp);
		}
		return dp[m][n] = (up + left);
	}

	ll count_mem(int m, int n) {
		vector<vector<ll>> dp(m+1, vector<ll>(n+1,-1));
		return count_mem_help(m, n, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	ll count_rec(int m, int n) {
		if(m<0 || n<0) {
			return 0; // Edge case
		}
		if(m==0 && n==0) {
			return 1; // Base case
		}
		ll up=0, left=0;
		if(m > 0) {
			up = count_rec(m-1, n);
		}
		if(n > 0) {
			left = count_rec(m, n-1);
		}
		return (up + left);
	}

public:
	ll numberOfPaths(int m, int n) {
		// ll ans1 = count_rec(m-1, n-1);
		// ll ans2 = count_mem(m-1, n-1);
		// ll ans3 = count_dp(m-1, n-1);
		ll ans4 = count_dp_space(m-1, n-1);
		return ans4;
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	Solution solve;
	ll ans = solve.numberOfPaths(m, n);
	cout << ans << "\n";
	return 0;
}