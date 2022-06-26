#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n*n)
	// Space : O(n)
	int minTotal_dp_space(vector<vector<int>>& triangle, int n) {
		vector<int> prevRow(n, 0);
		for(int i=n-1; i>=0; i--) {
			vector<int> currRow(n, 0);
			for(int j=0; j<=i; j++) {
				if(i== n-1) {
					currRow[j] = triangle[i][j];
				}
				else {
					int choice1 = prevRow[j+1];
					int choice2 = prevRow[j];
					currRow[j] += (triangle[i][j] + min(choice1, choice2));
				}
			}
			prevRow = currRow;
		}
		return prevRow[0];
	}

	// Tabulation
	// Time : O(n*n)
	// Space : O(n*n)
	int minTotal_dp(vector<vector<int>>& triangle, int n) {
		vector<vector<int>> dp;
		for(int i=0; i<n; i++) {
			vector<int> row(i+1, 0);
			dp.push_back(row);
		}
		for(int i=n-1; i>=0; i--) {
			for(int j=0; j<=i; j++) {
				if(i== n-1) {
					dp[i][j] = triangle[i][j];
				}
				else {
					int choice1 = dp[i+1][j+1];
					int choice2 = dp[i+1][j];
					dp[i][j] += (triangle[i][j] + min(choice1, choice2));
				}
			}
		}
		return dp[0][0];
	}

	// Memoization
	// Time : O(n*n)
	// Space : O(n*n)  + O(n*n)  ->  Recursion stack
	int minTotal_mem_help(vector<vector<int>>& triangle, int n, int i, int j, vector<vector<int>>& dp) {
		if(i >= n) {
			return 0;
		}
		if(dp[i][j] != -1) {
			return dp[i][j];
		}
		int ans1 = minTotal_mem_help(triangle, n, i+1, j, dp);
		int ans2 = minTotal_mem_help(triangle, n, i+1, j+1, dp);
		dp[i][j] = triangle[i][j] + min(ans1, ans2);
		return dp[i][j];
	}

	int minTotal_mem(vector<vector<int>>& triangle, int n, int i, int j) {
		vector<vector<int>> dp;
		for(int i=0; i<n; i++) {
			vector<int> row(i+1, -1);
			dp.push_back(row);
		}
		int ans = minTotal_mem_help(triangle, n, i, j, dp);
		return ans;
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(2^n)  ..  Recursion stack
	int minTotal_rec(vector<vector<int>>& triangle, int n, int i, int j) {
		if(i >= n) {
			return 0;
		}
		int ans1 = minTotal_rec(triangle, n, i+1, j);
		int ans2 = minTotal_rec(triangle, n, i+1, j+1);
		return triangle[i][j] + min(ans1, ans2);
	}

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans1 = minTotal_rec(triangle, n, 0, 0);
        int ans2 = minTotal_mem(triangle, n, 0, 0);
        int ans3 = minTotal_dp(triangle, n);
        int ans4 = minTotal_dp_space(triangle, n);
        return ans4;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<vector<int>> triangle;
	for(int i=0; i<n; i++) {
		vector<int> row;
		for(int j=0; j<=i; j++) {
			int ele;
			cin >> ele;
			row.push_back(ele);
		}
		triangle.push_back(row);
	}
	int ans = solve.minimumTotal(triangle);
	cout << ans << endl;
	return 0;
}