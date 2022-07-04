#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
	// Time : O(n^2)
	// Space : O(n)
	int maxProfit_dp_space(int n, vector<int>& prices, int fee) {
		vector<int> nextRow(2,0);
		// Base case
		nextRow[0] = nextRow[1] = 0;
		for(int i=n-1; i>=0; i--) {
			vector<int> currRow(2,0);
			for(int buy=0; buy<2; buy++) {
				if(buy) {
					int profit1 = nextRow[0] - prices[i];
					int profit2 = nextRow[1];
					currRow[buy] = max(profit1, profit2);
				}
				else {
					int profit1 = nextRow[1] + prices[i] - fee;
					// After selling -> transaction fee
					int profit2 = nextRow[0];
					currRow[buy] = max(profit1, profit2);
				}
			}
			nextRow = currRow;
		}
		return nextRow[1];
	}

public:
	// Similar to BuyAnd..II (infinite transactions)
	// Just keep adding transaction fee (after selling)
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int ans = maxProfit_dp_space(n, prices, fee);
        return ans;
    }
};

int main() {
	int n, fee;
	cin >> n >> fee;
	vector<int> prices;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		prices.push_back(ele);
	}
	Solution solve;
	int ans = solve.maxProfit(prices, fee);
	cout << ans << endl;
	return 0;
}