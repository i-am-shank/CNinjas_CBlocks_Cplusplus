// Time Complexity = O(1)


#include <bits/stdc++.h>
using namespace std;

int clearAllBits(int n, int i) {
	int x = (1 << i);
	int a = x - 1;
	int ans = (n & a);
	return ans;
}

int main() {
	int n, i;
	cin >> n >> i;
	int m = clearAllBits(n, i);
	cout << m << endl;
	return 0;
}