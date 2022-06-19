#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0, n = nums.size();
        for(int i=0; i<n; i++) {
        	if(nums[i] == 0) {
        		count0++;
        	}
        	else if(nums[i] == 1) {
        		count1++;
        	}
        	else {
        		count2++;
        	}
        }
        for(int i=0; i<n; i++) {
        	if(i<count0) {
        		nums[i] = 0;
        	}
        	else if(i<count0+count1) {
        		nums[i] = 1;
        	}
        	else {
        		nums[i] = 2;
        	}
        }
        return;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	Solution solve;
	solve.sortColors(nums);
	for(int i=0; i<n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}