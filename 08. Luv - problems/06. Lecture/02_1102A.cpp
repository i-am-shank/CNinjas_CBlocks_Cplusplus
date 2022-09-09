#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x = ((n-1) / 2);
	if(x % 2 == 0) { // even
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}