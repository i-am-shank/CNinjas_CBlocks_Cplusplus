#include <bits/stdc++.h>
using namespace std;

// 1st word > 2nd word  ->  Deletion
// 1st word < 2nd word  ->  Insertion
class Solution {
	int lcs_dp(int n1, int n2, string word1, string word2) {
		vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
		// Base case  :-
		// If 0 characters left in word2..
		for(int i=0; i<=n1; i++) {
			dp[i][0] = i;  // i deletions from word1
		}
		// If 0 characters left in word1..
		for(int i=0; i<=n2; i++) {
			dp[0][i] = i;  // i insertion in word1
		}
		for(int i=1; i<=n1; i++) {
			for(int j=1; j<=n2; j++) {
				if(word1[i-1] == word2[j-1]) {
					dp[i][j] = dp[i-1][j-1];
					// As same char., no extra-operations needed
				}
				else {
					int choice1 = 1 + dp[i-1][j-1]; // Replacing current character  ->  +1
					int choice2 = 1 + dp[i][j-1]; // Inserting 1 char.(word2[j]) in word1 (next step)  ->  +1
					int choice3 = 1 + dp[i-1][j]; // Deleting 1 char.(word1[i]) in word1 (next step)  ->  +1
					dp[i][j] = min(choice1, min(choice2,choice3));
				}
			}
		}
		return dp[n1][n2];
	}

public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int modifiedLCS = lcs_dp(n1, n2, word1, word2);
        return modifiedLCS;
        // In this, not counting common characters..
        // ..but calculating minimum steps to convert
    }
};

int main() {
	string word1, word2;
	cin >> word1 >> word2;
	Solution solve;
	int ans = solve.minDistance(word1, word2);
	cout << ans << endl;
	return 0;
}