#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(n)
    vector<int> majorityElement(vector<int>& nums) {
        // Finding all elements.. freq > (n/2)
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0; i<n; i++) {
        	freq[nums[i]]++;
        }
        vector<int> ans;
        for(auto it: freq) {
        	// cout << it.first << " " << it.second << "\n";
        	if(it.second > (n/3)) {
        		ans.push_back(it.first);
        	}
        }
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
	vector<int> ans = solve.majorityElement(nums);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}