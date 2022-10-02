#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(1)
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = n-2;
        while(idx >= 0) {
        	if(nums[idx] < nums[idx+1]) {
        		break;
        	}
        	idx--;
        }
        // idx -> index at which digit at just smaller-unit is larger
        // .. next permutation -> swap (idx) & (n-1) .. reverse (idx+1) to (n-1)
        if(idx < 0) {
        	reverse(nums.begin(), nums.end());
        	return;
        }
        int idx2 = n-1;
        // Finding least-significant digit .. greater than curr. digit
        while(nums[idx2] <= nums[idx]) {
        	idx2--;
        }
        int temp = nums[idx];
        nums[idx] = nums[idx2];
        nums[idx2] = temp;
        reverse(nums.begin()+(idx+1), nums.end());
        return;
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
	solve.nextPermutation(nums);
	for(int i=0; i<n; i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";
	return 0;
}