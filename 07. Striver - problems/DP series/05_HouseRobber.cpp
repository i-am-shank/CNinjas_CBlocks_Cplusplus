// Maximum sum of Non-adjacent elements


#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation -> space optimization
	// Time : O(n)
	// Space : O(1)
	int rob_dp_space(vector<int>& nums, int n) {
		if(n == 0) {
			return 0;
		}
		int prev2 = 0, prev = nums[n-1];
		for(int i=n-2; i>=0; i--) {
			int curr = max(nums[i]+prev2 , prev);
			prev2 = prev;
			prev = curr;
		}
		return prev;  // Stores curr of last iteration
	}

	// Tabulation
	// Time : O(n)
	// Space : O(n)
	int rob_dp(vector<int>& nums, int n) {
		vector<int> dp(n+1, -1);
		dp[n] = 0;
		if(n > 1) {
			dp[n-1] = nums[n-1];
		}
		for(int i=n-2; i>=0; i--) {
			int take = nums[i] + dp[i+2];
			int notTake = dp[i+1];
			dp[i] = max(take, notTake);
		}
		return dp[0];
	}

	// Memoization
	// Time : O(n)
	// Space : O(n)
	int rob_mem_help(vector<int>& nums, int n, int i, vector<int>& dp) {
		if(dp[i] != -1) {
			return dp[i];
		}
		int take = nums[i] + rob_mem_help(nums, n, i+2, dp);
		int notTake = rob_mem_help(nums, n, i+1, dp);
		dp[i] = max(take, notTake);
		return dp[i];
	}

	int rob_mem(vector<int>& nums, int n, int i) {
		vector<int> dp(n+1, -1);
		dp[n] = 0;
		if(n > 1) {
			dp[n-1] = nums[n-1];
		}
		int ans = rob_mem_help(nums, n, i, dp);
		return ans;
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(1)
	int rob_rec(vector<int>& nums, int n, int i) {
		if(i == n-1) {
			return nums[n-1];
		}
		if(i >= n) {
			return 0;
		}
		int take = nums[i] + rob_rec(nums, n, i+2);
		int notTake = rob_rec(nums, n, i+1);
		return max(take, notTake);
	}

public:
    int rob(vector<int>& nums) {
    	int n = nums.size();
        int ans1 = rob_rec(nums, n, 0);
        int ans2 = rob_mem(nums, n, 0);
        int ans3 = rob_dp(nums, n);
        int ans4 = rob_dp_space(nums, n);
        return ans4;
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
	int ans = solve.rob(nums);
	cout << ans << endl;
	return 0;
}