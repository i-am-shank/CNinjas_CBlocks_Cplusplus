#include <bits/stdc++.h>
using namespace std;

class Solution {
	string getLCS(int n1, int n2, string str1, string str2) {
		vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
		for(int i=1; i<=n1; i++) {
			for(int j=1; j<=n2; j++) {
				if(str1[i-1] == str2[j-1]) {
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else {
					int choice1 = dp[i][j-1];
					int choice2 = dp[i-1][j];
					dp[i][j] = max(choice1,choice2);
				}
			}
		}
		// Now dp[n1][n2] has length of LCS.
		int i=n1, j=n2;
		string ans = "";
		while(i>0 && j>0) {
			if(str1[i-1] == str2[j-1]) {
				ans = str1[i-1] + ans;
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
		return ans;
	}

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        string lcs = getLCS(n1, n2, str1, str2);
        string ans = "";
        // Add chars. of LCS only once (twice available, if generally iterated)
        // And, all other characters simply keep adding
        int i=0, j=0, k=0; // indices for str1, str2 & lcs.
        while(i<n1 && j<n2) {
        	if(str1[i] == str2[j]) {
        		ans += str1[i];
        		i++;
        		j++;
        		k++;
        	}
        	else if(str1[i] != lcs[k]) {
        		ans += str1[i];
        		i++;
        	}
        	else if(str2[j] != lcs[k]) {
        		ans += str2[j];
        		j++;
        	}

        }
        while(i < n1) {
        	ans += str1[i++];
        }
        while(j < n2) {
        	ans += str2[j++];
        }
        return ans;
    }
};

int main() {
	Solution solve;
	string str1, str2;
	cin >> str1 >> str2;
	string ans = solve.shortestCommonSupersequence(str1, str2);
	cout << ans << endl;
	return 0;
}