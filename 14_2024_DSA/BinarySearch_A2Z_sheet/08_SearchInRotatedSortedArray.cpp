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
        		// search a smaller no.
        		// check if left half is sorted :-
        		if(nums[s] <= nums[mid]) {
        			// yes it is sorted !
        			if(nums[s] <= target) {
        				// target must lie in [s, mid-1]
        				e = (mid-1);
        			}
        			else {
        				// target not in [s, mid]
        				s = (mid+1);
        			}
        		}
        		else {
        			// right half is sorted
        			// (as one of the half will be sorted always)
        			// And have to get a smaller no.
        			e = (mid-1);
        		}
        	}
        	else {
        		// search a larger no.
        		if(nums[s] <= nums[mid]) {
        			// left half is sorted
        			// no. won't be in left half
        			s = (mid+1);
        		}
        		else {
        			// right half is sorted
        			if(nums[e] < target) {
        				// need a larger no.
        				// try in left half
        				e = (mid-1);
        			}
        			else {
        				// no. is in [mid+1, e]
        				s = (mid+1);
        			}
        		}
        	}
        }
        return -1; // reached here, means not found
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