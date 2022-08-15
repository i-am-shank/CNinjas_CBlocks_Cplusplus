#include <bits/stdc++.h>
using namespace std;

int setIthBit(int n, int i) {
	int mask = (1 << i);
	int ans = (n | mask);
	return ans;
}

int main() {
	int n, i;
	cin >> n >> i;
	int ans = setIthBit(n, i);
	cout << ans << endl;
	return 0;
}