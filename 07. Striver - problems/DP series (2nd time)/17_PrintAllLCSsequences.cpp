#include <bits/stdc++.h>
using namespace std;

class Solution {
	set<string> words;

	void getLCS(vector<vector<int>>& dp, int x, int y, string& s1, string& s2, string s, vector<string>& ans) {
		if(x==0 || y==0) {
			if(words.count(s) == 0) {
				ans.push_back(s);
				words.insert(s);
			}
			return;
		}
		if(s1[x-1] == s2[y-1]) {
			// Add s[i-1] to all made lcs strings
			s = s1[x-1] + s;
			getLCS(dp, x-1, y-1, s1, s2, s, ans);
		}
		else {
			// Proceed to 2 possibilities
			if(dp[x-1][y] > dp[x][y-1]) {
				getLCS(dp, x-1, y, s1, s2, s, ans);
			}
			else if(dp[x-1][y] < dp[x][y-1]) {
				getLCS(dp, x, y-1, s1, s2, s, ans);
			}
			else {
				// Both possibilities open
				getLCS(dp, x-1, y, s1, s2, s, ans);
				getLCS(dp, x, y-1, s1, s2, s, ans);
			}
		}
		return;
	}

public:
	vector<string> all_longest_common_subsequences(string s1, string s2) {
		int x=s1.size(), y=s2.size();
		vector<vector<int>> dp(x+1, vector<int>(y+1, 0));
		// vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
		for(int i=1; i<=x; i++) {
			for(int j=1; j<=y; j++) {
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		vector<string> ans;
		getLCS(dp, x, y, s1, s2, "", ans);
		sort(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	Solution solve;
	string s, t;
	cin >> s >> t;
	vector<string> ans = solve.all_longest_common_subsequences(s, t);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}