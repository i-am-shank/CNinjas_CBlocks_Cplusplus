#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation
	// Time : O(n^3)  .. O(n) loop
	// Space : O(n^2)
	int minCost_dp(int n, vector<int>& cuts) {
		int m = cuts.size();
		vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
		// Base case  ->  no need (default value is 0)
		for(int s=m-2; s>=1; s--) {
			for(int e=s; e<m-1; e++) {
				int minCost = 1e9;
				for(int i=s; i<=e; i++) {
					int cost = (cuts[e+1] - cuts[s-1]);
					cost += dp[s][i-1];
					cost += dp[i+1][e];
					minCost = min(minCost, cost);
				}
				dp[s][e] = minCost;
			}
		}
		return dp[1][m-2];
	}

	// Memoization
	// Time : O(n^3)  .. O(n) loop
	// Space : O(n^2) + Linear .. Recursion stack
	int minCost_mem_help(int n, int s, int e, vector<int>& cuts, vector<vector<int>>& dp) {
		// Base case
		if(s > e) {
			return 0;
		}
		if(dp[s][e] != -1) {
			return dp[s][e];
		}
		int minCost = 1e9;
		for(int i=s; i<=e; i++) {
			int cost = (cuts[e+1] - cuts[s-1]);
			cost += minCost_mem_help(n, s, i-1, cuts, dp);
			cost += minCost_mem_help(n, i+1, e, cuts, dp);
			minCost = min(minCost, cost);
		}
		dp[s][e] = minCost;
		return dp[s][e];
	}

	int minCost_mem(int n, int s, int e, vector<int>& cuts) {
		int m = cuts.size();
		vector<vector<int>> dp(m+1, vector<int>(m+1,-1));
		return minCost_mem_help(n, s, e, cuts, dp);
	}

	// Recursion
	// Time : Exponential
	// Space : Linear .. Recursion stack
	int minCost_rec(int n, int s, int e, vector<int> cuts) {
		// Base case
		if(s > e) {
			return 0;
		}
		int minCost = 1e9;
		for(int i=s; i<=e; i++) {
			int cost = (cuts[e+1] - cuts[s-1]);
			cost += minCost_rec(n, s, i-1, cuts);
			cost += minCost_rec(n, i+1, e, cuts);
			minCost = min(minCost, cost);
		}
		return minCost;
	}

public:
    int minCost(int n, vector<int>& cuts) {
    	cuts.push_back(0);
    	cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        // int ans1 = minCost_rec(n, 1, size-2, cuts);
        // int ans2 = minCost_mem(n, 1, size-2, cuts);
        int ans3 = minCost_dp(n, cuts);
        return ans3;
    }
};

int main() {
	Solution solve;
	int n, m;
	cin >> n >> m;
	vector<int> cuts;
	for(int i=0; i<m; i++) {
		int ele;
		cin >> ele;
		cuts.push_back(ele);
	}
	int ans = solve.minCost(n, cuts);
	cout << ans << endl;
	return 0;
}