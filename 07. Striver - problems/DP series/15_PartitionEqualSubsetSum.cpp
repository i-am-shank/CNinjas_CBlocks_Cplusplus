#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n^2)
	// Space : O(n)
	bool subsetSum_dp_space(vector<int>& nums, int n, int sum) {
		vector<bool> prevRow(sum+1, false);
		prevRow[0] = true;
		for(int i=0; i<=n; i++) {
			vector<bool> currRow(sum+1, false);
			currRow[0] = true;
			for(int j=0; j<=sum; j++) {
				if(i == 0) {
					if(nums[0] <= j) {
                        currRow[nums[0]] = true;
                    }
				}
				else {
					bool take = false;
					if(nums[i] <= j) {
						take = prevRow[j-nums[i]];
					}
					bool notTake = prevRow[j];
					currRow[j] = (take || notTake);
				}
			}
			prevRow = currRow;
		}
		return prevRow[sum];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	bool subsetSum_dp(vector<int>& nums, int n, int sum) {
		vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
		for(int i=0; i<=n; i++) {
			dp[i][0] = true;
		}
        if(nums[0] <= sum) {
            dp[0][nums[0]] = true;
        }
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=sum; j++) {
				bool take = false;
				if(nums[i] <= j) {
					take = dp[i-1][j-nums[i]];
				}
				bool notTake = dp[i-1][j];
				dp[i][j] = (take || notTake);
			}
		}
		return dp[n][sum];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. Recursion stack
	bool subsetSum_mem_help(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
		if(sum == 0) {
			return true;
		}
		if(n == 0) {
			return nums[0] == sum;
		}
		if(dp[n][sum] != -1) {
			return dp[n][sum];
		}
		bool take = false;
		if(sum >= nums[n]) {
			take = subsetSum_mem_help(nums, n-1, sum-nums[n], dp);
		}
		bool notTake = subsetSum_mem_help(nums, n-1, sum, dp);
		dp[n][sum] = (take || notTake);
		return dp[n][sum];
	}

	bool subsetSum_mem(vector<int>& nums, int n, int sum) {
		vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
		return subsetSum_mem_help(nums, n, sum, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	bool subsetSum_rec(vector<int>& nums, int n, int sum) {
		if(sum == 0) {
			return true;
		}
		if(n == 0) {
			return nums[0] == sum;
		}
		bool take = false;
		if(sum >= nums[n]) {
			take = subsetSum_rec(nums, n-1, sum-nums[n]);
		}
		bool notTake = subsetSum_rec(nums, n-1, sum);
		return (take || notTake);
	}

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=0; i<n; i++) {
        	sum += nums[i];
        }
        if(sum % 2 != 0) {
        	return false;
        }
        // bool ans1 = subsetSum_rec(nums, n-1, sum/2);
        // bool ans2 = subsetSum_mem(nums, n-1, sum/2);
        bool ans3 = subsetSum_dp(nums, n-1, sum/2);
        // bool ans4 = subsetSum_dp_space(nums, n-1, sum/2);
        return ans3;
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
	bool ans = solve.canPartition(nums);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}