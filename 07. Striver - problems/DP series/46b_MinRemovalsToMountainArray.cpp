#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Finding Longest Bitonic Sequence
	// Bitonic Sequence  ->  1 2 5 3 1
	//   (first increasing then decreasing)

	int getLBS(int n, vector<int>& nums) {
		vector<int> dp1(n,1);
		for(int i=0; i<n; i++) {
			for(int j=0; j<i; j++) {
				if(nums[i]>nums[j] && dp1[i]<dp1[j]+1) {
					dp1[i] = dp1[j]+1;
				}
			}
		}
		vector<int> dp2(n,1);
		for(int i=n-1; i>=0; i--) {
			for(int j=n-1; j>i; j--) {
				if(nums[i]>nums[j] && dp2[i]<dp2[j]+1) {
					dp2[i] = dp2[j]+1;
				}
			}
		}
		int maxBitonic = 0;
		for(int i=0; i<n; i++) {
			// Just confirming -> to get a peak (of mountain)
			// ->  Not just only increasing OR decreasing sequence
			if(dp1[i]>1 && dp2[i]>1) {
				int currBitonic = (dp1[i]+dp2[i]) - 1;
				maxBitonic = max(maxBitonic, currBitonic);
			}		
		}
		return maxBitonic;
	}

public:
    int minimumMountainRemovals(vector<int>& nums) {
    	int n = nums.size();
    	// Longest Bitonic Sequence
        int lbs = getLBS(n, nums);
        return (n-lbs);
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	int ans = solve.minimumMountainRemovals(nums);
	cout << ans << endl;
	return 0;
}