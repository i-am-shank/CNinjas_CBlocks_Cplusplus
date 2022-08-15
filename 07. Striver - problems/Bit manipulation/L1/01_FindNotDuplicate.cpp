#include <bits/stdc++.h>
using namespace std;

int findUnique(vector<int> arr) {
	int n = arr.size();
	int ans = 0;
	for(int i=0; i<n; i++) { // XOR with itself becomes 0
		ans ^= arr[i]; // So, all duplicates result to 0, on XOR operation
	}  // 0 ^ x = x  ..  So, ans will get unique no.
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int ans = findUnique(arr);
	cout << ans << endl;
	return 0;
}