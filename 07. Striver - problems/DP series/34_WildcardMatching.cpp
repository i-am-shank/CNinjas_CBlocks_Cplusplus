#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation
	bool isMatch_dp(int n1, int n2, string s1, string s2) {
		vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
		// Base case
		dp[0][0] = 1;
		bool flag = true;
		for(int i=1; i<=n1; i++) { // n2 = 0
			if(s1[i-1] != '*') {
				flag = false;
			}
			dp[i][0] = (int)flag;
		}
		flag = true;
		for(int i=1; i<=n2; i++) { // n1 = 0
			if(s2[i-1] != '*') {
				flag = false;
			}
			dp[0][i] = (int)flag;
		}
		for(int i=1; i<=n1; i++) {
			for(int j=1; j<=n2; j++) {
				if(s1[i-1]==s2[j-1]  ||  s2[j-1]=='?') {
					dp[i][j] = dp[i-1][j-1];
				}
				else if(s2[j-1] == '*') {
					bool ans = false;
					for(int k=0; k<=i+1; k++) {
						bool smallAns = dp[i-k][j-1];
						ans = (ans || smallAns);
						if(ans == true) {
							break;
						}
					}
					dp[i][j] = ans;
				}
				else {
					dp[i][j] = 0;
				}
			}
		}
		return dp[n1][n2];
	}

	// Memoization
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
			for(int i=0; i<=n1; i++) {
				if(s1[i] != '*') {
					return false;
				}
			}
			return true;
		}
		if(dp[n1][n2] != -1) {
			return dp[n1][n2];
		}
		if(s1[n1]==s2[n2]  ||  s2[n2]=='?') {
			dp[n1][n2] = isMatch_mem_help(n1-1, n2-1, s1, s2, dp);
		}
		else if(s2[n2] == '*') {
			bool ans = false;
			for(int i=0; i<=n1+1; i++) {
				bool smallAns = isMatch_mem_help(n1-i, n2-1, s1, s2, dp);
				ans = (ans || smallAns);
				if(ans == true) {
					break;
				}
			}
			dp[n1][n2] = ans;
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
	bool isMatch_rec(int n1, int n2, string s1, string s2) {
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
			for(int i=0; i<=n1; i++) {
				if(s1[i] != '*') {
					return false;
				}
			}
			return true;
		}
		if(s1[n1]==s2[n2]  ||  s2[n2]=='?') {
			return isMatch_rec(n1-1, n2-1, s1, s2);
		}
		if(s2[n2] == '*') {
			bool ans = false;
			for(int i=0; i<=n1+1; i++) {
				bool smallAns = isMatch_rec(n1-i, n2-1, s1, s2);
				ans = (ans || smallAns);
				if(ans == true) {
					break;
				}
			}
			return ans;
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