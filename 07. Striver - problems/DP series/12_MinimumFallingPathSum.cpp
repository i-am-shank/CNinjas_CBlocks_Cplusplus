#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  Space optimization
	// Time : O(n*n)
	// Space : O(n)
	int minPath_dp_space(vector<vector<int>>& matrix, int n) {
		vector<int> prevRow(n, 0);
		for(int i=0; i<n; i++) {
			vector<int> currRow(n, 0);
			for(int j=0; j<n; j++) {
				if(i == 0) {
					currRow[j] = matrix[i][j];
				}
				else {
					int choice1=INT_MAX, choice2=prevRow[j], choice3=INT_MAX;
					if(j > 0) {
						choice1 = prevRow[j-1];
					}
					if(j < n-1) {
						choice3 = prevRow[j+1];
					}
					currRow[j] += (matrix[i][j] + min(choice1, min(choice2,choice3)));
				}
			}
			prevRow = currRow;
		}
		int ans = INT_MAX;
		for(int i=0; i<n; i++) {
			ans = min(ans, prevRow[i]);
		}
		return ans;
	}

	// Tabulation
	// Time : O(n*n)
	// Space : O(n*n)
	int minPath_dp(vector<vector<int>>& matrix, int n) {
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for(int i=0; i<n; i++) {
			dp[0][i] = matrix[0][i];
		}
		for(int i=1; i<n; i++) {
			for(int j=0; j<n; j++) {
				int choice1=INT_MAX, choice2=dp[i-1][j], choice3=INT_MAX;
				if(j > 0) {
					choice1 = dp[i-1][j-1];
				}
				if(j < n-1) {
					choice3 = dp[i-1][j+1];
				}
				dp[i][j] += (matrix[i][j] + min(choice1, min(choice2,choice3)));
			}
		}
		int ans = INT_MAX;
		for(int i=0; i<n; i++) {
			ans = min(ans, dp[n-1][i]);
		}
		return ans;
	}

	// Memoization
	// Time : O(n*n)
	// Space : O(n*n)   + O(n*n) .. Recursion stack
	int minPath_mem_help(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>>& dp) {
		if(j<0 || j>=n) {
			return INT_MAX;
		}
		if(dp[i][j] != -1) {
			return dp[i][j];
		}
		if(i == 0) {
			dp[i][j] = matrix[i][j];
			return dp[i][j];
		}
		int choice1 = minPath_mem_help(matrix, n, i-1, j-1, dp);
		int choice2 = minPath_mem_help(matrix, n, i-1, j, dp);
		int choice3 = minPath_mem_help(matrix, n, i-1, j+1, dp);
		dp[i][j] = (matrix[i][j] + min(choice1, min(choice2,choice3)));
		return dp[i][j];
	}

	int minPath_mem(vector<vector<int>>& matrix, int n) {
		int ans = INT_MAX;
		vector<vector<int>> dp(n, vector<int>(n, -1));
		for(int i=0; i<n; i++) {
			int smallAns = minPath_mem_help(matrix, n, n-1, i, dp);
			ans = min(ans, smallAns);
		}
		return ans;
	}

	// Recursion
	// Time : O(3^n)
	// Space : O(3^n)  ..  Recursion stack
	int minPath_rec_help(vector<vector<int>>& matrix, int n, int i, int j) {
		if(j<0 || j>=n) {
			return INT_MAX;
		}
		if(i == 0) {
			return matrix[i][j];
		}
		int choice1 = minPath_rec_help(matrix, n, i-1, j-1);
		int choice2 = minPath_rec_help(matrix, n, i-1, j);
		int choice3 = minPath_rec_help(matrix, n, i-1, j+1);
		return (matrix[i][j] + min(choice1, min(choice2,choice3)));
	}

	int minPath_rec(vector<vector<int>>& matrix, int n) {
		int ans = INT_MAX;
		for(int i=0; i<n; i++) {
			int smallAns = minPath_rec_help(matrix, n, n-1, i);
			ans = min(ans, smallAns);
		}
		return ans;
	}

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        /*
        int ans1 = minPath_rec(matrix, n);
        int ans2 = minPath_mem(matrix, n);
        int ans3 = minPath_dp(matrix, n);
        */
        int ans4 = minPath_dp_space(matrix, n);
        return ans4;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<vector<int>> matrix;
	for(int i=0; i<n; i++) {
		vector<int> row;
		for(int j=0; j<n; j++) {
			int ele;
			cin >> ele;
			row.push_back(ele);
		}
		matrix.push_back(row);
	}
	int ans = solve.minFallingPathSum(matrix);
	cout << ans << endl;
	return 0;
}