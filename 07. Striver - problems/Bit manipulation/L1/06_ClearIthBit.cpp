#include <bits/stdc++.h>
using namespace std;

int clearIthBit(int n, int i) {
	int mask = (1 << i); //   0 0 1 0 0 (for i = 2)
	int newMask = ~(mask); // 1 1 0 1 1
	int ans = (n & newMask); // Only 2nd bit will be erased.. else same
	return ans;
}

int main() {
	int n, i;
	cin >> n >> i;
	int ans = clearIthBit(n, i);
	cout << ans << endl;
	return 0;
}