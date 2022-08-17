#include <bits/stdc++.h>
using namespace std;

int xorOfXors_best(vector<int> arr) {
	// Each element will appear for even no. of times
	// take .. notTake  (at each element)
	return 0; // Always !!
}

int xorOfXors(vector<int> arr) {
	int n = arr.size();
	int xorAll = 0;
	for(int i=0; i<n; i++) {
		xorAll = xorAll ^ arr[i];
	}
	int count = pow(2,n-1), totalXor=0;
	for(int i=0; i<count; i++) {
		totalXor = totalXor ^ xorAll;
	}
	return totalXor;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int ans = xorOfXors(arr);
	int ans2 = xorOfXors_best(arr);
	cout << ans << " " << ans2 << endl;
	return 0;
}