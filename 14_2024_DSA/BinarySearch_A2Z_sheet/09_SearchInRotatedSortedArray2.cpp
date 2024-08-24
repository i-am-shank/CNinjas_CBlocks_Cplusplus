#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0, e=(n-1);
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	if(nums[mid] == target) {
        		return true;
        	}
        	else if(nums[mid]==nums[s] && nums[mid]==nums[e]) {
        		// can't find sorted half
        		//   --> in all other case, can find sorted half
        		// shrink the search space
        		// as none of nums[s] & nums[e] are target element
        		s++;
        		e--;
        	}
        	else if(nums[mid] > target) {
        		// search smaller no.
        		if(nums[s] <= nums[mid]) {
        			// left half sorted
        			if(nums[s] <= target) {
        				// no. in index-range [s, mid-1]
        				e = (mid-1);
        			}
        			else {
        				s = (mid+1);
        			}
        		}
        		else {
        			// right half sorted
        			e = (mid-1);
        		}
        	}
        	else {
        		// search larger no.
        		if(nums[s] <= nums[mid]) {
        			// right half sorted
        			s = (mid+1);
        		}
        		else {
        			if(nums[e] >= target) {
        				// no. in index-range [mid+1, e]
        				s = (mid+1);
        			}
        			else {
        				// try searching in left half
        				// coz no. not in right half
        				e = (mid-1);
        			}
        		}
        	}
        }
        return false; // not found, that's why reached here
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
	bool ans = solve.search(nums, target);
	if(ans == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}
	return 0;
}