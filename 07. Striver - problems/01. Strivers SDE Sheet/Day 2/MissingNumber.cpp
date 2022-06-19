#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        int* arr = new int[n+1];
        for(int i=0; i<n+1; i++) {
        	arr[i] = 0;
        }
        for(int i=0; i<n; i++) {
        	arr[nums[i]] ++;
        }
        for(int i=0; i<n+1; i++) {
        	if(arr[i] == 0) {
        		ans = i;
        		break;
        	}
        }
        delete []arr;
        return ans;
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
	int ans = solve.missingNumber(nums);
	cout << ans << endl;
	return 0;
}