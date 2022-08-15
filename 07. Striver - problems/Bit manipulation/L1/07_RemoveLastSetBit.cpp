#include <bits/stdc++.h>
using namespace std;

int removeLastSetBit(int n) {
	// 1 1 0 1 1 0 0  (suppose a possible n)
	// 1 1 0 1 0 1 1  (then, n-1 will be this..)
	int ans = (n & (n-1));
	return ans;
}

int main() {
	int n;
	cin >> n;
	int ans = removeLastSetBit(n);
	cout << ans << endl;
	return 0;
}