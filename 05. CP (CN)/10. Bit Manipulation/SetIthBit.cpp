// Time Complexity = O(1)


#include <bits/stdc++.h>
using namespace std;

int turnOnIthBit(int n, int i) {
	int x = 1 << i;
	int ans = (n | x);
	return ans;
}

int main() {
	int n, i;
	cin >> n >> i;
	int ans = turnOnIthBit(n, i);
	cout << ans << endl;
	return 0;
}