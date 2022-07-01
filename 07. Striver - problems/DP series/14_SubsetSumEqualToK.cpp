#include <bits/stdc++.h>
using namespace std;

// Tabulation  ->  space optimization
// Time : O(n*k)
// Space : O(k)

bool subsetSum_dp_space(int n, int k, vector<int>& arr) {
	vector<bool> prevRow(k+1, 0);
	prevRow[0] = true;
	for(int i=0; i<=n; i++) {
		vector<bool> currRow(k+1, 0);
		currRow[0] = true;
		for(int j=1; j<=k; j++) {
			if(i == 0) {
				if(j == arr[0]) {
					currRow[j] = true;
				}
				else {
					currRow[j] = false;
				}
			}
			else {
				bool take = false;
				if(j-arr[i] >= 0) {
					take = prevRow[j-arr[i]];
				}
				bool notTake = prevRow[j];
				currRow[j] = (take || notTake);
			}
		}
		prevRow = currRow;
	}
	return prevRow[k]; // Stores last iteration
}

// Tabulation
// Time : O(n*k)
// Space : O(n*k)
bool subsetSum_dp(int n, int k, vector<int>& arr) {
	vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
	for(int i=0; i<=n; i++) {
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			bool take = false;
			if(j-arr[i] >= 0) {
				take = dp[i-1][j-arr[i]];
			}
			bool notTake = dp[i-1][j];
			dp[i][j] = (take || notTake);
		}
	}
	return dp[n][k];
}

// Memoization
// Time : O(n*k)
// Space : O(n*k)  + O(n) .. Recursion stack
bool subsetSum_mem_help(int n, int k, vector<int>& arr, vector<vector<int>>& dp) {
	if(k == 0) {
		return true;
	}
	if(n == 0) {
		return (arr[0] == k);
	}
	if(dp[n][k] != -1) {
		return dp[n][k];
	}
	bool take = false;
	if(k-arr[n] >= 0) {
		take = subsetSum_mem_help(n-1, k-arr[n], arr, dp);
	}
	bool notTake = subsetSum_mem_help(n-1, k, arr, dp);
	dp[n][k] = (take || notTake);
	return dp[n][k];
}

bool subsetSum_mem(int n, int k, vector<int>& arr) {
	vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
	return subsetSum_mem_help(n, k, arr, dp);
}

// Recursion
// Time : O(2^n)
// Space : O(n)  ..  Recursion stack
bool subsetSum_rec(int n, int k, vector<int>& arr) {
	if(k == 0) {
		return true;
	}
	if(n == 0) {
		return (arr[0] == k);
	}
	bool take = false;
	if(k-arr[n] >= 0) {
		take = subsetSum_rec(n-1, k-arr[n], arr);
	}
	bool notTake = subsetSum_rec(n-1, k, arr);
	return (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	// bool ans1 = subsetSum_rec(n-1, k, arr);
	// bool ans2 = subsetSum_mem(n-1, k, arr);
	// bool ans3 = subsetSum_dp(n-1, k, arr);
	bool ans4 = subsetSum_dp_space(n-1, k, arr);
	return ans4;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr;
		for(int i=0; i<n; i++) {
			int ele;
			cin >> ele;
			arr.push_back(ele);
		}
		bool ans = subsetSumToK(n, k, arr);
		cout << (ans == true ? "true" : "false") << endl;
	}
	return 0;
}