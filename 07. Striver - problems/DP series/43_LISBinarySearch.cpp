#include <bits/stdc++.h>
using namespace std;

int lisBinarySearch(int n, vector<int>& nums) {
	vector<int> lis;
	lis.push_back(nums[0]);
	for(int i=1; i<n; i++) {
		if(nums[i] > lis.back()) {
			lis.push_back(nums[i]);
		}
		else {
			int index = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
			lis[index] = nums[i];
		}
	}
	return lis.size();
}

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums.push_back(ele);
	}
	int ans = lisBinarySearch(n, nums);
	cout << ans << endl;
	return 0;
}