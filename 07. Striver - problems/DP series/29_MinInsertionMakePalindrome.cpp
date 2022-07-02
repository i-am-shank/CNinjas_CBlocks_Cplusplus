#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n^2)
	// Space : O(n)
	int lcs_dp_space(int n1, int n2, string text1, string text2) {
		vector<int> prevRow(n2+1, 0); // 0th row -> all 0 (base case)
		for(int i=1; i<=n1; i++) {
			vector<int> currRow(n2+1, 0); // 0th column-entry of all rows -> 0 (base case)
			for(int j=1; j<=n2; j++) {
				// Do substract 1 from indexes.. as index-shift is done before
				if(text1[i-1] == text2[j-1]) { // 1 character matched  ->  +1
					currRow[j] = 1 + prevRow[j-1];
				}
				else {
					int smallAns1 = prevRow[j];
					int smallAns2 = currRow[j-1];
					currRow[j] = max(smallAns1, smallAns2);
				}
			}
			prevRow = currRow;
		}
		return prevRow[n2];
	}

public:
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();
        int sizeLPS = lcs_dp_space(n, n, s, s2);
        // LCS of string & its reverse  ==  LPS (palindrome)
        int countInsertions = (n - sizeLPS);
        return countInsertions;
    }
};

int main() {
	Solution solve;
	string s;
	cin >> s;
	int ans = solve.minInsertions(s);
	cout << ans << endl;
	return 0;
}