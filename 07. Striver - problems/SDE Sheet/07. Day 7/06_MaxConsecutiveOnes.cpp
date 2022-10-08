#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen=0, curr=0, n=nums.size();
        for(int i=0; i<n; i++) {
        	if(nums[i] == 1) {
        		curr++;
        	}
        	else {
        		curr = 0; // consecutive-ness broken
        	}
        	maxLen = max(maxLen, curr);
        }
        return maxLen;
    }
};

int main() {
	int n;
	cin >> n;
	Solution solve;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	int ans = solve.findMaxConsecutiveOnes(nums);
	cout << ans << "\n";
	return 0;
}