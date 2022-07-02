#include <bits/stdc++.h>
using namespace std;

// Time : O(n1+n2) .. O(n)
// Space : O(n^2)
int main() {
	string text1, text2;
	cin >> text1 >> text2;
	int n1 = text1.size(), n2 = text2.size();
	vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
	for(int i=1; i<=n1; i++) {
		for(int j=1; j<=n2; j++) {
			if(text1[i-1] == text2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	string lcsString = "";
	int i=n1, j=n2;
	while(i>0 && j>0) {
		if(text1[i-1] == text2[j-1]) {
			lcsString = text1[i-1] + lcsString;
			i--;
			j--;
		}
		else {
			if(dp[i-1][j] >= dp[i][j-1]) {
				i--;
			}
			else {
				j--;
			}
		}
	}
	cout << lcsString << endl;
	return 0;
}