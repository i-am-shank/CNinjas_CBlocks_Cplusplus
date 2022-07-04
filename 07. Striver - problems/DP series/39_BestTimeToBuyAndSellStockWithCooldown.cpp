#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation
	// Time : O(n^2)
	// Space : O(n^2)
	int maxProfit_dp(int n, vector<int>& prices) {
		vector<vector<int>> dp(n+1, vector<int>(2,0));
		// Base case
		dp[n][0] = dp[n][1] = 0;
		for(int i=n-1; i>=0; i--) {
			for(int buy=0; buy<2; buy++) {
				if(buy) {
					int profit1 = dp[i+1][0] - prices[i];
					int profit2 = dp[i+1][1];
					dp[i][buy] = max(profit1, profit2);
				}
				else {
					int profit1 = prices[i];
					if(i < n-1) {
						profit1 += dp[i+2][1];
					}
					int profit2 = dp[i+1][0];
					dp[i][buy] = max(profit1, profit2);
				}
			}
		}
		return dp[0][1];
	}

public:
	// Similar problem to BuyAnd..II (infinite buy-sell)
	// Just 1-tweak -> After selling -> Recursion call to (i+2)th day
	// ....There we were doing recursion call at (i+1)th day
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();
        return maxProfit_dp(n, prices);
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> prices;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		prices.push_back(ele);
	}
	Solution solve;
	int ans = solve.maxProfit(prices);
	cout << ans << endl;
	return 0;
}