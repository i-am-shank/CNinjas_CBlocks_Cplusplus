#include <bits/stdc++.h>
using namespace std;

// Front Partition

bool isPalindrome(int s, int e, string str) {
	while(s < e) {
		if(str[s] != str[e]) {
			return false;
		}
		s++;
		e--;
	}
	return true;
}

bool isPalindrome_mem(int s, int e, string str, vector<vector<int>>& checkPal) {
	if(checkPal[s][e] != -1) {
		return checkPal[s][e];
	}
	while(s < e) {
		if(str[s] != str[e]) {
			checkPal[s][e] = false;
			return checkPal[s][e];
		}
		s++;
		e--;
	}
	checkPal[s][e] = true;
	return checkPal[s][e];
}

class Solution {
	// Tabulation
	// Time : O(n^2)
	// Space : O(n)
	int minCut_dp(string s) {
		int n = s.size();
		vector<int> dp(n+1, 0);
		// Base case -> no need (default value = 0)
		for(int i=n-1; i>=0; i--) {
			int minCuts = 1e9;
			for(int j=i; j<n; j++) {
				if(isPalindrome(i,j,s)) {
					int cuts = 1 + dp[j+1];
					minCuts = min(minCuts, cuts);
				}
			}
			dp[i] = minCuts;
		}
		return dp[0];
	}

	// Memoization
	// Time : O(n^3)  .. O(n) loop
	// Space : O(n)  + O(n) .. Recursion stack
	int minCut_mem_help(int n, int i, string s, vector<int>& dp, vector<vector<int>>& checkPal) {
		// Base case
		if(i == n) { // Recursion call on empty string
			return 0; // always Doing partition on end (if possible)
		}
		if(dp[i] != -1) {
			return dp[i];
		}
		int minCuts = 1e9;
		for(int j=i; j<=n; j++) {
			if(isPalindrome_mem(i,j,s,checkPal)) {
				int cuts = 1 + minCut_mem_help(n, j+1, s, dp, checkPal);
				minCuts = min(minCuts, cuts);
			}
		}
		dp[i] = minCuts;
		return dp[i];
	}

	int minCut_mem(int n, int i, string s) {
		vector<int> dp(n+1,-1);
		vector<vector<int>> checkPal(n, vector<int>(n,-1));
		return minCut_mem_help(n, i, s, dp, checkPal);
	}

	// Recursion
	// Time : O(n^3) .. n-states (calculated n-times) + O(n) loop
	// Space : O(n) .. Recursion stack
	int minCut_rec(int n, int i, string s) {
		// Base case
		if(i == n) { // Recursion call on empty string
			return 0; // always Doing partition on end (if possible)
		}
		int minCuts = 1e9;
		for(int j=i; j<=n; j++) {
			if(isPalindrome(i,j,s)) {
				int cuts = 1 + minCut_rec(n, j+1, s);
				minCuts = min(minCuts, cuts);
			}
		}
		return minCuts;
	}

public:
    int minCut(string s) {
        int n = s.size();
        // as doing partition at end, do -1.
        // int ans1 = minCut_rec(n, 0, s) - 1;
        // int ans2 = minCut_mem(n, 0, s) - 1;
        int ans3 = minCut_dp(s) - 1;
        return ans3;
    }
};

int main() {
	Solution solve;
	string s;
	cin >> s;
	int ans = solve.minCut(s);
	cout << ans << endl;
	return 0;
}