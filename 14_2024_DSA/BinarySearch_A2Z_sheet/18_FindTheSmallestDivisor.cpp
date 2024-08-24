#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxEle = INT_MIN;
        for(int i=0; i<n; i++) {
        	maxEle = max(maxEle, nums[i]);
        }
        int s=1, e=maxEle, ans=maxEle;
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	int sum = 0;
        	for(int i=0; i<n; i++) {
        		int curr = ((nums[i]+(mid-1)) / mid);
        		sum += curr;
        	}
        	if(sum <= threshold) {
        		ans = mid;
        		// find a smaller divisor
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
	int n, threshold;
	cin >> n >> threshold;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	Solution solve;
	int ans = solve.smallestDivisor(nums, threshold);
	cout << ans << "\n";
	return 0;
}