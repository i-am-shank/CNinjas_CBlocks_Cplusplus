#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(1)
    int maxProfit(vector<int>& prices) {
        int maxP = 0, profit = 0, n = prices.size();
        int costP = prices[0], sellP;
        for(int i=1; i<n; i++) {
        	int profit = prices[i] - costP;
        	maxP = max(profit, maxP);
        	costP = min(costP, prices[i]);
        }
        return maxP;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> prices;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		prices.push_back(ele);
	}
	int ans = solve.maxProfit(prices);
	cout << ans << endl;
	return 0;
}