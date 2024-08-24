#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int s=0, e=(n-1);
        int ans = n;
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	if(nums[mid] == target) {
        		return mid;
        	}
        	else if(nums[mid] > target) {
        		ans = mid;
        		// search for a smaller no.
        		e = (mid-1);
        	}
        	else {
        		s = (mid+1);
        	}
        }
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
	int ans = solve.searchInsert(nums, target);
	cout << ans << "\n";
	return 0;
}