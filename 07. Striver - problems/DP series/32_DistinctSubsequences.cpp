#include <bits/stdc++.h>
using namespace std;

class Solution {
	int mod = 1e9 + 7; // To prevent heap-overflow

	// Tabulation  ->  Single-array space optimization
	// Time : O(n^2)
	// Space : O(n)  .. Half of general space optimization
	int count_dp_space_better(int n1, int n2, string s, string t) {
		vector<int> prevRow(n2+1, 0);
		prevRow[0] = 1; // Base case
		for(int i=1; i<=n1; i++) {
			for(int j=n2; j>=1; j--) {
				int take = 0, notTake = 0;
				if(s[i-1] == t[j-1]) { // modified-index
					// If 1 char. matching, 2 options (take or notTake)
					take = prevRow[j-1];
					notTake = prevRow[j];
					prevRow[j] = (take + notTake) % mod;
				}
				// Else no update required
			}
		}
		return prevRow[n2];
	}

	// Tabulation  ->  space optimization
	// Time : O(n^2)
	// Space : O(n)
	int count_dp_space(int n1, int n2, string s, string t) {
		vector<int> prevRow(n2+1, 0);
		prevRow[0] = 1; // Base case
		for(int i=1; i<=n1; i++) {
			vector<int> currRow(n2+1, 0);
			currRow[0] = 1; // Base case
			for(int j=1; j<=n2; j++) {
				int take = 0, notTake = 0;
				if(s[i-1] == t[j-1]) { // modified-index
					// If 1 char. matching, 2 options (take or notTake)
					take = prevRow[j-1];
					notTake = prevRow[j];
					currRow[j] = (take + notTake) % mod;
				}
				else {
					currRow[j] = prevRow[j];
				}
			}
			prevRow = currRow;
		}
		return prevRow[n2];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int count_dp(int n1, int n2, string s, string t) {
		vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
		// Base case
		for(int i=0; i<=n1; i++) {
			dp[i][0] = 1;
		}
		for(int i=1; i<=n1; i++) {
			for(int j=1; j<=n2; j++) {
				int take = 0, notTake = 0;
				if(s[i-1] == t[j-1]) { // modified-index
					// If 1 char. matching, 2 options (take or notTake)
					take = dp[i-1][j-1];
					notTake = dp[i-1][j];
					dp[i][j] = (take + notTake) % mod;
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		return dp[n1][n2];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. Recursion stack
	int count_mem_help(int n1, int n2, string s, string t, vector<vector<int>>& dp) {
		// Base case
		if(n2 < 0) { // Whole string t tracked in s
			return 1;
		}
		if(n1 < 0) { // Whole string s traversed (without discovering t)
			return 0;
		}
		if(dp[n1][n2] != -1) {
			return dp[n1][n2];
		}
		int take = 0, notTake = 0;
		if(s[n1] == t[n2]) {
			// If 1 char. matching, 2 options (take or notTake)
			take = count_mem_help(n1-1, n2-1, s, t, dp);
			notTake = count_mem_help(n1-1, n2, s, t, dp);
			dp[n1][n2] = (take + notTake) % mod;
		}
		else {
			dp[n1][n2] = count_mem_help(n1-1, n2, s, t, dp);
		}
		return dp[n1][n2];
	}

	int count_mem(int n1, int n2, string s, string t) {
		vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
		return count_mem_help(n1, n2, s, t, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n)  .. Recursion stack
	int count_rec(int n1, int n2, string s, string t) {
		// Base case
		if(n2 < 0) { // Whole string t tracked in s
			return 1;
		}
		if(n1 < 0) { // Whole string s traversed (without discovering t)
			return 0;
		}
		int take = 0, notTake = 0;
		if(s[n1] == t[n2]) {
			// If 1 char. matching, 2 options (take or notTake)
			take = count_rec(n1-1, n2-1, s, t);
			notTake = count_rec(n1-1, n2, s, t);
			return (take + notTake) % mod;
		}
		else {
			return count_rec(n1-1, n2, s, t);
		}
	}

public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        // int ans1 = count_rec(n1-1, n2-1, s, t);
        // int ans2 = count_mem(n1-1, n2-1, s, t);
        // int ans3 = count_dp(n1, n2, s, t);
        // int ans4 = count_dp_space(n1, n2, s, t);
        int ans5 = count_dp_space_better(n1, n2, s, t);
        return ans5;
    }
};

int main() {
	Solution solve;
	string s, t;
	cin >> s >> t;
	int ans = solve.numDistinct(s, t);
	cout << ans << endl;
	return 0;
}