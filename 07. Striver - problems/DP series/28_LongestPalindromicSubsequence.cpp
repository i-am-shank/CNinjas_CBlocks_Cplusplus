#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n^2)
	// Space : O(n)
	int lcs_dp_space(int n1, int n2, string text1, string text2) {
		vector<int> prevRow(n2+1, 0); // 0th row -> all 0 (base case)
		for(int i=1; i<=n1; i++) {
			vector<int> currRow(n2+1, 0); // 0th column-entry of all rows -> 0 (base case)
			for(int j=1; j<=n2; j++) {
				// Do substract 1 from indexes.. as index-shift is done before
				if(text1[i-1] == text2[j-1]) { // 1 character matched  ->  +1
					currRow[j] = 1 + prevRow[j-1];
				}
				else {
					int smallAns1 = prevRow[j];
					int smallAns2 = currRow[j-1];
					currRow[j] = max(smallAns1, smallAns2);
				}
			}
			prevRow = currRow;
		}
		return prevRow[n2];
	}


	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	// Here n1 = text1.size()   &   n2 = text2.size();
	int lcs_dp(int n1, int n2, string text1, string text2) {
		vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
		// Base case
		// 0th row of dp.. dp[0][i]  &  0th column of dp.. dp[i][0]
		//    -> Already set to 0  (Symbolizing <0-index by 0-index)
		// Transformation  :  if(n1<0 || n2<0)  -->  if(n1==0 || n2==0)
		for(int i=1; i<=n1; i++) {
			for(int j=1; j<=n2; j++) {
				// Do substract 1 from indexes.. as index-shift is done before
				if(text1[i-1] == text2[j-1]) { // 1 character matched  ->  +1
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else {
					int smallAns1 = dp[i-1][j];
					int smallAns2 = dp[i][j-1];
					dp[i][j] = max(smallAns1, smallAns2);
				}
			}
		}
		return dp[n1][n2]; // (0,n1-1) in text1  &  (0,n2-1) in text2
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2)  + O(n) .. Recursion stack
	int lcs_mem_help(int n1, int n2, string text1, string text2, vector<vector<int>>& dp) {
		// Base case
		if(n1<0 || n2<0) {
			return 0;
		}
		if(dp[n1][n2] != -1) {
			return dp[n1][n2];
		}
		if(text1[n1] == text2[n2]) { // 1 character matched  ->  +1
			dp[n1][n2] = 1 + lcs_mem_help(n1-1, n2-1, text1, text2, dp);
		}
		else {
			int smallAns1 = lcs_mem_help(n1-1, n2, text1, text2, dp);
			int smallAns2 = lcs_mem_help(n1, n2-1, text1, text2, dp);
			dp[n1][n2] = max(smallAns1, smallAns2);
		}
		return dp[n1][n2];
	}

	int lcs_mem(int n1, int n2, string text1, string text2) {
		vector<vector<int>> dp(n1+1, vector<int> (n2+1,-1));
		return lcs_mem_help(n1, n2, text1, text2, dp);
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	int lcs_rec(int n1, int n2, string s1, string s2) {
		// Base case
		if(n1<0 || n2<0) {
			return 0;
		}
		if(s1[n1] == s2[n2]) {
			return (1 + lcs_rec(n1-1,n2-1,s1,s2));
		}
		else {
			int smallAns1 = lcs_rec(n1-1, n2, s1, s2);
			int smallAns2 = lcs_rec(n1, n2-1, s1, s2);
			return max(smallAns1, smallAns2);
		}
	}

public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n1 = s.size(), n2 = s2.size();
        // int ans1 = lcs_rec(n1-1, n2-1, s, s2);
        // int ans2 = lcs_mem(n1-1, n2-1, s, s2);
        // int ans3 = lcs_dp(n1, n2, s, s2);
        int ans4 = lcs_dp_space(n1, n2, s, s2);
        return ans4;
    }
};

int main() {
	Solution solve;
	string s;
	cin >> s;
	int ans = solve.longestPalindromeSubseq(s);
	cout << ans << endl;
	return 0;
}