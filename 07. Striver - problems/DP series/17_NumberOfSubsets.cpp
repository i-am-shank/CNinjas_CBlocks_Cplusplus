#include <bits/stdc++.h>
using namespace std;

// Tabulation  ->  space optimization
// Time : O(n^2)
// Space : O(n)
int count_dp_space(vector<int>& num, int n, int tar) {
	vector<int> prevRow(tar+1, 0);
	prevRow[0] = 1;
	for(int i=0; i<=n; i++) {
		vector<int> currRow(tar+1, 0);
		currRow[0] = 1;
		for(int j=1; j<=tar; j++) {
			if(i == 0) {
				if(num[0] <= j) {
					currRow[num[0]] = 1;
				}
			}
			else {
				int take = 0;
				if(num[i] <= j) {
					take += prevRow[j-num[i]];
				}
				int notTake = prevRow[j];
				currRow[j] = (take + notTake);
			}
		}
		prevRow = currRow;
	}
	return prevRow[tar];
}

// Tabulation
// Time : O(n^2)
// Space : O(n^2)
int count_dp(vector<int>& num, int n, int tar) {
	vector<vector<int>> dp(n+1, vector<int>(tar+1, 0));
	for(int i=0; i<=n; i++) {
		dp[i][0] = 1;
	}
	if(num[0] <= tar) {
		dp[0][num[0]] = 1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=tar; j++) {
			int take = 0;
			if(num[i] <= j) {
				take += dp[i-1][j-num[i]];
			}
			int notTake = dp[i-1][j];
			dp[i][j] = (take + notTake);
		}
	}
	return dp[n][tar];
}

// Memoization
// Time : O(n^2)
// Space : O(n^2) + O(n) .. Recursion stack
int count_mem_help(vector<int>& num, int n, int tar, vector<vector<int>>& dp) {
	if(tar == 0) {
		return 1;
	}
	if(n == 0) {
		if(num[0] == tar) {
			return 1;
		}
		return 0;
	}
	if(dp[n][tar] != -1) {
		return dp[n][tar];
	}
	int take = 0;
	if(num[n] <= tar) {
		take += count_mem_help(num, n-1, tar-num[n], dp);
	}
	int notTake = count_mem_help(num, n-1, tar, dp);
	dp[n][tar] = (take + notTake);
	return dp[n][tar];
}

int count_mem(vector<int>& num, int n, int tar) {
	vector<vector<int>> dp(n+1, vector<int>(tar+1,-1));
	return count_mem_help(num, n, tar, dp);
}

// Recursion
// Time : O(2^n)
// Space : O(n) .. Recursion stack
int count_rec(vector<int>& num, int n, int tar) {
	if(tar == 0) {
		return 1;
	}
	if(n == 0) {
		if(num[0] == tar) {
			return 1;
		}
		return 0;
	}
	int take = 0;
	if(num[n] <= tar) {
		take += count_rec(num, n-1, tar-num[n]);
	}
	int notTake = count_rec(num, n-1, tar);
	return (take + notTake);
}

int findWays(vector<int> &num, int tar){
    int n = num.size();
    // int ans1 = count_rec(num, n-1, tar);
    // int ans2 = count_mem(num, n-1, tar);
    // int ans3 = count_dp(num, n-1, tar);
    int ans4 = count_dp_space(num, n-1, tar);
    return ans4;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, tar;
		cin >> n >> tar;
		vector<int> num;
		for(int i=0; i<n; i++) {
			int ele;
			cin >> ele;
			num.push_back(ele);
		}
		int ans = findWays(num, tar);
		cout << ans << endl;
	}
	return 0;
}