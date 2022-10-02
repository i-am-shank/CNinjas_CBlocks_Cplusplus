#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Kadane's algorithm
	// Time : O(n)
	// Space : O(1)
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN, currSum=0, n=nums.size();
        for(int i=0; i<n; i++) {
        	currSum += nums[i];
        	maxSum = max(maxSum, currSum);
        	if(currSum < 0) {
        		currSum = 0; // Not add backlogs to next subarray-sums
        	}
        }
        return maxSum;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	Solution solve;
	int ans = solve.maxSubArray(nums);
	cout << ans << "\n";
	return 0;
}