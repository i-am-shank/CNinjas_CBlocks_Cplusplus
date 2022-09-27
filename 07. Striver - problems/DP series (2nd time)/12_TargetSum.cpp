#include <bits/stdc++.h>
using namespace std;

// Divide int 2 subsets with '+' & '-'
// ..in other words saying, no. of ways of getting s1 & s2
// ..such that  s1-s2 == target

// s1 - s2 = target
// s1 + s2 = totalSum
// Subtracting both.. s2 = (totalSum - target) / 2

// Count no. of subsets with sum (s2).

class Solution {
	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. Recursion stack
	int count_mem_help(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
		if(n < 0) {
			return (sum == 0);
		}
		if(n == 0) {
			return ((sum==0) || (sum==arr[0]));
		}
		if(dp[n][sum] != -1) {
			return dp[n][sum];
		}
		int notTake = count_mem_help(arr, n-1, sum, dp);
		int take = 0;
		if(arr[n] <= sum) {
			take = count_mem_help(arr, n-1, sum-arr[n], dp);
		}
		return dp[n][sum] = (take+notTake);
	}

	int count_mem(vector<int>& arr, int n, int sum) {
		// n , sum
		vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
		return count_mem_help(arr, n, sum, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(1)
	int count_rec(vector<int>& arr, int n, int sum) {
		if(n < 0) {
			return (sum == 0);
		}
		if(n == 0) {
			return ((sum==0) || (sum==arr[0]));
		}
		int notTake = count_rec(arr, n-1, sum);
		int take = 0;
		if(arr[n] <= sum) {
			take = count_rec(arr, n-1, sum-arr[n]);
		}
		return (take+notTake);
	}

public:
    int findTargetSumWays(vector<int>& arr ,int target) {
        int sum = 0, n = arr.size();
        for(int i=0; i<n; i++) {
        	sum += arr[i];
        }
        int targetSum = (sum - target), numZeros = 0;
        if(targetSum<0 || (targetSum % 2) != 0) {
        	return 0; // No possiblility of decimal sum
        	// (as all elements are integers)
        }
        targetSum /= 2;
        vector<int> nums;
        for(int i=0; i<n; i++) {
        	if(arr[i] == 0) {
        		numZeros++;
        	}
        	else {
        		nums.push_back(arr[i]);
        	}
        }
        int size = nums.size();
        // int ans1 = count_rec(nums, size-1, targetSum);
        int ans2 = count_mem(nums, size-1, targetSum);
        return (ans2 * pow(2,numZeros));
    }
};

int main() {
	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	int ans = solve.findTargetSumWays(arr, target);
	cout << ans << "\n";
	return 0;
}