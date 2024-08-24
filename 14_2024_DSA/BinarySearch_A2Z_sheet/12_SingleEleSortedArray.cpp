#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
        	return nums[0];
        }
        int s=0, e=(n-1);
        while(s <= e) {
        	if(s == e) {
        		return nums[s];
        	}
        	int mid = (s + ((e-s)>>1));
        	if((mid%2) == 0) {
        		// (mid) & (mid+1) should have same element
        		if(nums[mid] == nums[mid+1]) {
        			// left-half don't have that no.
        			s = (mid+1);
        		}
        		else {
        			if(mid == 0) {
        				// this is the no.
        				return nums[mid];
        			}
        			else if(nums[mid] == nums[mid-1]) {
        				// search in left-half
        				e = (mid-1);
        			}
        			else {
        				// this is the no.
        				return nums[mid];
        			}

        		}
        	}
        	else {
        		// (mid) & (mid-1) should be same
        		if(nums[mid] == nums[mid-1]) {
        			// left-half don't have the no.
        			s = (mid+1);
        		}
        		else {
        			if(mid == (n-1)) {
        				// this is the no.
        				return nums[mid];
        			}
        			else if(nums[mid] == nums[mid+1]) {
        				// serach in left half
        				e = (mid-1);
        			}
        			else {
        				return nums[mid];
        			}
        		}
        	}
        }
        return -1; // execution won't reach here
        // as it is said, their is always one answer
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
	cout << ans << "\n";
	return 0;
}