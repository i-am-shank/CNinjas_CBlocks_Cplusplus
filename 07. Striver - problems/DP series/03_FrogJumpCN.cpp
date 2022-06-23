#include <bits/stdc++.h>
using namespace std;

// Tabulation  ->  Space optimization
// Time : O(n)
// Space : O(1)
int frogJump_dp_space(int n, vector<int>& heights) {
	if(n == 1) {
		return 0;
	}
	if(n == 2) {
		return abs(heights[n-2] - heights[n-1]);
	}
	int prev2 = 0, prev = abs(heights[n-2]-heights[n-1]);
	for(int i=n-3; i>=0; i--) {
		int jump1 = prev + (abs(heights[i+1]-heights[i]));
		int jump2 = prev2 + (abs(heights[i+2]-heights[i]));
		int curr = min(jump1, jump2);
		prev2 = prev;  // Updating for next iteration
		prev = curr;
	}
	return prev; // curr of last iteration
}

// DP .. Tabulation .. Bottom-up
// Time : O(n)
// Space : O(n)
int frogJump_dp(int n, vector<int>& heights) {
	vector<int> dp(n, -1);
	// dp[i]  ->  min. Energy required from index ith (to reach n-1)
	if(n > 0) {
		dp[n-1] = 0;
	}
	if(n > 1) {
		dp[n-2] = abs(heights[n-1] - heights[n-2]);
	}
	for(int j=n-3; j>=0; j--) {
		int jump1 = abs(heights[j+1] - heights[j]);
		int jump2 = abs(heights[j+2] - heights[j]);
		int choice1 = jump1 + (dp[j+1]);
		int choice2 = jump2 + dp[j+2];
		dp[j] = min(choice1, choice2);
	}
	int ans = dp[0];
	return ans;
}

// Memoization .. Top-down
// Time : O(n)
// Space : O(n)
int frogJump_mem_help(int n, vector<int>& heights, int i, vector<int>& dp) {
	if(dp[i] != -1) {
		return dp[i];
	}
	int jump1 = abs(heights[i+1] - heights[i]);
	int jump2 = abs(heights[i+2] - heights[i]);
	int smallAns1 = jump1 + frogJump_mem_help(n, heights, i+1, dp);
	int smallAns2 = jump2 + frogJump_mem_help(n, heights, i+2, dp);
	dp[i] = min(smallAns1, smallAns2);
	return dp[i];
}

int frogJump_mem(int n, vector<int>& heights, int i) {
	vector<int> dp(n, -1);
	if(n != 0) {
		dp[n-1] = 0;
	}
	if(n > 1) {
		dp[n-2] = abs(heights[n-1] - heights[n-2]);
	}
	int ans = frogJump_mem_help(n, heights, i, dp);
	return ans;
}

// Recursion
// Time : O(2^n)
// Space : O(1)
int frogJump_rec(int n, vector<int>& heights, int i) {
	if(i == n-1) {
		return 0;
	}
	if(i == n-2) {
		return abs(heights[i+1] - heights[i]);
	}
	int jump1 = abs(heights[i+1] - heights[i]);
	int jump2 = abs(heights[i+2] - heights[i]);
	int smallAns1 = jump1 + frogJump_rec(n, heights, i+1);
	int smallAns2 = jump2 + frogJump_rec(n, heights, i+2);
	return min(smallAns1, smallAns2);
}

int frogJump(int n, vector<int> &heights){
    /* int ans1 = frogJump_rec(n, heights, 0);
    int ans2 = frogJump_mem(n, heights, 0);
    int ans3 = frogJump_dp(n, heights); */
    int ans4 = frogJump_dp_space(n, heights);
    return ans4;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> heights;
		for(int i=0; i<n; i++) {
			int ele;
			cin >> ele;
			heights.push_back(ele);
		}
		int ans = frogJump(n, heights);
		cout << ans << endl;
	}
	return 0;
}