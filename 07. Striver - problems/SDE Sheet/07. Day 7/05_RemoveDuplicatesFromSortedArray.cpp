#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
    int removeDuplicates(vector<int>& nums) {
        int k=0, n=nums.size();
        for(int i=1; i<n; i++) {
        	if(nums[i] == nums[k]) {
        		continue;
        	}
        	else {
        		k++;
        		nums[k] = nums[i];
        	}
        }
        return (k+1); // As it was index
        // And we have to return unique element count
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
	int ans = solve.removeDuplicates(nums);
	cout << ans << "\n";
	for(int i=0; i<ans; i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";
	return 0;
}