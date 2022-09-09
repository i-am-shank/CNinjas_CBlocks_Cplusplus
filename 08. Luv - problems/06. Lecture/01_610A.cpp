#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n % 2 != 0) {
		cout << 0 << endl;
	}
	else { // Even .. divisible to 2 (sum of edges)
		int x = (n / 2);
		if(x % 2 == 0) {
			int ways = (x/2) - 1;
			cout << ways << endl;
		}
		else {
			int ways = (x/2);
			cout << ways << endl;
		}
	}
	return 0;
}