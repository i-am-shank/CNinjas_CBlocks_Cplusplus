#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
        	if(indexMap.find(target-nums[i]) != indexMap.end()) {
        		ans.push_back(indexMap[target-nums[i]]);
        		ans.push_back(i);
        		return ans;
        	}
        	else {
        		indexMap.insert(make_pair(nums[i], i));
        	}
        }
        return ans;  // Never reaches this state.. as has atleast 1 answer.
    }
};

int main() {
	Solution solve;
	vector<int> nums;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	int target;
	cin >> target;
	vector<int> ans = solve.twoSum(nums, target);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}