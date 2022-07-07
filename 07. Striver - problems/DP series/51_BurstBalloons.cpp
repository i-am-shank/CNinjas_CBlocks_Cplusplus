#include <bits/stdc++.h>
using namespace std;

// If we solve this problem in the order..
//    -> Can't divide the problem into smaller sub-problems
// So, solving the problem in reverse way.
//    -> this way, can divide into sub-problems
// Edges treated as 1  ->  added 1 on both edges.

class Solution {
	// Tabulation
	// Time : O(n^3)
	// Space : O(n^2)
	int maxCoins_dp(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n,0));
		for(int s=n-2; s>=1; s--) {
			for(int e=s; e<n-1; e++) {
				int maxCoins = -1e9;
				for(int i=s; i<=e; i++) {
					int coins = (nums[s-1]*nums[i]*nums[e+1]);
					coins += dp[s][i-1];
					coins += dp[i+1][e];
					maxCoins = max(maxCoins, coins);
				}
				dp[s][e] = maxCoins;
			}
		}
		return dp[1][n-2];
	}

	// Memoization
	// Time : O(n^3)
	// Space : O(n^2)  + O(n) .. Recursion stack
	int maxCoins_mem_help(vector<int>& nums, int s, int e, vector<vector<int>>& dp) {
		// Base case
		if(s > e) {
			return 0;
		}
		if(dp[s][e] != -1) {
			return dp[s][e];
		}
		int maxCoins = -1e9;
		for(int i=s; i<=e; i++) {
			int coins = (nums[s-1]*nums[i]*nums[e+1]);
			coins += maxCoins_mem_help(nums, s, i-1, dp);
			coins += maxCoins_mem_help(nums, i+1, e, dp);
			maxCoins = max(maxCoins, coins);
		}
		dp[s][e] = maxCoins;
		return dp[s][e];
	}

	int maxCoins_mem(vector<int>& nums, int s, int e) {
		int n = nums.size();
		vector<vector<int>> dp(n-1, vector<int>(n-1,-1));
		return maxCoins_mem_help(nums, s, e, dp);
	}

	// Recursion
	// Time : Exponential
	// Space : O(n)  .. Recursion stack
	int maxCoins_rec(vector<int>& nums, int s, int e) {
		// Base case
		if(s > e) {
			return 0;
		}
		int maxCoins = -1e9;
		for(int i=s; i<=e; i++) {
			int coins = (nums[s-1]*nums[i]*nums[e+1]);
			coins += maxCoins_rec(nums, s, i-1);
			coins += maxCoins_rec(nums, i+1, e);
			maxCoins = max(maxCoins, coins);
		}
		return maxCoins;
	}

public:
    int maxCoins(vector<int>& nums) {
    	nums.push_back(1);
    	nums.insert(nums.begin(), 1);
    	int n = nums.size();
        // int ans1 = maxCoins_rec(nums, 1, n-2);
        // int ans2 = maxCoins_mem(nums, 1, n-2);
        int ans3 = maxCoins_dp(nums);
        return ans3;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	Solution solve;
	int ans = solve.maxCoins(nums);
	cout << ans << endl;
	return 0;
}