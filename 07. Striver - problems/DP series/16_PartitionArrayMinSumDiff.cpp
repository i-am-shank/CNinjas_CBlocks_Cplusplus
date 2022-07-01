// Code Studio questions

#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool subsetSum_dp(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
		for(int i=0; i<=n; i++) {
			dp[i][0] = 1;
		}
		if(nums[0] <= sum) {
			dp[0][nums[0]] = 1;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=sum; j++) {
				int take = 0;
				if(nums[i] <= j) {
					take = dp[i-1][j-nums[i]];
				}
				int notTake = dp[i-1][j];
				dp[i][j] = (take || notTake);
			}
		}
		return dp[n][sum];
	}

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
        	sum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        bool dummy = subsetSum_dp(nums, n-1, sum, dp); // Just used to fill the dp matrix..
        int minDiff = INT_MAX;
        // Not solvable by exactly this approach for  "-ve elements"
        for(int i=0; i<=sum; i++) {
        	int isPresent = dp[n-1][i];
        	if(isPresent == 1) {
        		int diff = abs((sum-i) - i);
        		minDiff = min(minDiff, diff);
        	}
        }
        return minDiff;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	int ans = solve.minimumDifference(nums);
	cout << ans << endl;
	return 0;
}