#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Readable code
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        count[0] = 1;
        int lis = 1;
        for(int i=0; i<n; i++) {
        	for(int j=0; j<i; j++) {
        		if(nums[i]>nums[j] && dp[i]<dp[j]+1) {
        			dp[i] = dp[j] + 1;
        			count[i] = count[j];
        		}
        		else if(nums[i]>nums[j] && dp[i]==dp[j]+1) {
        			count[i] += count[j];
        		}
        	}
        	lis = max(lis, dp[i]);
        }
        int countLis = 0;
        for(int i=0; i<n; i++) {
        	if(dp[i] == lis) {
        		countLis += count[i];
        	}
        }
        return countLis;
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
	int ans = solve.findNumberOfLIS(nums);
	cout << ans << endl;
	return 0;
}