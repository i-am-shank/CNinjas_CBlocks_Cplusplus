#include <bits/stdc++.h>
using namespace std;

int clearAllBitsLSB(int n, int i) {
	int a = 1 << (i+1);  //  2 ^ (i+1)
	int b = a - 1;
	int c = ~b;
	int ans = n & c;
	return ans;
}

int main() {
	int n, i;
	cin >> n >> i;
	int ans = clearAllBitsLSB(n, i);
	cout << ans << endl;
	return 0;
}