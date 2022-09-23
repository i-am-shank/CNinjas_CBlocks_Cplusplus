#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Memoization
	// Time : O(m*n)
	// Space : O(m+n) .. Recursion stack
	int count_mem_help(vector<vector<int>>& arr, int m, int n, vector<vector<int>>& dp) {
		int mod = 1e9+7;
		if(m<0 || n<0 || arr[n][m]==-1) {
			return 0; // Edge case
		}
		if(m==0 && n==0) {
			return 1; // Base case
		}
		if(dp[m][n] != -1) {
			return dp[m][n] % mod;
		}
		int up=0, left=0;
		if(m > 0) {
			up = count_mem_help(arr, m-1, n, dp) % mod;
		}
		if(n > 0) {
			left = count_mem_help(arr, m, n-1, dp) % mod;
		}
		return dp[m][n] = ((up%mod) + (left%mod)) % mod;
	}

	int count_mem(vector<vector<int>>& arr, int m, int n) {
		int mod = 1e9+7;
		vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
		return count_mem_help(arr, m, n, dp) % mod;
	}

public:
	int FindWays(int n, int m, vector<vector<int>> blocked_cells) {
		vector<vector<int>> arr(n, vector<int>(m,0));
		int k = blocked_cells.size();
		for(int i=0; i<k; i++) {
			int a=blocked_cells[i][0], b=blocked_cells[i][1];
			cin >> a >> b;
			a--, b--; // 0-indexing
			arr[a][b] = -1; // blocked
		}
		int mod = 1e9+7;
		int ans1 = count_mem(arr, n-1, m-1)%mod;
		return ans1%mod;
	}
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> blocked_cells(k, vector<int>(2,0));
	for(int i=0; i<k; i++) {
		cin >> blocked_cells[i][0] >> blocked_cells[i][1];
	}
	Solution solve;
	int ans = solve.FindWays(n, m, blocked_cells);
	cout << ans << "\n";
	return 0;
}