#include <bits/stdc++.h>
using namespace std;

// Tabulation  ->  A Unique approach (for LIS)
// Time : O(n^2)
// Space : O(n)
void print_lis_tab(int n, vector<int>& nums) {
	vector<int> dp(n, 1);
	vector<int> mapPrev;
	for(int i=0; i<n; i++) {
		mapPrev.push_back(i);
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(nums[j]<nums[i] && 1+dp[j]>dp[i]) {
				dp[i] = 1 + dp[j];
				mapPrev[i] = j;
			}
		}
	}
	// Backtrack  ->  to find lis (store in vector)
	vector<int> lis;
	int i = n-1;
	while(true) {
		lis.push_back(nums[i]); // Reverse order stored
		if(mapPrev[i] == i) {
			break;
		}
		i = mapPrev[i];
	}
	for(int i=lis.size()-1; i>=0; i--) {
		cout << lis[i] << " ";
	}
	cout << endl;
	return;
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
	print_lis_tab(n, nums);
	return 0;
}