#include <bits/stdc++.h>
using namespace std;

class Solution{
	// Memoization
	// Time : O(n * (3*n))
	// Space : O(n^2) + O(n) .. Recursion stack
	int maxPath_mem_help(vector<vector<int>>& matrix, int i, int j, int n, vector<vector<int>>& dp) {
		if(j<0 || j>=n) {
			return -1e8;
		}
		if(i == 0) {
			// Reached last row
			return matrix[0][j];
		}
		if(dp[i][j] != -1) {
			return dp[i][j];
		}
		int ans1 = maxPath_mem_help(matrix, i-1, j, n, dp) + matrix[i][j];
		int ans2 = maxPath_mem_help(matrix, i-1, j-1, n, dp) + matrix[i][j];
		int ans3 = maxPath_mem_help(matrix, i-1, j+1, n, dp) + matrix[i][j];
		return dp[i][j] = max(ans1, max(ans2, ans3));
	}

	int maxPath_mem(vector<vector<int>>& matrix, int n) {
		vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
		int maxAns = 0;
		for(int i=0; i<n; i++) {
		    int ans = maxPath_mem_help(matrix, n-1, i, n, dp);
		    maxAns = max(maxAns, ans);
		}
		return maxAns;
	}

public:
    int maximumPath(int n, vector<vector<int>> matrix) {
    	int ans = maxPath_mem(matrix, n); // Time : O(n^2)
        return ans;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> matrix[i][j];
		}
	}
	int ans = solve.maximumPath(n, matrix);
	cout << ans << "\n";
	return 0;
}