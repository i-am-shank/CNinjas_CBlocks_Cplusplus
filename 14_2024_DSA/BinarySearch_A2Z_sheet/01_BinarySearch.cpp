#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s=0, e=(n-1);
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	if(nums[mid] == target) {
        		return mid;
        	}
        	else if(nums[mid] > target) {
        		// search smaller nos.
        		e = (mid-1);
        	}
        	else {
        		// search larger nos.
        		s = (mid+1);
        	}
        }
        return -1; // not found, so reached here
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
	int ans = solve.search(nums, target);
	cout << ans << "\n";
	return 0;
}