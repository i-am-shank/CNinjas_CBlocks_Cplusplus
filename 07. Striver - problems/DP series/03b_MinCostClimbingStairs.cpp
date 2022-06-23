#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n)
	// Space : O(1)
	int minCost_dp_space(int n, vector<int>& cost) {
		if(n == 0) {
			return 0;
		}
		int prev2 = 0, prev = 0;
		for(int i=n-1; i>=0; i--) {
			int curr = cost[i] + (min(prev2, prev));
			prev2 = prev;
			prev = curr;
		}
		return min(prev, prev2);
	}

	// Tabulation .. bottom-up
	// Time : O(n)
	// Space : O(n)
	int minCost_dp(int n, vector<int>& cost) {
		vector<int> dp(n+1, -1);
		for(int i=n; i>=n-1 && i>=0; i--) {
			if(i == n-1) {
				dp[i] = cost[n-1];
				continue;
			}
			dp[i] = 0;
		}
		for(int i=n-2; i>=0; i--) {
			dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
		}
		if(n > 1) {
			return min(dp[0], dp[1]);
		}
		return dp[0];
	}

	// Memoization .. top-down
	// Time : O(n)
	// Space : O(n)
	int minCost_mem_help(int n, vector<int>& cost, int i, vector<int>& dp) {
		if(dp[i] != -1) {
			return dp[i];
		}
		int cost1 = minCost_mem_help(n, cost, i+1, dp);
		int cost2 = minCost_mem_help(n, cost, i+2, dp);
		dp[i] = cost[i] + min(cost1, cost2);
		return dp[i];
	}

	int minCost_mem(int n, vector<int>& cost, int i) {
		vector<int> dp(n+1, -1);
		for(int j=n; j>=n-1 && j>=0; j--) {
			if(j == n-1) {
				dp[j] = cost[n-1];
				continue;
			}
			dp[j] = 0;
		}
		int ans1 = minCost_mem_help(n, cost, i, dp);
		int ans2 = INT_MAX;
		if(i < n-1) {
			ans2 = minCost_mem_help(n, cost, i+1, dp);
		}
		return min(ans1, ans2);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(1)
	int minCost_rec(int n, vector<int>& cost, int i) {
		if(i == n) {
			return 0;
		}
		if(i == n-1) {
			return cost[n-1];
		}
		int minCost = INT_MAX;
		for(int j=1; j<=2; j++) {
			if(i+j <= n) {  // j-step climbing
				int costj = cost[i] + minCost_rec(n, cost, i+j);
				minCost = min(minCost, costj);
			}
		}
		return minCost;
	}

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        /* int ans1 = min(minCost_rec(n, cost, 0) , minCost_rec(n, cost, 1));
        int ans2 = min(minCost_mem(n, cost, 0) , minCost_mem(n, cost, 1));
        int ans3 = minCost_dp(n, cost); */
        int ans4 = minCost_dp_space(n, cost);
        return ans4;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> cost;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		cost.push_back(ele);
	}
	int ans = solve.minCostClimbingStairs(cost);
	cout << ans << endl;
	return 0;
}