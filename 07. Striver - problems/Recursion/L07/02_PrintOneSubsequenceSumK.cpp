#include <bits/stdc++.h>
using namespace std;

// Returning bool.. if condition satisfied
// ..No further recursion calls.. after returning true
// ..Will print only one subsequence.
bool printSumK(vector<int>& arr, int n, int k, vector<int>& ans) {
	if(k == 0) {
		reverse(ans.begin(), ans.end());
		// As elements pushed in reversed way (n-1) to 0
		for(int i=0; i<ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return true; // condition satisfied
	}
	if(n < 0) {
		return false;
	}
	bool ans1 = printSumK(arr, n-1, k, ans);
	if(ans1 == true) {
		return true; // No further recursion calls
	}
	if(arr[n] <= k) {
		ans.push_back(arr[n]);
		bool ans2 = printSumK(arr, n-1, k-arr[n], ans);
		ans.pop_back();
		if(ans2 == true) {
			return true;
		}
	}
	return false; // None returned true
}

void printSubsequences(vector<int>& arr, int n, int k) {
	vector<int> ans;
	bool flag = printSumK(arr, n-1, k, ans);
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