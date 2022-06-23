// 1. Try to represent problem in terms of index.
// 2. Do all possible stuffs on that index, according to problem statement
// 3. If asks total no. of ways  ->  sum up all ways
// 4. Find min/max  ->  Find min/max.


#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  Space optimization
	// Time : O(n)
	// Space : O(1)
	int count_dp_space(int n) {
		if(n < 2) {
			return 1;
		}
		int prev2 = 1, prev = 1;  // 0th & 1st values
		for(int i=2; i<=n; i++) {
			int curr = (prev2 + prev);
			prev2 = prev;
			prev = curr;
		}
		return prev; // prev stores curr of last iteration
	}

	// DP.. Tabulation
	// Time : O(n)
	// Space : O(n)
	int count_dp(int n) {
		vector<int> dp(n+1, -1);
		for(int i=0; i<=n; i++) {
			if(i<2) {
				dp[i] = 1;
				continue;
			}
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
	}

	// Memoization
	// Time : O(n)
	// Space : O(n)
	int count_mem_help(int n, vector<int>& dp) {
		if(dp[n] != -1) {
			return dp[n];
		}
		dp[n] = count_mem_help(n-1, dp) + count_mem_help(n-2, dp);
		return dp[n];
	}

	int count_mem(int n) {
		if(n <= 1) {
			return 1;
		}
		vector<int> dp(n+1, -1);
		for(int i=0; i<2 && i<=n; i++) {
			dp[i] = 1;
		}
		return count_mem_help(n, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(1)
	int count_rec(int n) {
		if(n <= 1) {
			return 1;
		}
		int smallAns1 = count_rec(n-1); // 1st step  ->  1
		int smallAns2 = count_rec(n-2); // 1st step  ->  2
		return (smallAns1 + smallAns2);
	}

public:
    int climbStairs(int n) {
        int ans1 = count_rec(n);
        int ans2 = count_mem(n);
        int ans3 = count_dp(n);
        int ans4 = count_dp_space(n);
        return ans4;
    }
};

int main() {
	int n;
	cin >> n;
	Solution solve;
	int ans = solve.climbStairs(n);
	cout << ans << endl;
	return 0;
}