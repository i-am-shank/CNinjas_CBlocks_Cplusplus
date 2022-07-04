#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Not possible in our case
	// Have to pass 1st string as pattern in arguments
	// As in our case, in base case..
	//     -> assigning [0][j] after iterating all rows


	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	bool isMatch_dp(int n1, int n2, string s1, string s2) {
		vector<vector<bool>> dp(n1+1, vector<bool>(n2+1,0));
		// Base case
		dp[0][0] = true;
		for(int j=1; j<=n2; j++) {
			bool flag = true;
			for(int k=1; k<=j; k++) {
				if(s2[k-1] != '*') {
					flag = false;
					break;
				}
			}
			dp[0][j] = flag;
		}
		for(int i=1; i<=n1; i++) {
			dp[i][0] = false;
		}
		for(int i=1; i<=n1; i++) {
			for(int j=1; j<=n2; j++) {
				if(s1[i-1]==s2[j-1]  ||  s2[j-1]=='?') {
					dp[i][j] = dp[i-1][j-1];
				}
				else if(s2[j-1] == '*') {
					bool smallAns1 = dp[i][j-1];
					bool smallAns2 = dp[i-1][j];
					dp[i][j] = (smallAns1 || smallAns2);
				}
				else {
					dp[i][j] = false;
				}
			}
		}
		return dp[n1][n2];
	}

	// Memoization
	// Time : O(n^2)
	// Space : O(n^2) + O(n) .. Recursion stack
	bool isMatch_mem_help(int n1, int n2, string s1, string s2, vector<vector<int>>& dp) {
		// Base case
		if(n1<0 && n2<0) { // Both exhausted
			return true; 
		}
		if(n1 < 0) { // One of them got exhausted
			for(int i=0; i<=n2; i++) {
				if(s2[i] != '*') {
					return false;
				}
			}
			return true;
		}
		if(n2 < 0) {
			return false;
		}
		if(dp[n1][n2] != -1) {
			return dp[n1][n2];
		}
		if(s1[n1]==s2[n2]  ||  s2[n2]=='?') {
			dp[n1][n2] = isMatch_mem_help(n1-1, n2-1, s1, s2, dp);
		}
		else if(s2[n2] == '*') {
			bool smallAns1 = isMatch_mem_help(n1, n2-1, s1, s2, dp);
			bool smallAns2 = isMatch_mem_help(n1-1, n2, s1, s2, dp);
			dp[n1][n2] = (smallAns1 || smallAns2);
		}
		else {
			dp[n1][n2] = 0;
		}
		return (bool)dp[n1][n2];
	}

	bool isMatch_mem(int n1, int n2, string s1, string s2) {
		vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
		return isMatch_mem_help(n1, n2, s1, s2, dp);
	}

	// Recursion
	// Time : Exponential
	// Space : O(n)   .. O(n1+n2)
	bool isMatch_rec(int n1, int n2, string s1, string s2) {
		// Base case
		if(n1<0 && n2<0) { // Both exhausted
			return true; 
		}
		if(n1 < 0) { // String1 got exhausted
			for(int i=0; i<=n2; i++) {
				if(s2[i] != '*') {
					return false;
				}
			}
			return true;
		}
		if(n2 < 0) {
			return false;
		}
		if(s1[n1]==s2[n2]  ||  s2[n2]=='?') {
			return isMatch_rec(n1-1, n2-1, s1, s2);
		}
		if(s2[n2] == '*') {
			bool smallAns1 = isMatch_rec(n1, n2-1, s1, s2);
			bool smallAns2 = isMatch_rec(n1-1, n2, s1, s2);
			return (smallAns1 || smallAns2);
		}
		return false;
	}

public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        // bool ans1 = isMatch_rec(n1-1, n2-1, s, p);
        // bool ans2 = isMatch_mem(n1-1, n2-1, s, p);
        bool ans3 = isMatch_dp(n1, n2, s, p);
        return ans3;
    }
};

int main() {
	Solution solve;
	string s, p;
	cin >> s >> p;
	bool ans = solve.isMatch(s, p);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}