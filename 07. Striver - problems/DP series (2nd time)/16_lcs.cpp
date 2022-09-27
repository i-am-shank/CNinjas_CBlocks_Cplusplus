#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation -> space optimization (1 1D array)
	// Time : O(n^2)
	// Space : O(n)
	int lcs_dp_space2(int x, int y, string& s1, string& s2) {
		vector<int> dp(y+2,0);
		// For edge case (or base case) of x<0 || y<0
		// --> Doing shift of index
		for(int i=1; i<=x+1; i++) {
			for(int j=1; j<=y+1; j++) {
				if(s1[i-1] == s2[j-1]) {
					dp[j] = 1 + dp[j-1];
				}
				else {
					int ans1 = dp[j];
					int ans2 = dp[j-1];
					dp[j] = max(ans1, ans2);
				}
			}
		}
		return dp[y+1];
	}

	// Tabulation --> space optimization
	// Time : O(n^2)
	// Space : O(n)
	int lcs_dp_space(int x, int y, string& s1, string& s2) {
		vector<int> prev(y+2,0);
		// For edge case (or base case) of x<0 || y<0
		// --> Doing shift of index
		for(int i=1; i<=x+1; i++) {
			vector<int> curr(y+2,0);
			for(int j=1; j<=y+1; j++) {
				if(s1[i-1] == s2[j-1]) {
					curr[j] = 1 + prev[j-1];
				}
				else {
					int ans1 = prev[j];
					int ans2 = curr[j-1];
					curr[j] = max(ans1, ans2);
				}
			}
			prev = curr;
		}
		return prev[y+1];
	}

	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int lcs_dp(int x, int y, string& s1, string& s2) {
		vector<vector<int>> dp(x+2, vector<int>(y+2,0));
		// For edge case (or base case) of x<0 || y<0
		// --> Doing shift of index
		for(int i=1; i<=x+1; i++) {
			for(int j=1; j<=y+1; j++) {
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else {
					int ans1 = dp[i-1][j];
					int ans2 = dp[i][j-1];
					dp[i][j] = max(ans1, ans2);
				}
		
			}
		}
		return dp[x+1][y+1];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. Recursion stack
	int lcs_mem_help(int x, int y, string& s1, string& s2, vector<vector<int>>& dp) {
		if(x<0 || y<0) {
			return 0;
		}
		if(dp[x][y] != -1) {
			return dp[x][y];
		}
		if(s1[x] == s2[y]) {
			dp[x][y] = 1 + lcs_mem_help(x-1, y-1, s1, s2, dp);
		}
		else {
			int ans1 = lcs_mem_help(x-1, y, s1, s2, dp);
			int ans2 = lcs_mem_help(x, y-1, s1, s2, dp);
			dp[x][y] = max(ans1, ans2);
		}
		return dp[x][y];
	}

	int lcs_mem(int x, int y, string& s1, string& s2) {
		vector<vector<int>> dp(x+1, vector<int>(y+1, -1));
		return lcs_mem_help(x, y, s1, s2, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	int lcs_rec(int x, int y, string& s1, string& s2) {
		if(x<0 || y<0) {
			return 0;
		}
		if(s1[x] == s2[y]) {
			return 1 + lcs_rec(x-1, y-1, s1, s2);
		}
		else {
			int ans1 = lcs_rec(x-1, y, s1, s2);
			int ans2 = lcs_rec(x, y-1, s1, s2);
			return max(ans1, ans2);
		}
	}

public:
    int lcs(int x, int y, string s1, string s2) {
        // int ans1 = lcs_rec(x-1, y-1, s1, s2);
        // int ans2 = lcs_mem(x-1, y-1, s1, s2);
        // int ans3 = lcs_dp(x-1, y-1, s1, s2);
        // int ans4 = lcs_dp_space(x-1, y-1, s1, s2);
        int ans5 = lcs_dp_space2(x-1, y-1, s1, s2);
        return ans5;
    }
};

int main() {
	int x, y;
	string s1, s2;
	cin >> x >> y >> s1 >> s2;
	Solution solve;
	int ans = solve.lcs(x, y, s1, s2);
	cout << ans << "\n";
	return 0;
}