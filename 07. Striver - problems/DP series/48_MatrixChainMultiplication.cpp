// Partition DP :-

// 1. Start with entire block/array [i,j].
// 2. Try all partitions. (run a loop)
// 3. Return the best possible partition-pair.

#include <bits/stdc++.h>
using namespace std;

// Tabulation
// Time : O(n^3)
// Space : O(n^2)
int mcm_dp(vector<int>& arr, int n) {
	vector<vector<int>> dp(n, vector<int>(n,0));
	// Base case  ->  no need (initialized by 0)
	for(int i=0; i<n; i++) {
		dp[i][i] = 0;
	}
	for(int s=n-1; s>=0; s--) {
		for(int e=s+1; e<n; e++) {
			int ans = 1e9;
			for(int i=s; i<e; i++) {
				// Formulating no. of steps (for 1 partition) :
					// arr  ->  [10, 20, 30, 40, 50]  ->  [A, B, C, D]
					//   (n-size array  ==  n-1 matrices)
					// (AB) = (10*20) * (20*30) = (10 * 30) matrix
					// (CD) = (30*40) * (40*50) = (30 * 50) matrix
					// (AB)*(CD) = (10*30) * (30*50) = (10 * 30 * 50) steps
					//     +  No. of steps for (AB)   +  No. of steps for (CD)
					// So, here  :
					// arr[s-1] = 10  ,  arr[i] = 30  ,  arr[e] = 50
				// No. of steps = (arr[s-1] * arr[i] * arr[e])  +  Recursion calls
				int currSteps = (arr[s-1] * arr[i] * arr[e]);
				int smallAns1 = dp[s][i];
				int smallAns2 = dp[i+1][e];
				int totalSteps = (currSteps + smallAns1 + smallAns2);
				ans = min(ans, totalSteps);
			}
			dp[s][e] = ans;
		}
	}
	return dp[1][n-1]; // Start = 1  ,  End = n-1
}

// Memoization
// Time : O(n^2)
// Space : O(n^2) + Linear .. Recursion stack
int mcm_mem_help(vector<int>& arr, int s, int e, vector<vector<int>>& dp) {
	// Base case
	if(s == e) { // Single matrix  ->  0 multiplication
		return 0;
	}
	if(dp[s][e] != -1) {
		return dp[s][e];
	}
	int ans = 1e9;
	for(int i=s; i<e; i++) {
		// Formulating no. of steps (for 1 partition) :
			// arr  ->  [10, 20, 30, 40, 50]  ->  [A, B, C, D]
			//   (n-size array  ==  n-1 matrices)
			// (AB) = (10*20) * (20*30) = (10 * 30) matrix
			// (CD) = (30*40) * (40*50) = (30 * 50) matrix
			// (AB)*(CD) = (10*30) * (30*50) = (10 * 30 * 50) steps
			//     +  No. of steps for (AB)   +  No. of steps for (CD)
			// So, here  :
			// arr[s-1] = 10  ,  arr[i] = 30  ,  arr[e] = 50
		// No. of steps = (arr[s-1] * arr[i] * arr[e])  +  Recursion calls
		int currSteps = (arr[s-1] * arr[i] * arr[e]);
		int smallAns1 = mcm_mem_help(arr, s, i, dp);
		int smallAns2 = mcm_mem_help(arr, i+1, e, dp);
		int totalSteps = (currSteps + smallAns1 + smallAns2);
		ans = min(ans, totalSteps);
	}
	dp[s][e] = ans;
	return dp[s][e];
}

int mcm_mem(vector<int>& arr, int N, int s, int e) {
	vector<vector<int>> dp(N, vector<int>(N,-1));
	return mcm_mem_help(arr, s, e, dp);
}

// Recursion
// Time : Exponential
// Space : Linear  .. Recursion stack
int mcm_rec(vector<int>& arr, int s, int e) {
	// Base case
	if(s == e) { // Single matrix  ->  0 multiplication
		return 0;
	}
	int ans = 1e9;
	for(int i=s; i<e; i++) {
		// Formulating no. of steps (for 1 partition) :
			// arr  ->  [10, 20, 30, 40, 50]  ->  [A, B, C, D]
			//   (n-size array  ==  n-1 matrices)
			// (AB) = (10*20) * (20*30) = (10 * 30) matrix
			// (CD) = (30*40) * (40*50) = (30 * 50) matrix
			// (AB)*(CD) = (10*30) * (30*50) = (10 * 30 * 50) steps
			//     +  No. of steps for (AB)   +  No. of steps for (CD)
			// So, here  :
			// arr[s-1] = 10  ,  arr[i] = 30  ,  arr[e] = 50
		// No. of steps = (arr[s-1] * arr[i] * arr[e])  +  Recursion calls
		int currSteps = (arr[s-1] * arr[i] * arr[e]);
		int smallAns1 = mcm_rec(arr, s, i);
		int smallAns2 = mcm_rec(arr, i+1, e);
		int totalSteps = (currSteps + smallAns1 + smallAns2);
		ans = min(ans, totalSteps);
	}
	return ans;
}

int matrixMultiplication(vector<int> &arr, int N) {
	// ith matrix  ->  arr[i] x arr[i-1]
	// int ans1 = mcm_rec(arr, 1, N-1);
	// int ans2 = mcm_mem(arr, N, 1, N-1);
	int ans3 = mcm_dp(arr, N);
	return ans3;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int N;
		cin >> N;
		vector<int> arr;
		for(int i=0; i<N; i++) {
			int ele;
			cin >> ele;
			arr.push_back(ele);
		}
		int ans = matrixMultiplication(arr, N);
		cout << ans << endl;
	}
	return 0;
}