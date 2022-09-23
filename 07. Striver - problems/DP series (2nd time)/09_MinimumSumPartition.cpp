#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	vector<vector<bool>> check_dp(vector<int>& arr, int n, int sum) {
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
		return dp;
	}

public:
	int minDifference(vector<int>& arr, int n) {
	    int sum = 0;
	    for(int i=0; i<n; i++) {
	    	sum += arr[i];
	    }
	    // Have to find a sum .. closest to (sum/2)
	    // Almost equally partitioned .. if possible
	    // Build the dp table for (0-n, sum)
	    // And come to result from that table

	    // Last row of dp table :-
	    // For indexes (0 to n), is sum x achievable
	    int minDiff = sum;
	    vector<vector<bool>> dp = check_dp(arr, n-1, sum);
	    for(int i=1; i<=sum; i++) {
	    	if(dp[n][i] == 1) { // A sum of (i) possible
	    		// Diff. between sums of 2 subsets
	    		int diff = abs((i) - (sum-i));
	    		minDiff = min(minDiff, diff);
	    	}
	    }
	    return minDiff;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	int ans = solve.minDifference(arr, n);
	cout << ans << "\n";
	return 0;
}