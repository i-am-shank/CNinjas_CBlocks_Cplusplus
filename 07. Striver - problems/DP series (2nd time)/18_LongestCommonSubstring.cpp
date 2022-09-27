#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int lcs_dp(int x, int y, string& s1, string& s2) {
		vector<vector<int>> dp(x+2, vector<int>(y+2,0));
		// For edge case (or base case) of x<0 || y<0
		// --> Doing shift of index
		int maxLen = INT_MIN;
		for(int i=1; i<=x+1; i++) {
			for(int j=1; j<=y+1; j++) {
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else {
					// No matching.. subtring goes to length 0
					dp[i][j] = 0;
				}
				maxLen = max(maxLen, dp[i][j]);
			}
		}
		return maxLen;
	}

public:
	int longestCommonSubstr(string s1, string s2, int x, int y){
		return lcs_dp(x, y, s1, s2);
	}
};

int main() {
	Solution solve;
	int x, y;
	string s1, s2;
	cin >> x >> y >> s1 >> s2;
	int ans = solve.longestCommonSubstr(s1, s2, x, y);
	cout << ans << "\n";
	return 0;
}