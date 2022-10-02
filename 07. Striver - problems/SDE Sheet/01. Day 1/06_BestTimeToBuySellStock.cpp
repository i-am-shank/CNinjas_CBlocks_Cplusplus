#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit=0, profit=0;
        int minPrevPrice = prices[0];
        for(int i=1; i<n; i++) {
        	profit = (prices[i] - minPrevPrice);
        	maxProfit = max(maxProfit, profit);
        	minPrevPrice = min(minPrevPrice, prices[i]);
        }
        return maxProfit;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> prices(n);
	for(int i=0; i<n; i++) {
		cin >> prices[i];
	}
	int ans = solve.maxProfit(prices);
	cout << ans << "\n";
	return 0;
}