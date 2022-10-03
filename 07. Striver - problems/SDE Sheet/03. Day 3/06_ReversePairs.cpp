#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
	// Time : O(nlogn) .. merge-sort technique
	// Similar to count-inversions .. count-reverse pairs
	// Space : O(n) .. temp array
	int merge(vector<int>& nums, int start, int mid, int end) {
		int ans = 0, k=0;
		int temp[(end-start)+1];
		int i1=start, i2=mid+1;
		int i3=start, i4=mid+1;
		while(i3<=mid && i4<=end) {
			if((ll)nums[i3] > (ll)(2*(ll)nums[i4])) {
				ans += ((mid-i3)+1); // Counting reverse-pairs
				// Next values of i3 (greater) will also fulfill this
				// .. on comparison with this value of i4.. those many reverse-pairs
				i4++; // Compare for next i4 now.
			}
			else {
				i3++;
			}
		}
		while(i1<=mid && i2<=end) {
			if(nums[i1] <= nums[i2]) {
				temp[k++] = nums[i1++];
			}
			else {
				temp[k++] = nums[i2++];
			}
		}
		while(i1 <= mid) {
			temp[k++] = nums[i1++];
		}
		while(i2 <= end) {
			temp[k++] = nums[i2++];
		}
		k = 0;
		for(int i=start; i<=end; i++) {
			nums[i] = temp[k++];
		}
		return ans;
	}

	int countReverse(vector<int>& nums, int start, int end) {
		if(start >= end) {
			return 0;
		}
		int mid = start + ((end-start) >> 1);
		int ans1 = countReverse(nums, start, mid);
		int ans2 = countReverse(nums, mid+1, end);
		int ans3 = merge(nums, start, mid, end);
		return (ans1 + ans2 + ans3);
	}

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = countReverse(nums, 0, n-1);
        return ans;
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
	int ans = solve.reversePairs(nums);
	cout << ans << "\n";
	return 0;
}