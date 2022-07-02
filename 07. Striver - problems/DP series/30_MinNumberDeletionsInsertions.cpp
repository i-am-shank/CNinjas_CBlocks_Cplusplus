#include <bits/stdc++.h>
using namespace std;

// Tabulation
// Time : O(n^2)
// Space : O(n)
int lcs_dp_space(int n1, int n2, string& str, string& ptr) {
	vector<int> prevRow(n2+1, 0);
	for(int i=1; i<=n1; i++) {
		vector<int> currRow(n2+1, 0);
		for(int j=1; j<=n2; j++) {
			if(str[i-1] == ptr[j-1]) {
				currRow[j] = 1 + prevRow[j-1];
			}
			else {
				currRow[j] = max(currRow[j-1], prevRow[j]);
			}
		}
		prevRow = currRow;
	}
	return prevRow[n2];
}

int canYouMake(string &str, string &ptr) {
    int n1 = str.size(), n2 = ptr.size();
    int lcs = lcs_dp_space(n1, n2, str, ptr);
    return (n1-lcs) + (n2-lcs);
    // No. of insertion  +  deletion  (or vice versa)
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string str, ptr;
		cin >> str >> ptr;
		int ans = canYouMake(str, ptr);
		cout << ans << endl;
	}
	return 0;
}