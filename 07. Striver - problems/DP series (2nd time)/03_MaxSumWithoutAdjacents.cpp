#include <bits/stdc++.h>
using namespace std;

class Solution{
	// Tabulation --> space optimization
	// Time : O(n)
	// Space : O(1)
	int maxSum_dp_space(int* arr, int n) {
		int prev=arr[0], prev2=0;
		for(int i=1; i<=n; i++) {
			int notTake = prev;
			int take = INT_MIN;
			if(i >= 1) {
				take = (prev2 + arr[i]);
			}
			int curr = max(notTake, take);
			prev2 = prev;
			prev = curr;
		}
		return prev;
	}

	// Tabulation
	// Time : O(n)
	// Space : O(n)
	int maxSum_dp(int* arr, int n) {
		if(n <= 1) {
			return arr[n];
		}
		vector<int> dp(n+1, 0);
		for(int i=0; i<1; i++) {
			dp[i+1] = arr[i];
		}
		for(int i=1; i<=n; i++) {
			int notTake = dp[i];
			int take = INT_MIN;
			if(i >= 1) {
				take = (dp[i-1] + arr[i]);
			}
			dp[i] = max(notTake, take);
		}
		return dp[n];
	}

	// Memoization
	// Time : O(n)
	// Space : O(n) + O(n) .. Recursion stack
	int maxSum_mem_help(int* arr, int n, vector<int>& dp) {
		if(n < 0) {
			return 0; // No more elements possible
		}
		if(dp[n] != -1) {
			return dp[n];
		}
		int notTake = maxSum_mem_help(arr, n-1, dp);
		int take = INT_MIN;
		if(n >= 2) {
			take = (maxSum_mem_help(arr, n-2, dp) + arr[n]);
		}
		return dp[n] = max(notTake, take);
	}

	int maxSum_mem(int* arr, int n) {
		vector<int> dp(n+1, -1);
		return maxSum_mem_help(arr, n, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	int maxSum_rec(int* arr, int n) {
		if(n <= 1) {
			return arr[n]; // No more elements possible
			// max. sum .. pick current element into sum
		}
		int notTake = maxSum_rec(arr, n-1);
		int take = INT_MIN;
		if(n >= 2) {
			take = (maxSum_rec(arr, n-2) + arr[n]);
		}
		return max(notTake, take);
	}

public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // int ans1 = maxSum_rec(arr, n-1);
	    // int ans2 = maxSum_mem(arr, n-1);
     	// int ans3 = maxSum_dp(arr, n-1);
	    int ans4 = maxSum_dp_space(arr, n-1);
	    return ans4;
	}
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int ans = solve.findMaxSum(arr, n);
	cout << ans << "\n";
	return 0;
}