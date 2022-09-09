#include <bits/stdc++.h>
using namespace std;

int sumDigits(int n) {
	int sum = 0;
	while(n != 0) {
		int digit = (n % 10);
		sum += digit;
		n /= 10;
	}
	return sum;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans = sumDigits(n);
		cout << ans << endl;
	}
	return 0;
}