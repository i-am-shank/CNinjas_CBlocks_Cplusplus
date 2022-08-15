#include <bits/stdc++.h>
using namespace std;

// Time : O(1)
// Space : O(1)
bool checkIthBit(int n, int i) {
	int num = (1 << i);
	int ans = (n & num);
	return (ans != 0);
}

int main() {
	int n, i;
	cin >> n >> i;
	bool ans = checkIthBit(n, i);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}