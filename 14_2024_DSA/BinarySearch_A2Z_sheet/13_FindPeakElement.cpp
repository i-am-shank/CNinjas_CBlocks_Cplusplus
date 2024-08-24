#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s=0, e=(n-1);
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	bool smallLeft = true, smallRight = true;
        	if(mid > 0) {
        		smallLeft = (nums[mid]>nums[mid-1]);
        	}
        	if(mid < (n-1)) {
        		smallRight = (nums[mid]>nums[mid+1]);
        	}
        	if(smallLeft && smallRight) {
        		return mid;
        	}
        	else if((smallLeft==true) && (smallRight==false)) {
        		// increasing slope
        		// peak in right direction
        		s = (mid+1);
        	}
        	else if((smallLeft==false) && (smallRight==true)) {
        		// decreasing slope
        		// peak in left direction
        		e = (mid-1);
        	}
        	else {
        		if(nums[s] > nums[mid]) {
        			e = (mid-1);
        		}
        		else if(nums[e] > nums[mid]) {
        			s = (mid+1);
        		}
        		else {
        			if(s<(n-1) && nums[s]>nums[s+1]) {
        				return s;
        			}
        			else if(e>0 && nums[e]>nums[e-1]) {
        				return e;
        			}
        			else {
        				s++;
        				e--;
        			}
        		}
        	}
        }
        return -1; // won't reach here ever
        // as per question
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
	int ans = solve.findPeakElement(nums);
	cout << ans << "\n";
	return 0;
}