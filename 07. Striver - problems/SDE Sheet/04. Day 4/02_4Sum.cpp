#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Avoiding duplicates.. is the main task in this problem
	//   -> Not faced such techniques in any other problems

	// Time : O(n^3) + O(nlogn) .. sorting 
	//      .. (n^2) for first 2 & (n) for last 2 (sorted array)
	// Space : O(1)

	vector<vector<int>> fourSum1(vector<int>& nums, int target) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int i=0, j=1, left, right;
		vector<vector<int>> ans;
		if(nums.empty()) {
			return ans;
		}
		while(i < n) {
			j = i+1; // j & i will adjust to avoid duplicates
			while(j < n) {
				int sum = nums[i] + nums[j];
				left = (j+1), right=(n-1);
				while(left < right) {
					int rem = (target-sum);
					int currSum = nums[left] + nums[right];
					if(currSum == rem) {
						vector<int> ele(4,0);
						ele[0] = (nums[i]);
						ele[1] = (nums[j]);
						ele[2] = (nums[left]);
						ele[3] = (nums[right]);
						ans.push_back(ele);
						// Now shift both left & right
						// (to avoid duplicates)
						int prevRight = nums[right];
						while(right>=0 && nums[right] == prevRight) {
							right--; // Avoid duplicates
						}
						int prevLeft = nums[left];
						while(left<n && nums[left] == prevLeft) {
							left++; // Avoid duplicates
						}
					}
					else if(currSum > rem) {
						// Decrease currSum .. shift right
						int prevRight = nums[right];
						while(right>=0 && nums[right] == prevRight) {
							right--; // Avoid duplicates
						}
					}
					else {
						// Increase currSum .. shift left
						int prevLeft = nums[left];
						while(left<n && nums[left] == prevLeft) {
							left++; // Avoid duplicates
						}
					}
				}
				int prevj = nums[j];
				while(j<n && nums[j]==prevj) {
					j++;
				}
			}
			int previ = nums[i];
			while(i<n && nums[i]==previ) {
				i++;
			}
		}
		return ans;
	}

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans = fourSum1(nums, target);
        return ans;
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
	vector<vector<int>> ans = solve.fourSum(nums, target);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}