#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s=0, e=(n-1);
        int ans = INT_MAX;
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	if(nums[s] <= nums[mid]) {
        		// left half sorted
        		ans = min(ans, nums[s]);
        		// find a smaller element in right half now
        		s = (mid+1);
        	}
        	else {
        		// right half sorted
        		ans = min(ans, nums[mid]);
        		// find a smaller element in left half now
        		e = (mid-1);
        	}
        }
        return ans;
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
	int ans = solve.findMin(nums);
	cout << ans << "\n";
	return 0;
}