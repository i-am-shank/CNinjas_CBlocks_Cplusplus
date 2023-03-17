#include <bits/stdc++.h>
using namespace std;

class Solution {
	int gcd(int a, int b) {
		if(a == 0) {
			return b;
		}
		return gcd(b%a, a);
	}

public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++) {
        	int curr = nums[i];
        	if(curr == k) {
        		count++;
        	}
        	for(int j=i+1; j<n; j++) {
        		curr = gcd(curr, nums[j]);
        		if(curr == k) {
        			count++;
        		}
        	}
        }
        return count;
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
	int ans = solve.subarrayGCD(nums, k);
	cout << ans << "\n";
	return 0;
}