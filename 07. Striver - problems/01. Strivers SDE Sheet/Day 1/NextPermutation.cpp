#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index1 = 0, index2 = 0;
        int n = nums.size();
        for(index1=n-2; index1>=0; index1--) {
        	if(nums[index1] < nums[index1+1]) {
        		break;
        	}
        }
        if(index1 < 0) {  // Next Permutation doesn't exists  -->  reverse the number.
        	reverse(nums.begin(), nums.end());
        }
        else {
        	for(index2=n-1; index2>index1; index2--) {
        		if(nums[index2] > nums[index1]) {
        			break;
        		}
        	}
        	int temp = nums[index1];
        	nums[index1] = nums[index2];
        	nums[index2] = temp;
        	reverse(nums.begin()+index1+1, nums.end());
        }
        return;
    }
};

int main() {
	vector<int> nums;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	Solution solve;
	solve.nextPermutation(nums);
	for(int i=0; i<n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}