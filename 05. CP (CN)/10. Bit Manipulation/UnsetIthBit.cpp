// Time Complexity = O(1)


#include <bits/stdc++.h>
using namespace std;

int turnOffIthBit(int n, int i) {
	int a = 1 << i;
	int b = ~a;
	int ans = (n & b);
	return ans;
}

int main() {
	int n, i;
	cin >> n >> i;
	int ans = turnOffIthBit(n, i);
	cout << ans << endl;
	return 0;
}