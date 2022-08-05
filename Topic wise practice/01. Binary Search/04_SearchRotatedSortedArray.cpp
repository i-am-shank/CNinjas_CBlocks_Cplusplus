#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Applying logic .. at any index (atleast 1 of left & right-half is sorted)
	// -> If an half is sorted .. We'll check possibility of target in it
	//        .. by comparing with extremes
	//    If not found possibility .. will check in other half
	// -> If 1st half checking .. was not sorted  ->  process in 2nd half

	// Time : O(logn)
	// Space : O(1)
    int search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-2;
        while(s <= e) {
        	int mid = (s+e) >> 1;
        	if(nums[mid] == target) {
        		return mid;
        	}
        	else if(nums[mid] >= nums[s]) { // left-half sorted
        		if(target>=nums[s] && target<=nums[mid]) {
        			e = mid;
        		}
        		else {
        			s = mid+1;
        		}
        	}
        	else { // right-half sorted
        		if(target>=nums[mid+1] && target<=nums[e]) {
        			s = mid+1;
        		}
        		else {
        			e = mid;
        		}
        	}
        }
        return -1;
    }
};

int main() {
	Solution solve;
	int n, target;
	cin >> n >> target;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	int ans = solve.search(nums, target);
	cout << ans << endl;
	return 0;
}