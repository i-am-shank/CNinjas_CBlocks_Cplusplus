#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(1)
    int majorityElement(vector<int>& nums) {
        int element=nums[0], freq=1, n=nums.size();
        for(int i=1; i<n; i++) {
        	if(element != nums[i]) {
        		if(freq == 0) {
        			element = nums[i];
        			freq++;
        		}
        		else {
        			freq--;
        		}
        	}
        	else {
        		freq++;
        	}
        }
        return element;
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
	int ans = solve.majorityElement(nums);
	cout << ans << "\n";
	return 0;
}