#include <bits/stdc++.h>
using namespace std;

void printSumK(vector<int>& arr, int n, int k, vector<int>& ans) {
	if(k == 0) {
		reverse(ans.begin(), ans.end());
		// As elements pushed in reversed way (n-1) to 0
		for(int i=0; i<ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	if(n < 0) {
		return;
	}
	printSumK(arr, n-1, k, ans);
	if(arr[n] <= k) {
		ans.push_back(arr[n]);
		printSumK(arr, n-1, k-arr[n], ans);
		ans.pop_back();
	}
	return;
}

void printSubsequences(vector<int>& arr, int n, int k) {
	vector<int> ans;
	printSumK(arr, n-1, k, ans);
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