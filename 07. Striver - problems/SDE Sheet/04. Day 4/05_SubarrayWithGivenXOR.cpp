#include <bits/stdc++.h>
using namespace std;

int count(vector<int>& arr, int target) {
	int curr = 0; // As (x ^ 0) = x  ..  so begin with 0.
	unordered_map<int,int> XorCount; // Count previous achieved XORs
	// If (a ^ b = target)  -->  (b ^ target = a ^ b ^ b = a)
	// Using this property.. we check (count of XORs with target)
	// .. Similar to what is done in Pair-sum
	int n = arr.size(), ans = 0;
	for(int i=0; i<n; i++) {
		curr = (curr ^ arr[i]);
		if(curr == target) {
			// Starting from 1st element.. subarray till here, Xor = target
			ans++; // 1-subarray added
		}
		if(XorCount.find(curr^target) != XorCount.end()) {
			ans += XorCount[(curr^target)];
		}
		XorCount[curr]++;
	}
	return ans;
}

int main() {
	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int ans = count(arr, target);
	cout << ans << "\n";
	return 0;
}