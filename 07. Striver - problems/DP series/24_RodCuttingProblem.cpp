#include <bits/stdc++.h>
using namespace std;

// Tabulation  ->  space optimization
// Time : O(n^2)
// Space : O(n)
int maxPrice_dp_space(int n, int l, vector<int>& price) {
	vector<int> prevRow(l+1, 0);
	// Base case
	for(int i=0; i<=l; i++) {
		prevRow[i] = (i * price[0]);
	}
	for(int i=1; i<=n; i++) {
		vector<int> currRow(l+1, 0);
		for(int j=0; j<=l; j++) {
			int notTake = prevRow[j];
			int take = 0;
			if(i+1 <= j) {
				take = price[i] + currRow[j-(i+1)];
			}
			currRow[j] = max(take, notTake);
		}
		prevRow = currRow;
	}
	return prevRow[l];
}

// Tabulation
// Time : O(n^2)
// Space : O(n^2)
int maxPrice_dp(int n, int l, vector<int>& price) {
	vector<vector<int>> dp(n+1, vector<int>(l+1, 0));
	// Base case
	for(int i=0; i<=l; i++) {
		dp[0][i] = (i * price[0]);
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=l; j++) {
			int notTake = dp[i-1][j];
			int take = 0;
			if(i+1 <= j) {
				take = price[i] + dp[i][j-(i+1)];
			}
			dp[i][j] = max(take, notTake);
		}
	}
	return dp[n][l];
}

// Memoization
// Time : O(n^2)
// Space : O(n^2) + O(n) .. Recursion stack
int maxPrice_mem_help(int n, int l, vector<int>& price, vector<vector<int>>& dp) {
	// Base case
	if(n == 0) {
		return (l * price[0]); // 0th rod is of length (0+1).
	}
	if(dp[n][l] != -1) {
		return dp[n][l];
	}
	int notTake = maxPrice_mem_help(n-1, l, price, dp);
	int take = 0;
	if(n+1 <= l) {
		take = price[n] + maxPrice_mem_help(n, l-(n+1), price, dp);
	}
	dp[n][l] = max(take, notTake);
	return dp[n][l];
}

int maxPrice_mem(int n, int l, vector<int>& price) {
	vector<vector<int>> dp(n+1, vector<int>(l+1, -1));
	return maxPrice_mem_help(n, l, price, dp);
}

// Recursion
// Time : Exponential
// Space : O(n)  .. Recursion stack O(l)
int maxPrice_rec(int n, int l, vector<int>& price) {
	// Base case
	if(n == 0) {
		return (l * price[0]); // 0th rod is of length (0+1).
	}
	int notTake = maxPrice_rec(n-1, l, price);
	int take = 0;
	if(n+1 <= l) {
		take = price[n] + maxPrice_rec(n, l-(n+1), price);
	}
	return max(take, notTake);
}

// Instead of thinking as cutting a rod..
//   -> Collect lengths (maximise cost)
int cutRod(vector<int> &price, int n) {
	// int ans1 = maxPrice_rec(n-1, n, price);
	// int ans2 = maxPrice_mem(n-1, n, price);
	// int ans3 = maxPrice_dp(n-1, n, price);
	int ans4 = maxPrice_dp_space(n-1, n, price);
	return ans4;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> price;
		for(int i=0; i<n; i++) {
			int ele;
			cin >> ele;
			price.push_back(ele);
		}
		int ans = cutRod(price, n);
		cout << ans << endl;
	}
	return 0;
}