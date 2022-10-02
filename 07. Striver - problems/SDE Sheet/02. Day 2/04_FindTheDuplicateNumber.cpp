#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(n)
    int findDuplicate(vector<int>& nums) {
    	unordered_map<int,int> freq;
    	int n = nums.size();
    	for(int i=0; i<n; i++) {
    		freq[nums[i]]++;
    	}
    	for(auto it: freq) {
    		if(it.second > 1) {
    			return it.first;
    		}
    	}
    	return 0; // This case never comes
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	int ans = solve.findDuplicate(nums);
	cout << ans << "\n";
	return 0;
}