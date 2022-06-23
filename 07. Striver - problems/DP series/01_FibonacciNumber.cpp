// Overlapping sub-problem

#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  Space optimization
	// Time : O(n)
	// Space : O(1)
	int fib_dp_space(int n) {
		if(n < 2) {
			return n;
		}
		int prev2 = 0, prev = 1; // fib(0) & fib(1)
		for(int i=2; i<=n; i++) {
			int curr = (prev2 + prev);
			prev2 = prev; // Updating previous values
			prev = curr;
		}
		return prev;  // Prev stores curr of last iteration
	}

	// DP .. Tabulation
	//    Time : O(n)
	//    Space : O(n)
	int fib_dp(int n) {
		vector<int> dp(n+1, -1);
		dp[0] = 0;
		dp[1] = 1;
		for(int i=2; i<=n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
	}

	// Memoization
	//    Time : O(n)
	//	  Space : O(n)
	int fib_mem_help(int n, vector<int>& dp) {
		if(dp[n] != -1) {
			return dp[n];
		}
		dp[n] = fib_mem_help(n-1,dp) + fib_mem_help(n-2,dp);
		return dp[n];
	}

	int fib_mem(int n) {
		vector<int> dp(n+1, -1);
		for(int i=0; i<2; i++) {
			dp[i] = i;
		}
		return fib_mem_help(n, dp);
	}

	// Brute-force .. Recursion
	// 		Time : O(2^n)
	//      Space : O(1)
	int fib_rec(int n) {
		if(n==1 || n==0) {
			return n;
		}
		return fib_rec(n-1) + fib_rec(n-2);
	}

public:
    int fib(int n) {
        int ans1 = fib_rec(n);
        int ans2 = fib_mem(n);
        int ans3 = fib_dp(n);
        int ans4 = fib_dp_space(n);
        return ans4;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	int ans = solve.fib(n);
	cout << ans << endl;
	return 0;
}