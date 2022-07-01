// Code-studio problem

#include <bits/stdc++.h>
using namespace std;

// Tabulation  ->  single-array space optimization
// Time : O(n^2)
// Space : O(n)  ..  Half space than general optimization
int knapsack_dp_space_better(int n, int w, int* weights, int* values) {
	vector<int> prevRow(w+1, 0);
	for(int i=weights[0]; i<=w; i++) { // Base case
		prevRow[i] = values[0];
	}
	for(int i=1; i<=n; i++) {
		for(int j=w; j>=0; j--) {
			int take = 0;
			if(weights[i] <= j) {
				take = values[i] + prevRow[j-weights[i]];
			}
			int notTake = prevRow[j];
			// both take & notTake using prevRow values only
			// If logically thinked, no need of currRow  --  How ??
			//   -> As index call is always less than the jth index
			//      -> Reverse update the values of array in an iteration
			//      -> Right to Left  ->  Previous calculated values will not get lost
			prevRow[j] = max(take, notTake);
		}
	}
	return prevRow[w];
}

// Tabulation  ->  space optimization
// Time : O(n^2)
// Space : O(n)
int knapsack_dp_space(int n, int w, int* weights, int* values) {
	vector<int> prevRow(w+1, 0);
	for(int i=weights[0]; i<=w; i++) { // Base case
		prevRow[i] = values[0];
	}
	for(int i=1; i<=n; i++) {
		vector<int> currRow(w+1, 0);
		for(int j=0; j<=w; j++) {
			int take = 0;
			if(weights[i] <= j) {
				take = values[i] + prevRow[j-weights[i]];
			}
			int notTake = prevRow[j];
			currRow[j] = max(take, notTake);
		}
		prevRow = currRow;
	}
	return prevRow[w];
}

// Tabulation
// Time : O(n^2)
// Space : O(n^2)
int knapsack_dp(int n, int w, int* weights, int* values) {
	vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
	for(int i=weights[0]; i<=w; i++) { // Base case
		dp[0][i] = values[0];
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=w; j++) {
			int take = 0;
			if(weights[i] <= j) {
				take = values[i] + dp[i-1][j-weights[i]];
			}
			int notTake = dp[i-1][j];
			dp[i][j] = max(take, notTake);
		}
	}
	return dp[n][w];
}

// Memoization
// Time : O(n^2)
// Space : O(n^2)  + O(n) .. Recursion stack
int knapsack_mem_help(int n, int w, int* weights, int* values, vector<vector<int>>& dp) {
	if(n == 0) { // Base case
		if(w >= weights[n]) {
			return values[n];
		}
		return 0;
	}
	if(dp[n][w] != -1) {
		return dp[n][w];
	}
	int take = 0;
	if(weights[n] <= w) {
		take = values[n] + knapsack_mem_help(n-1, w-weights[n], weights, values, dp);
	}
	int notTake = knapsack_mem_help(n-1, w, weights, values, dp);
	dp[n][w] = max(take, notTake);
	return dp[n][w];
}

int knapsack_mem(int n, int w, int* weights, int* values) {
	vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
	return knapsack_mem_help(n, w, weights, values, dp);
}

// Recursion
// Time : O(2^n)
// Space : O(n)  ..  Recursion stack
int knapsack_rec(int n, int w, int* weights, int* values) {
	if(n == 0) {
		if(w >= weights[n]) {
			return values[n];
		}
		return 0;
	}
	int take = 0;
	if(weights[n] <= w) {
		take = values[n] + knapsack_rec(n-1, w-weights[n], weights, values);
	}
	int notTake = knapsack_rec(n-1, w, weights, values);
	return max(take, notTake);
}

int knapsack(int *weights, int *values, int n, int maxWeight) {
	// int ans1 = knapsack_rec(n-1, maxWeight, weights, values);
	// int ans2 = knapsack_mem(n-1, maxWeight, weights, values);
	// int ans3 = knapsack_dp(n-1, maxWeight, weights, values);
	// int ans4 = knapsack_dp_space(n-1, maxWeight, weights, values);
	int ans5 = knapsack_dp_space_better(n-1, maxWeight, weights, values);
	return ans5;
}

int main() {
	int n;
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];
	for(int i=0; i<n; i++) {
		cin >> weights[i];
	}
	for(int i=0; i<n; i++) {
		cin >> values[i];
	}
	int maxWeight;
	cin >> maxWeight;
	int ans = knapsack(weights, values, n, maxWeight);
	cout << ans << endl;
	delete []weights;
	delete []values;
	return 0;
}