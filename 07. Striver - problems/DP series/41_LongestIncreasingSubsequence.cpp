#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Using Binary Search
	// Time : O(n * logn)
	// Space : O(n)
	int lisBinarySearch(int n, vector<int>& nums) {
		vector<int> lis; // Not generating lis
		// Just a vector of same length as lis.
		lis.push_back(nums[0]);
		for(int i=1; i<n; i++) {
			if(nums[i] > lis.back()) {
				lis.push_back(nums[i]);
			}
			else {
				int index = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
				lis[index] = nums[i];
			}
		}
		return lis.size();
	}

	// Tabulation  ->  A Unique approach (for LIS)
	// Time : O(n^2)
	// Space : O(n)
	int lis_tab(int n, vector<int>& nums) {
		vector<int> dp(n, 1);
		int lis = 1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<i; j++) {
				if(nums[j] < nums[i]) {
					dp[i] = max(dp[i], 1+dp[j]);
				}
			}
			lis = max(lis, dp[i]);
		}
		return lis;
	}

	// Tabulation  ->  space optimization
	// Time : O(n^2)
	// Space : O(n)
	int lis_dp_space(int n, vector<int>& nums) {
		vector<int> nextRow(n+1, 0);
		// Base case  ->  no need (as default assign 0)
		for(int i=n-1; i>=0; i--) {
			vector<int> currRow(n+1, 0);
			for(int last=i; last>=0; last--) {
				int take = 0;
				if((last == 0)  ||  (nums[i] > nums[last-1])) {
					take = 1 + nextRow[i+1];
				}
				int notTake = nextRow[last];
				currRow[last] = max(take, notTake);
			}
			nextRow = currRow;
		}
		return nextRow[0];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int lis_dp(int n, vector<int>& nums) {
		vector<vector<int>> dp(n+1, vector<int>(n+1,0));
		// Base case  ->  no need (as default assign 0)
		for(int i=n-1; i>=0; i--) {
			for(int last=i; last>=0; last--) {
				int take = 0;
				if((last == 0)  ||  (nums[i] > nums[last-1])) {
					take = 1 + dp[i+1][i+1];
				}
				int notTake = dp[i+1][last];
				dp[i][last] = max(take, notTake);
			}
		}
		return dp[0][0];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2)  + O(n) .. Recursion stack
	int lis_mem_help(int n, int i, vector<int>& nums, int last, vector<vector<int>>& dp) {
		// Base case
		if(i == n) {
			return 0;
		}
		if(dp[i][last] != -1) {
			return dp[i][last];
		}
		int take = 0;
		if((last == 0)  ||  (nums[i] > nums[last-1])) {
			take = 1 + lis_mem_help(n, i+1, nums, i+1, dp);
		}
		int notTake = lis_mem_help(n, i+1, nums, last, dp);
		dp[i][last] = max(take, notTake);
		return dp[i][last];
	}

	int lis_mem(int n, int i, vector<int>& nums, int last) {
		vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
		// In Recursion,  last  ->  [-1, n-1]
		// In Memoization, last ->  [0 , n]
		return lis_mem_help(n, i, nums, last, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n)  .. Auxiliary recursion stack
	int lis_rec(int n, int i, vector<int>& nums, int last) {
		// Base case
		if(i == n) {
			return 0;
		}
		int take = 0;
		if((last == -1)  ||  (nums[i] > nums[last])) {
			take = 1 + lis_rec(n, i+1, nums, i);
		}
		int notTake = lis_rec(n, i+1, nums, last);
		return max(take, notTake);
	}

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // int ans1 = lis_rec(n, 0, nums, -1);
        // int ans2 = lis_mem(n, 0, nums, 0);
        // int ans3 = lis_dp(n, nums);
        // int ans4 = lis_dp_space(n, nums);
        // int ans5 = lis_tab(n, nums);
        int ans6 = lisBinarySearch(n, nums);
        return ans6;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	int ans = solve.lengthOfLIS(nums);
	cout << ans << endl;
	return 0;
}