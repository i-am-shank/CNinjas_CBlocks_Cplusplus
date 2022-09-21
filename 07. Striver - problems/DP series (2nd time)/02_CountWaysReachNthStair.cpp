#include <bits/stdc++.h>
using namespace std;

// Matrix exponentiation --> most optimal solution

class Solution {
	// Tabulation --> space optimization
	// Time : O(n)
	// Space : O(1)
	int count_dp_space(int n) {
		if(n==1 || n==2) {
			return n;
		}
		int prev=2, prev2=1;
		for(int i=3; i<=n; i++) {
			int curr = (prev + prev2);
			prev2 = prev;
			prev = curr;
		}
		return prev;
	}

	// Tabulation
	// Time : O(n)
	// Space : O(n)
	int count_dp(int n) {
		if(n==1 || n==2) {
			return n;
		}
		vector<int> dp(n+1, 0);
		dp[1] = 1;
		dp[2] = 2;
		for(int i=3; i<=n; i++) {
			dp[i] = (dp[i-1] + dp[i-2]);
		}
		return dp[n];
	}

	// Memoization
	// Time : O(n)
	// Space : O(n) + O(n) .. Recursion stack
	int count_mem_help(int n, vector<int>& dp) {
		if(n==1 || n==2) {
			return n;
		}
		if(dp[n] != -1) {
			return dp[n];
		}
		dp[n] = (count_mem_help(n-1,dp) + count_mem_help(n-2,dp));
		return dp[n];
	}

	int count_mem(int n) {
		vector<int> dp(n+1, -1);
		return count_mem_help(n, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	int count_rec(int n) {
		if(n==1 || n==2) {
			return n;
		}
		return (count_rec(n-1) + count_rec(n-2));
	}

public:
	int countWays(int n) {
		// int ans1 = count_rec(n);
		// int ans2 = count_mem(n);
		// int ans3 = count_dp(n);
		int ans4 = count_dp_space(n);
		return ans4;
	}
};

int main() {
	int n;
	cin >> n;
	Solution solve;
	int ans = solve.countWays(n);
	cout << ans << "\n";
	return 0;
}