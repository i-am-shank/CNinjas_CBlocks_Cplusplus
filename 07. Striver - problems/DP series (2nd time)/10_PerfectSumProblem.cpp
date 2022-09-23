#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

class Solution {
	// Tabulation --> space optimization
	// Time : O(n^2)
	// Space : O(n)
	int count_dp_space(vector<int>& arr, int n, int sum) {
		vector<int> prev(sum+1,0);
		prev[0] = 1;
		for(int i=1; i<=n+1; i++) {
			vector<int> curr(sum+1,0);
			curr[0] = 1;
			for(int j=0; j<=sum; j++) {
				int notTake = prev[j]%mod;
				int take = 0;
				if(arr[i-1] <= j) {
					take = prev[j-arr[i-1]]%mod;
				}
				curr[j] = ((take%mod) + (notTake%mod))%mod;
			}
			prev = curr;
		}
		return prev[sum];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int count_dp(vector<int>& arr, int n, int sum) {
		vector<vector<int>> dp(n+2, vector<int>(sum+1,0));
		for(int i=0; i<=n; i++) {
			dp[i][0] = 1; // sum = 0
		}
		for(int i=1; i<=n+1; i++) {
			for(int j=0; j<=sum; j++) {
				int notTake = dp[i-1][j]%mod;
				int take = 0;
				if(arr[i-1] <= j) {
					take = dp[i-1][j-arr[i-1]]%mod;
				}
				dp[i][j] = ((take%mod) + (notTake%mod))%mod;
			}
		}
		return dp[n+1][sum];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. Recursion stack
	int count_mem_help(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
		if(sum == 0) {
			return 1;
		}
		if(n == 0) {
			return (arr[n] == sum);
		}
		if(dp[n][sum] != -1) {
			return dp[n][sum] % mod;
		}
		int notTake = count_mem_help(arr, n-1, sum, dp)%mod;
		int take = 0;
		if(arr[n] <= sum) {
			take = count_mem_help(arr, n-1, sum-arr[n], dp)%mod;
		}
		dp[n][sum] = ((take%mod) + (notTake%mod))%mod;
		return dp[n][sum];
	}

	int count_mem(vector<int>& arr, int n, int sum) {
		vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
		return count_mem_help(arr, n, sum, dp) % mod;
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	int count_rec(vector<int>& arr, int n, int sum) {
		if(sum == 0) {
			return 1;
		}
		if(n == 0) {
			if(arr[0] == sum) {
				return 1;
			}
			return 0;
		}
		int notTake = count_rec(arr, n-1, sum)%mod;
		int take = 0;
		if(arr[n] <= sum) {
			take += count_rec(arr, n-1, sum-arr[n])%mod;
		}
		return ((take%mod) + (notTake%mod))%mod;
	}

public:
	int perfectSum(vector<int>& arr, int n, int sum) {
		n = arr.size();
		int zeros = 0;
		vector<int> nums;
		for(int i=0; i<n; i++) {
			if(arr[i] == 0) {
				zeros++;
			}
			else {
				nums.push_back(arr[i]);
			}
		}
		n = nums.size();
        // int ans1 = count_rec(nums, n-1, sum)%mod;
        // int ans2 = count_mem(nums, n-1, sum) % mod;
        // int ans3 = count_dp(nums, n-1, sum) % mod;
        int ans4 = count_dp_space(nums, n-1, sum) % mod;
        return (ans4 * ((int)pow(2,zeros)%mod)) % mod;
	}
};

int main() {
	int n, sum;
	cin >> n >> sum;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	int ans = solve.perfectSum(arr, n, sum);
	cout << ans << "\n";
	return 0;
}