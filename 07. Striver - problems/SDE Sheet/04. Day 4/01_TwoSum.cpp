#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
        	if(indexMap.find(target-nums[i]) != indexMap.end()) {
        		// Both nums[i] & (target-nums[i]) are present
        		// Both sum-up to target .. that's what is required
        		ans.push_back(i);
        		ans.push_back(indexMap[target-nums[i]]);
        		return ans;
        	}
        	indexMap[nums[i]] = i;
        }
        return ans; // This will not reach.. as given in question
        // ..As there always exists an answer
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
	vector<int> ans = solve.twoSum(nums, target);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}