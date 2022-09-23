#include <bits/stdc++.h>
using namespace std;

class Solution{
	// Tabulation --> space optimization
	// Time : O(n^2)
	// Space : O(n)
	bool check_dp_space(vector<int>& arr, int n, int sum) {
		vector<bool> prev(sum+1,false);
		prev[0] = true;
		// For edge case of n<0  -->  shift of index
		for(int i=1; i<n+2; i++) {
			vector<bool> curr(sum+1, false);
			curr[0] = true;
			for(int j=1; j<=sum; j++) {
				bool notTake = prev[j];
				bool take = false;
				if(arr[i-1] <= j) {
					take = prev[j-arr[i-1]];
				}
				curr[j] = (take || notTake);
			}
			prev = curr;
		}
		return prev[sum];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	bool check_dp(vector<int>& arr, int n, int sum) {
		vector<vector<bool>> dp(n+2, vector<bool>(sum+1,false));
		for(int i=0; i<n+2; i++) {
			dp[i][0] = true; // If sum = 0 .. base case
		}
		// For edge case of n<0  -->  shift of index
		for(int i=1; i<n+2; i++) {
			for(int j=1; j<=sum; j++) {
				bool notTake = dp[i-1][j];
				bool take = false;
				if(arr[i-1] <= j) {
					take = dp[i-1][j-arr[i-1]];
				}
				dp[i][j] = (take || notTake);
			}
		}
		return dp[n+1][sum];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. Recursion stack
	bool check_mem_help(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
		if(sum == 0) {
			return true;
		}
		if(n < 0) {
			return false;
		}
		if(dp[n][sum] != -1) {
			return dp[n][sum];
		}
		bool notTake = check_mem_help(arr, n-1, sum, dp);
		bool take = false;
		if(arr[n] <= sum) {
			take = check_mem_help(arr, n-1, sum-arr[n], dp);
		}
		return dp[n][sum] = (take || notTake);
	}

	bool check_mem(vector<int>& arr, int n, int sum) {
		// n, sum
		vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
		return check_mem_help(arr, n, sum, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	bool check_rec(vector<int>& arr, int n, int sum) {
		if(sum == 0) {
			return true;
		}
		if(n < 0) {
			return false;
		}
		bool notTake = check_rec(arr, n-1, sum);
		bool take = false;
		if(arr[n] <= sum) {
			take = check_rec(arr, n-1, sum-arr[n]);
		}
		return (take || notTake);
	}

public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        // bool ans1 = check_rec(arr, n-1, sum);
        // bool ans2 = check_mem(arr, n-1, sum);
        // bool ans3 = check_dp(arr, n-1, sum);
        bool ans4 = check_dp_space(arr, n-1, sum);
        return ans4;
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
	bool ans = solve.isSubsetSum(arr, sum);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}