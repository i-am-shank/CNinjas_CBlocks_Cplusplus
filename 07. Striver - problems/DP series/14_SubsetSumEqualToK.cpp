#include <bits/stdc++.h>
using namespace std;

// Memoization
bool subsetSum_mem_help(int n, int k, vector<int>& arr, vector<vector<int>>& dp) {
	if(k == 0) {
		return true;
	}
	if(n == 0) {
		return (arr[n] == k);
	}
	if(dp[n][k] != -1) {
		return dp[n][k];
	}
	bool take = false;
	if(k-arr[n] >= 0) {
		take = subsetSum_rec(n-1, k-arr[n], arr);
	}
	bool notTake = subsetSum_rec(n-1, k, arr);
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
	if(n < 0) {
		return (k == 0);
	}
	if(k == 0) {
		return true;
	}
	if(k < 0) {
		return false;
	}
	bool take = subsetSum_rec(n-1, k-arr[n], arr);
	bool notTake = subsetSum_rec(n-1, k, arr);
	return (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	// bool ans1 = subsetSum_rec(n-1, k, arr);
	bool ans2 = subsetSum_mem(n-1, k, arr);
	return ans2;
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