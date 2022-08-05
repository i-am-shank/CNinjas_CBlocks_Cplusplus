#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(logn)
	// Space : O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = nums[0], e = nums[n-1];
        while(s <= e) {
        	int mid = s + ((e-s)/2);
        	int count = upper_bound(nums.begin(), nums.end(), mid) - nums.begin();
        	// count  =  count of  >=  mid  elements
        	if(count % 2 == 0) { // odd element not in lower range
        		s = mid+1;
        	}
        	else {
        		e = mid-1;
        	}
        }
        return s;
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
	int ans = solve.singleNonDuplicate(nums);
	cout << ans << endl;
	return 0;
}