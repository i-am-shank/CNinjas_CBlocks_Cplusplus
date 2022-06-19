#include <bits/stdc++.h>
using namespace std;

class Solution {
	void fourSumHelp(vector<int>& nums, vector<int>& flag, int target, vector<int> temp, vector<vector<int>>& ans) {
		if(temp.size() > 4) {
			return;
		}
		if(target == 0) {
			if(temp.size() == 4) {
				ans.push_back(temp);
			}
			return;
		}
		for(int i=0; i<nums.size(); i++) {
			if(flag[i] == 0) {  // Not visited
				flag[i] = 1;
				target -= nums[i];
				temp.push_back(nums[i]);
				fourSumHelp(nums, flag, target, temp, ans);
				// Backtrack .. for searching for next solutions.
				temp.pop_back();
				target += nums[i];
				flag[i] = 0;
			}
		}
		return;
	}

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<int> temp;
    	vector<int> flag;
    	for(int i=0; i<nums.size(); i++) {
    		flag[i] = 0;
    	}
    	vector<vector<int>> ans;
        fourSumHelp(nums, flag, target, temp, ans);
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	int target;
	cin >> target;
	Solution solve;
	vector<vector<int>> ans = solve.fourSum(nums, target);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}