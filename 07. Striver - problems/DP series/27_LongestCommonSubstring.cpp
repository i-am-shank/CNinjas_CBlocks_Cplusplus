#include <bits/stdc++.h>
using namespace std;

// Used tabulation method  ->  of Longest Common Subsequence
// Time : O(n^2)
// Space : O(n)
int lcs(string &str1, string &str2){
	int n1 = str1.size(), n2 = str2.size();
	vector<int> prevRow(n2+1, 0);
	int ans = 0;
	for(int i=1; i<=n1; i++) {
		vector<int> currRow(n2+1, 0);
		for(int j=1; j<=n2; j++) {
			if(str1[i-1] == str2[j-1]) {
				currRow[j] = 1 + prevRow[j-1];
			}
			else {
				currRow[j] = 0; // No interruptions taken
			}
			ans = max(ans, currRow[j]);
		}
		prevRow = currRow;
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string str1, str2;
		cin >> str1 >> str2;
		int ans = lcs(str1, str2);
		cout << ans << endl;
	}
	return 0;
}