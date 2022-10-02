#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Space : O(1)
    void sortColors(vector<int>& nums) {
        int c0=0, c1=0, c2=0, n=nums.size();
        for(int i=0; i<n; i++) {
        	c0 += (nums[i] == 0);
        	c1 += (nums[i] == 1);
        	c2 += (nums[i] == 2);
        }
        for(int i=0; i<n; i++) {
        	if(c0 > 0) {
        		nums[i] = 0;
        		c0--;
        	}
        	else if(c1 > 0) {
        		nums[i] = 1;
        		c1--;
        	}
        	else if(c2 > 0) {
        		nums[i] = 2;
        		c2--;
        	}
        }
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
	solve.sortColors(nums);
	for(int i=0; i<n; i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";
	return 0;
}