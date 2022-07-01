#include <bits/stdc++.h>
using namespace std;

// Tabulation  ->  space optimization
// Time : O(n^2)
// Space : O(n)
int maxProfit_dp_space(int n, int w, vector<int>& profit, vector<int>& weight) {
	vector<int> prevRow(w+1, 0);
	// Base case
	for(int i=0; i<=w; i++) {
		prevRow[i] = ((i/weight[0]) * profit[0]);
	}
	for(int i=1; i<=n; i++) {
		vector<int> currRow(w+1, 0);
		for(int j=0; j<=w; j++) {
			int notTake = prevRow[j];
			int take = 0;
			if(j >= weight[i]) {
				take = profit[i] + currRow[j-weight[i]];
			}
			currRow[j] = max(take, notTake);
		}
		prevRow = currRow;
	}
	return prevRow[w];
}

// Tabulation
// Time : O(n^2)
// Space : O(n^2)
int maxProfit_dp(int n, int w, vector<int>& profit, vector<int>& weight) {
	vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
	// Base case
	for(int i=0; i<=w; i++) {
		dp[0][i] = ((i/weight[0]) * profit[0]);
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=w; j++) {
			int notTake = dp[i-1][j];
			int take = 0;
			if(j >= weight[i]) {
				take = profit[i] + dp[i][j-weight[i]];
			}
			dp[i][j] = max(take, notTake);
		}
	}
	return dp[n][w];
}

// Memoization
// Time : O(n^2)
// Space : O(n^2) + O(n)..   recursion stack O(w)
int maxProfit_mem_help(int n, int w, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp) {
	// Base case
	if(n == 0) {
		int product = (w / weight[n]);
		return (product * profit[n]);
	}
	if(dp[n][w] != -1) {
		return dp[n][w];
	}
	int notTake = maxProfit_mem_help(n-1, w, profit, weight, dp);
	int take = 0;
	if(w >= weight[n]) {
		take = profit[n] + maxProfit_mem_help(n, w-weight[n], profit, weight, dp);
	}
	dp[n][w] = max(take, notTake);
	return dp[n][w];
}

int maxProfit_mem(int n, int w, vector<int>& profit, vector<int>& weight) {
	vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
	return maxProfit_mem_help(n, w, profit, weight, dp);
}

// Recursion
// Time : Exponential .. complex recursion stack
// Space : Linear..
int maxProfit_rec(int n, int w, vector<int>& profit, vector<int>& weight) {
	// Base case
	if(n == 0) {
		int product = (w / weight[n]);
		return (product * profit[n]);
	}
	int notTake = maxProfit_rec(n-1, w, profit, weight);
	int take = 0;
	if(w >= weight[n]) {
		take = profit[n] + maxProfit_rec(n, w-weight[n], profit, weight);
	}
	return max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    // int ans1 = maxProfit_rec(n-1, w, profit, weight);
    // int ans2 = maxProfit_mem(n-1, w, profit, weight);
    // int ans3 = maxProfit_dp(n-1, w, profit, weight);
    int ans4 = maxProfit_dp_space(n-1, w, profit, weight);
    return ans4;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, w;
		cin >> n >> w;
		vector<int> profit;
		vector<int> weight;
		for(int i=0; i<n; i++) {
			int ele;
			cin >> ele;
			profit.push_back(ele);
		}
		for(int i=0; i<n; i++) {
			int ele;
			cin >> ele;
			weight.push_back(ele);
		}
		int ans = unboundedKnapsack(n, w, profit, weight);
		cout << ans << endl;
	}
	return 0;
}