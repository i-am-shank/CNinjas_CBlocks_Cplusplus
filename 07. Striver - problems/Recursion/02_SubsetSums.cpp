#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getSums(vector<int>& arr, int n, int sum, vector<int>& sums) {
		if(n < 0) {
			sums.push_back(sum);
			return;
		}
		getSums(arr, n-1, sum, sums);
		getSums(arr, n-1, sum+arr[n], sums);
		return;
	}

public:
	vector<int> subsetSums(vector<int> arr, int n) {
		vector<int> sums;
		getSums(arr, n-1, 0, sums);
		return sums;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	vector<int> ans = solve.subsetSums(arr, n);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}