#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0], maxProfit = 0, profit, n = prices.size();
        for(int i=1; i<n; i++) {
        	profit = prices[i] - minVal;
        	maxProfit = max(maxProfit, profit);
        	minVal = min(minVal, prices[i]);
        }
        return maxProfit;
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