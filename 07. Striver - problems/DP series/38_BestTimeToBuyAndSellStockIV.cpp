#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Tabulation  ->  space optimization
    // Time : O(n^3)
    // Space : O(n^2)
	int maxProfit_dp_space(int n, vector<int>& prices, int k) {
		vector<vector<int>> nextIter(2, vector<int>(k+1,0));
		vector<vector<int>> currIter(2, vector<int>(k+1,0));
		for(int i=n-1; i>=0; i--) {
			for(int buy=0; buy<2; buy++) {
				for(int cap=1; cap<k+1; cap++) {
					if(buy == 1) {
						int profit1 = nextIter[0][cap] - prices[i];
						int profit2 = nextIter[1][cap];
						currIter[buy][cap] = max(profit1, profit2);
					}
					else if(buy == 0) {
						int profit1 = nextIter[1][cap-1] + prices[i];
						int profit2 = nextIter[0][cap];
						currIter[buy][cap] = max(profit1, profit2);
					}
				}
			}
			nextIter = currIter;
		}
		return nextIter[1][k]; // Sending index 0 to buy(1) with (2) caps.
	}

public:
	// Similar problem to BestTime..III  ->  There at most 2 transaction
	// Here  -> at most k transaction  ->  Just edit parameters & same logic.
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int ans = maxProfit_dp_space(n, prices, k);
        return ans;
    }
};

int main() {
	Solution solve;
	int n, k;
	cin >> n >> k;
	vector<int> prices;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		prices.push_back(ele);
	}
	int ans = solve.maxProfit(k, prices);
	cout << ans << endl;
	return 0;
}