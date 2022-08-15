#include <bits/stdc++.h>
using namespace std;

bool checkIfPowerOf2(int n) {
	int num = (n & (n-1)); // Last set bit removed
	return (num == 0); // If that was only set-bit -> power of 2
}

int main() {
	int n;
	cin >> n;
	bool ans = checkIfPowerOf2(n);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}