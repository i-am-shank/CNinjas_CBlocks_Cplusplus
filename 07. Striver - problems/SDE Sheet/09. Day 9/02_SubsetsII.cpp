#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getSubsets(vector<int>& nums, int n, vector<int> subset, vector<vector<int>>& subsets) {
		if(n < 0) {
			subsets.push_back(subset);
			return;
		}
		getSubsets(nums, n-1, subset, subsets);
		subset.push_back(nums[n]);
		getSubsets(nums, n-1, subset, subsets);
		return;
	}

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        int n = nums.size();
        vector<int> subset;
        getSubsets(nums, n-1, subset, subsets);
        int m = subsets.size();
		set<vector<int>> check;
        vector<vector<int>> ans;
        for(int i=0; i<m; i++) {
        	if(check.count(subsets[i]) == 0) {
        		check.insert(subsets[i]);
        		ans.push_back(subsets[i]);
        	}
        }
        return ans;
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
	vector<vector<int>> ans = solve.subsetsWithDup(nums);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}