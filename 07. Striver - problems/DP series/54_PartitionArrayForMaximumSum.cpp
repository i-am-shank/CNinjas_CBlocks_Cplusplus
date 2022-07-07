#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation
	// Time : O(n^2)
	// Space : O(n)
	int maxSum_dp(vector<int>& arr, int k) {
		int n = arr.size();
		vector<int> dp(n+1, 0);
		// Base case  ->  no need
		for(int i=n-1; i>=0; i--) {
			int maxSum = -1e9;
			for(int j=i; j<i+k && j<n ; j++) {
				int maxEle = -1e9;
				for(int l=i; l<=j; l++) { // Finding max
					maxEle = max(arr[l], maxEle);
				}
				int sum = ((j-i+1) * maxEle);
				sum += dp[j+1];
				maxSum = max(maxSum, sum);
			}
			dp[i] = maxSum;
		}
		return dp[0];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n)  + O(n) .. Recursion stack
	int maxSum_mem_help(int n, int i, vector<int>& arr, int k, vector<int>& dp) {
		// Base case
		if(i >= n) {
			return 0;
		}
		if(dp[i] != -1) {
			return dp[i];
		}
		int maxSum = -1e9;
		for(int j=i; j<i+k && j<n ; j++) {
			int maxEle = -1e9;
			for(int l=i; l<=j; l++) { // Finding max
				maxEle = max(arr[l], maxEle);
			}
			int sum = ((j-i+1) * maxEle);
			sum += maxSum_mem_help(n, j+1, arr, k, dp);
			maxSum = max(maxSum, sum);
		}
		dp[i] = maxSum;
		return dp[i];
	}

	int maxSum_mem(int n, int i, vector<int>& arr, int k) {
		vector<int> dp(n+1,-1);
		return maxSum_mem_help(n, i, arr, k, dp);
	}

	// Recursion
	// Time : Exponential
	// Space : O(n) .. Recursion stack
	int maxSum_rec(int n, int i, vector<int>& arr, int k) {
		// Base case
		if(i >= n) {
			return 0;
		}
		int maxSum = -1e9;
		for(int j=i; j<i+k && j<n ; j++) {
			int maxEle = -1e9;
			for(int l=i; l<=j; l++) { // Finding max
				maxEle = max(arr[l], maxEle);
			}
			int sum = ((j-i+1) * maxEle);
			sum += maxSum_rec(n, j+1, arr, k);
			maxSum = max(maxSum, sum);
		}
		return maxSum;
	}

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // int ans1 = maxSum_rec(n, 0, arr, k);
        // int ans2 = maxSum_mem(n, 0, arr, k);
        int ans3 = maxSum_dp(arr, k);
        return ans3;
    }
};

int main() {
	Solution solve;
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		arr.push_back(ele);
	}
	int ans = solve.maxSumAfterPartitioning(arr, k);
	cout << ans << endl;
	return 0;
}