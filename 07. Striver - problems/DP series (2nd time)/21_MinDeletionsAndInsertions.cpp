#include <bits/stdc++.h>
using namespace std;

class Solution {
	int lcs_dp(int x, int y, string& s1, string& s2) {
		vector<vector<int>> dp(x+2, vector<int>(y+2,0));
		for(int i=1; i<=x+1; i++) {
			for(int j=1; j<=y+1; j++) {
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else {
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				}
			}
		}
		return dp[x+1][y+1];
	}

public:
	int minOperations(string str1, string str2) {
		int n1 = str1.size(), n2 = str2.size();
		int lcs = lcs_dp(n1-1, n2-1, str1, str2);
		int ans = (n1+n2) - (2*lcs);
		return ans;
	}
};

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	Solution solve;
	int ans = solve.minOperations(str1, str2);
	cout << ans << "\n";
	return 0;
}