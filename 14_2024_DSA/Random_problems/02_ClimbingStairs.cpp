#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation + space-optimization
	// Time : O(n)
	// Space : O(1)
	int count_dp_space(int n) {
		if(n==0 || n==1) {
			return 1;
		}
		int a=1, b=1;
		for(int i=2; i<=n; i++) {
			int c = (a + b);
			a = b;
			b = c;
		}
		return b;
	}

	// Tabulation
	// Time : O(n)
	// Space : O(n)
	//    .. dp-array
	int count_dp(int n) {
		if(n==0 || n==1) {
			return 1;
		}
		vector<int> dp(n+1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2; i<=n; i++) {
			dp[i] = (dp[i-1] + dp[i-2]);
		}
		return dp[n];
	}

	// Memoisation
	// Time : O(n)
	// Space : O(n) + O(n)
	//     .. mem-array + stack-space
	int count_mem_help(int n, vector<int>& dp) {
		if(n==0 || n==1) {
			return 1;
		}
		if(dp[n] != -1) {
			return dp[n];
		}
		int ans1 = count_mem_help(n-1, dp);
		int ans2 = 0;
		if(n >= 2) {
			ans2 = count_mem_help(n-2, dp);
		}
		return dp[n] = (ans1 + ans2);
	}

	int count_mem(int n) {
		vector<int> dp(n+1, -1);
		return count_mem_help(n, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. recursion stack
	int count(int n) {
		if(n==0 || n==1) {
			return 1;
		}
		int ans1 = count(n-1);
		int ans2 = 0;
		if(n >= 2) {
			ans2 = count(n-2);
		}
		return (ans1 + ans2);
	}

public:
    int climbStairs(int n) {
        // int ans = count(n);
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
	int ans = solve.climbStairs(n);
	cout << ans << "\n";
	return 0;
}