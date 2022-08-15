// Given N, print the XOR of all nos. between (1-N)

#include <bits/stdc++.h>
using namespace std;

// Time : O(1)
// Space : O(1)
int findXor_best(int n) {
	int r = (n % 4);
	if(r == 0) {
		return n;
	}
	else if(r == 1) {
		return 1;
	}
	else if(r == 2) {
		return (n+1);
	}
	else {
		return 0;
	}
}

// Time : O(1)  .. As loop runs for max. 5 times
// Space : O(1)
int findXor_better(int n) {
	int x = (n+1);
	int r = (x % 6);
	int q = (x / 6);
	int ans;
	if(q % 2 == 0) {
		ans = 0;
	}
	else {
		ans = 1;
	}
	int start = (6 * q);
	for(int i=start; i<(start+r); i++) {
		ans = (ans^i);
	}
	return ans;
}

// Brute-force approach
// Time : O(n)
int findXor(int n) {
	int ans = 0;
	for(int i=1; i<=n; i++) {
		ans ^= i;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	int ans = findXor(n);
	int ans2 = findXor_better(n);
	int ans3 = findXor_best(n);
	cout << ans << " " << ans2 << " " << ans3 << endl;
	return 0;
}