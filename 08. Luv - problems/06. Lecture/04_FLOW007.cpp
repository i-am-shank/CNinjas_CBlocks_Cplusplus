#include <bits/stdc++.h>
using namespace std;

int reverseNum(int n) {
	int ans = 0;
	while(n != 0) {
		int digit = (n % 10);
		ans = (ans * 10) + digit;
		n /= 10;
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans = reverseNum(n);
		cout << ans << endl;
	}
	return 0;
}