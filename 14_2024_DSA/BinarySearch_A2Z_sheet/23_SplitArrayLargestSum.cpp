#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle=INT_MIN, sum=0;
        for(int i=0; i<n; i++) {
        	sum += nums[i];
        	maxEle = max(maxEle, nums[i]);
        }
        int s=maxEle, e=sum;
        int ans = e;
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	// check if (mid) is a possible largest sum
        	int count=1, curr=0;
        	for(int i=0; i<n; i++) {
        		curr += nums[i];
        		if(curr > mid) {
        			count++;
        			curr = nums[i];
        		}
        	}
        	if(count <= k) {
        		// if got anything less than k,
        		// can get k-arrays within this largest sum
        		ans = mid;
        		// search for a smaller sum
        		e = (mid-1);
        	}
        	else {
        		// search for a larger sum
        		s = (mid+1);
        	}
        }
        return ans;
    }
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	Solution solve;
	int ans = solve.splitArray(nums, k);
	cout << ans << "\n";
	return 0;
}