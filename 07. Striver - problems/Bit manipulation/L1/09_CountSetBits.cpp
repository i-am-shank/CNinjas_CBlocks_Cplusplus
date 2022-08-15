#include <bits/stdc++.h>
using namespace std;

// Time : O(no. of set-bits)
int countSetBits(int n) {
	if(n == 0) { // Edge case
		return 0; // as for all, counter is +1 at end
	}
	int count = 0;
	while((n&(n-1)) != 0) {
		count++;
		n = n & (n-1); // Removing LSB 1 by 1.
	}
	return (count + 1); // As last bit was just taken off in condition
}

int main() {
	int n;
	cin >> n;
	int ans = countSetBits(n);
	cout << ans << endl;
	return 0;
}