#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0, n = nums.size();
        for(int i=0; i<n; i++) {
        	sum += nums[i];
        	maxSum = max(maxSum, sum);
        	if(sum < 0) {
        		sum = 0;
        	}
        }
        return maxSum;
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
	int ans = solve.maxSubArray(nums);
	cout << ans << endl;
	return 0;
}