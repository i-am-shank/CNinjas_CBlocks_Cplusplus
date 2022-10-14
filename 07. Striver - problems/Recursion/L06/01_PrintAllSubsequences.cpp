#include <bits/stdc++.h>
using namespace std;

// Subsequence -> take, notTake (similar pattern for most problems)

// Time : O(2^n)
// Space : O(n) .. Recursion stack
void printAllSubsequences(vector<int>& arr, int n, int idx, vector<int> num) {
	if(idx == n) {
		// Print the num-array
		for(int i=0; i<num.size(); i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}
	// not-take
	printAllSubsequences(arr, n, idx+1, num);
	// take
	num.push_back(arr[idx]);
	printAllSubsequences(arr, n, idx+1, num);
	num.pop_back();
	return;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	vector<int> num;
	printAllSubsequences(arr, n, 0, num);
	return 0;
}