#include <bits/stdc++.h>
using namespace std;

// Returning 1 .. if condition satisfied

int countSumK(vector<int>& arr, int n, int k, vector<int>& ans) {
	if(k == 0) {
		return 1; // condition satisfied
	}
	if(n < 0) {
		return 0;
	}
	int ans1 = countSumK(arr, n-1, k, ans);
	int ans2 = 0;
	if(arr[n] <= k) {
		ans.push_back(arr[n]);
		ans2 = countSumK(arr, n-1, k-arr[n], ans);
		ans.pop_back();
	}
	return (ans1 + ans2); // None returned true
}

void printSubsequences(vector<int>& arr, int n, int k) {
	vector<int> ans;
	int count = countSumK(arr, n-1, k, ans);
	cout << count << "\n";
	return;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	printSubsequences(arr, n, k);
	return 0;
}