#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getPermutations(vector<int>& nums, int n, int count, unordered_map <int,int> check, vector<int> permut, vector<vector<int>>& ans) {
		if(count == n) {
			ans.push_back(permut);
			return; // A permutation is created
		}
		for(int i=0; i<n; i++) {
			if(check[nums[i]] == 0) {
				check[nums[i]]++;
				permut.push_back(nums[i]);
				getPermutations(nums, n, count+1, check, permut, ans);
				permut.pop_back();
				check[nums[i]]--;
			}
		}
		return;
	}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int> check;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> permut;
        getPermutations(nums, n, 0, check, permut, ans);
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