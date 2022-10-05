#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Using map (frequency-map)
	// ..& figure out starts of consecutive-sequences present.
	// ..get Lengths of them ..& maintain max. length of them
	// Time : O(n)
	// Space : O(n)
	int lcs_map(vector<int>& nums, int n) {
		unordered_map<int,int> freq;
		int maxLen=0, currLen=0;
		for(int i=0; i<n; i++) {
			freq[nums[i]]++;
		}
		for(auto it = freq.begin(); it!=freq.end(); it++) {
			int ele = it->first;
			if(freq.find(ele-1) != freq.end()) {
				// Longest-consecutive-sequence doesn't starts with (ele).
				continue;
			}
			// If reached here, means :-
			// (ele) is starting of the local-longest-consecutive sequence
			currLen = 0;
			while(freq.find(ele+currLen) != freq.end()) {
				currLen++;
			}
			maxLen = max(maxLen, currLen);
		}
		return maxLen;
	}

public:
    int longestConsecutive(vector<int>& nums) {
    	int n = nums.size();
        int ans1 = lcs_map(nums, n);
        return ans1;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	int ans = solve.longestConsecutive(nums);
	cout << ans << "\n";
	return 0;
}