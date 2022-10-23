#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getPermutation(vector<int>& nums, int n, int count, vector<int> p, vector<vector<int>>& ans, set<int> check) {
		if(count == n) {
			ans.push_back(p);
			return;
		}
		for(int i=0; i<n; i++) {
			if(check.find(nums[i]) == check.end()) {
				// Not taken yet
				p.push_back(nums[i]);
				check.insert(nums[i]);
				getPermutation(nums, n, count+1, p, ans, check);
				auto it = check.find(nums[i]);
				check.erase(it); // Backtrack
				p.pop_back();
			}
		}
		return;
	}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> p;
        int n = nums.size();
        set<int> check;
        getPermutation(nums, n, 0, p, ans, check);
        return ans;
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
	vector<vector<int>> ans = solve.permute(nums);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}