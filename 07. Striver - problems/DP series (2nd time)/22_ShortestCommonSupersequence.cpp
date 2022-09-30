#include <bits/stdc++.h>
using namespace std;

class Solution {
	int lcs_dp(string& s1, string& s2, int n1, int n2) {
		vector<vector<int>> dp(n1+2, vector<int>(n2+2,0));
		for(int i=1; i<=n1+1; i++) {
			for(int j=1; j<=n2+1; j++) {
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		return dp[n1+1][n2+1];
	}

public:
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        int lcs = lcs_dp(X, Y, m-1, n-1);
        return (lcs + (m-lcs) + (n-lcs));
    }
};

int main() {
	string X, Y;
	cin >> X >> Y;
	int m = X.size(), n = Y.size();
	Solution solve;
	int ans = solve.shortestCommonSupersequence(X, Y, m, n);
	cout << ans << "\n";
	return 0;
}