#include <bits/stdc++.h>
using namespace std;

class Solution{
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
    int countMin(string str){
    	string s = str;
    	reverse(s.begin(), s.end());
    	int n = s.size();
    	int lcs = lcs_dp(n-1, n-1, s, str);
    	return (n-lcs);
    }
};

int main() {
	Solution solve;
	string str;
	cin >> str;
	int ans = solve.countMin(str);
	cout << ans << "\n";
	return 0;
}