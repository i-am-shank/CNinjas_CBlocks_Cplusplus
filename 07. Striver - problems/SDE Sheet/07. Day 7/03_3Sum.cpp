#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Time : O(n^3)
	// .. will give TLE (sure)
	vector<vector<int>> threeSum_bf(vector<int>& nums) {
		vector<vector<int>> ans;
		int n = nums.size();
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				for(int k=j+1; k<n; k++) {
					int sum = (nums[i]+nums[j]+nums[k]);
					if(sum == 0) {
						vector<int> ele;
						ele.push_back(nums[i]);
						ele.push_back(nums[j]);
						ele.push_back(nums[k]);
						ans.push_back(ele);
					}
				}
			}
		}
		return ans;
	}

	// Time : O(n^2) + O(nlogn)
	// .. O(nlogn)  ->  for sorting
	// .. O(n)  ->  for outer element
	// .. O(n)  ->  for target-sum (2 elements) in sorted-array 
	vector<vector<int>> threeSum_better(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int i=0;
		while(i < (n-2)) {
			int s=i+1, e=n-1;
			int target = ((-1) * (nums[i]));
			while(s < e) {
				int sum = nums[s] + nums[e];
				if(sum == target) {
					// Found 1 - entry
					vector<int> ele;
					ele.push_back(nums[i]);
					ele.push_back(nums[s]);
					ele.push_back(nums[e]);
					ans.push_back(ele);
					// Change both
					// To a different value (to avoid duplicates)
					int prevs = nums[s], preve = nums[e];
					while(s<n && nums[s]==prevs) {
						s++;
					}
					while(e>=0 && nums[e]==preve) {
						e--;
					}
				}
				else if(sum > target) {
					// Have to decrease sum.. change e
					int preve = nums[e];
					while(e>=0 && nums[e]==preve) {
						e--;
					}
				}
				else {
					// Have to increase sum.. change s
					int prevs = nums[s];
					while(s<n && nums[s]==prevs) {
						s++;
					}
				}
			}
			int previ = nums[i];
			while(i<(n-2) && previ==nums[i]) {
				i++;
			}
		}
		return ans;
	}

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>> ans1 = threeSum_bf(nums);
        vector<vector<int>> ans2 = threeSum_better(nums);
        return ans2;
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
	vector<vector<int>> ans = solve.threeSum(nums);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}