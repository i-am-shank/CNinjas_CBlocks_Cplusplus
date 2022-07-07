#include <bits/stdc++.h>
using namespace std;

class Solution {
	// The same logic as Longest Increasing subsequence
	//   =>  Just sort the array -> In increasing order
	//   =>  Divisibility condition (instead of increasing condition)

	vector<int> lds(int n, vector<int> nums) {
		vector<int> dp(n, 1);
		vector<int> mapPrev;
		sort(nums.begin(), nums.end());
		for(int i=0; i<n; i++) {
			mapPrev.push_back(i);
		}
		int lastIndex = 0, maxV = 1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<i; j++) {
				// Divisibility condition
				if((nums[i]%nums[j]==0) && (1+dp[j]>dp[i])) {
					dp[i] = 1 + dp[j];
					mapPrev[i] = j;
				}
			}
			if(dp[i] > maxV) {
				maxV = dp[i];
				lastIndex = i;
			}
		}
		// Backtrack  ->  to find lis (store in vector)
		vector<int> lis;
		lis.push_back(nums[lastIndex]);
		while(mapPrev[lastIndex] != lastIndex) {
			lastIndex = mapPrev[lastIndex];
			lis.push_back(nums[lastIndex]); // Reverse order stored
		}
		reverse(lis.begin(), lis.end());
		return lis;
	}

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = lds(n, nums);
        return ans;
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
	vector<int> ans = solve.largestDivisibleSubset(nums);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}