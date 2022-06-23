#include <bits/stdc++.h>
using namespace std;

// --> Space optimization not possible here
//       -> Possible only in (n-1) & (n-2) like logics.
//       ->   Space  :   O(n)  ->  O(1)

// Here even if we try to optimize space : 
//       ->   Space  :   O(n)  ->  O(k)


// Tabulation
// Time : O(n*k)
// Space : O(n)
int frogJumpK_dp(int n, vector<int>& heights, int k) {
	vector<int> dp(n, -1);
	if(n > 0) {
		dp[n-1] = 0;
	}
	for(int i=n-2; i>=0; i--) {
		int minJumps = INT_MAX;
		for(int j=1; j<=k && i+j<n ; j++) {
			int jumpj = dp[i+j];
			int energyj = abs(heights[i+j] - heights[i]);
			minJumps = min(minJumps, jumpj+energyj);
		}
		dp[i] = minJumps;
	}
	return dp[0]; // Jumps (to reach n-1 starting from 0th index)
}

// Memoization
// Time : O(n * k)
// Space : O(n)
int frogJumpK_mem_help(int n, vector<int>& heights, int i, int k, vector<int>& dp) {
	if(dp[i] != -1) {
		return dp[i];
	}
	int minVal = INT_MAX;
	for(int j=1; j<=k && i+j<n; j++) {
		int energyj = abs(heights[i+j] - heights[i]);
		int jumpj = frogJumpK_mem_help(n, heights, i+j, k, dp);
		minVal = min(minVal, energyj+jumpj);
	}
	dp[i] = minVal;
	return dp[i];
}

int frogJumpK_mem(int n, vector<int>& heights, int i, int k) {
	vector<int> dp(n, -1);
	if(n > 0) {
		dp[n-1] = 0;
	}
	int ans = frogJumpK_mem_help(n, heights, i, k, dp);
	return ans;
}

// Recursion
// Time : O(k ^ n)  ..  k-recursion calls at each level
// Space : O(1)
int frogJumpK_rec(int n, vector<int>& heights, int i, int k) {
	if(i == n-1) {
		return 0;
	}
	int minVal = INT_MAX;
	for(int j=1; j<=k; j++) {
		if(i+j < n) {  // then only j-unit jump possible
			int energyj = abs(heights[i+j] - heights[i]);
			int jumpj = frogJumpK_rec(n, heights, i+j, k);
			minVal = min(minVal, (energyj+jumpj));
		}
	}
	return minVal;
}

int frogJumpK(int n, vector<int>& heights, int k) {
	int ans1 = frogJumpK_rec(n, heights, 0, k);
	int ans2 = frogJumpK_mem(n, heights, 0, k);
	int ans3 = frogJumpK_dp(n, heights, k);
	return ans3;
}

int main() {
	int n;
	cin >> n;
	vector<int> heights;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		heights.push_back(ele);
	}
	int k;
	cin >> k;
	int ans = frogJumpK(n, heights, k);
	cout << ans << endl;
	return 0;
}