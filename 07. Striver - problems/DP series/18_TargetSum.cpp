// Count subset partitions with difference = target

// Let partitions have sum as sum1 & sum2, such that :
//  (sum2 - sum1) = target

// Further solving :
//  (totalSum - sum1) - sum1 = target
//  totalSum - (2 * sum1) = target
//  sum1  =  (totalSum - target) / 2

//  The problem is converted to finding no. of subsets with sum as sum1 

#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n^2)
    // Space : O(n)
	int count_dp_space(vector<int> nums, int n, int sum) {
		vector<int> prevRow(sum+1,0);
		if(nums[0] == 0) {
			prevRow[0] = 2;
		}
		else {
			prevRow[0] = 1;
		}
		if(nums[0]<=sum && nums[0]!=0) {
			prevRow[nums[0]] = 1;
		}
		for(int i=1; i<=n; i++) {
			vector<int> currRow(sum+1,0);
			for(int j=0; j<=sum; j++) {
				int take = 0;
				if(nums[i] <= j) {
					take = prevRow[j-nums[i]];
				}
				int notTake = prevRow[j];
				currRow[j] = (take + notTake);
			}
			prevRow = currRow;
		}
		return prevRow[sum];  // Contains value corresponding to last iteration
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int count_dp(vector<int> nums, int n, int sum) {
		vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
		if(nums[0] == 0) {
			dp[0][0] = 2;
		}
		else {
			dp[0][0] = 1;
		}
		if(nums[0] <= sum  &&  nums[0]!=0) {
			dp[0][nums[0]] = 1;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=sum; j++) {
				int take = 0;
				if(nums[i] <= j) {
					take = dp[i-1][j-nums[i]];
				}
				int notTake = dp[i-1][j];
				dp[i][j] = (take + notTake);
			}
		}
		return dp[n][sum];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2)  + O(n) .. Recursion stack
	int count_mem_help(vector<int> nums, int n, int sum, vector<vector<int>>& dp) {
		if(n == 0) {
			if(sum == nums[0]) {
				if(sum == 0) {
					return 2;
				}
				return 1;
			}
			if(sum == 0) {
				return 1;
			}
			return 0;
		}
		if(dp[n][sum] != -1) {
			return dp[n][sum];
		}
		int take = 0;
		if(nums[n] <= sum) {
			take = count_mem_help(nums, n-1, sum-nums[n], dp);
		}
		int notTake = count_mem_help(nums, n-1, sum, dp);
		dp[n][sum] = (take + notTake);
		return dp[n][sum];
	}

	int count_mem(vector<int> nums, int n, int sum) {
		vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
		return count_mem_help(nums, n, sum, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n)  .. Recursion stack
	int count_rec(vector<int> nums, int n, int sum) {
		if(n == 0) {
			if(sum == nums[0]) {
				if(sum == 0) {
					return 2;
				}
				return 1;
			}
			if(sum == 0) {
				return 1;
			}
			return 0;
		}
		int take = 0;
		if(nums[n] <= sum) {
			take = count_rec(nums, n-1, sum-nums[n]);
		}
		int notTake = count_rec(nums, n-1, sum);
		return (take + notTake);
	}

public:
    int findTargetSumWays(vector<int>& nums, int target) {
    	target = abs(target);
        int totalSum = 0, n = nums.size();
        for(int i=0; i<n; i++) {
        	totalSum += nums[i];
        }
        if((totalSum-target < 0)  ||  ((totalSum-target)%2 == 1)) {
        	return 0;
        }
        int sum = ((totalSum - target) / 2);
        // int ans1 = count_rec(nums, n-1, sum);
        // int ans2 = count_mem(nums, n-1, sum);
        // int ans3 = count_dp(nums, n-1, sum);
        int ans4 = count_dp_space(nums, n-1, sum);
        return ans4;
    }
};

int main() {
	Solution solve;
	int n, target;
	cin >> n >> target;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	int ans = solve.findTargetSumWays(nums, target);
	cout << ans << endl;
	return 0;
}