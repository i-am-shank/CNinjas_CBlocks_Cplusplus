#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int i2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(i1==n || nums[i1]!=target) {
        	// no occurence of element
        	vector<int> ans;
        	ans.push_back(-1);
        	ans.push_back(-1);
        	return ans;
        }
        else {
        	vector<int> ans;
        	ans.push_back(i1);
        	ans.push_back(i2-1);
        	return ans;
        }
    }
};

int main() {
	int n, target;
	cin >> n >> target;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	Solution solve;
	vector<int> ans = solve.searchRange(nums, target);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}