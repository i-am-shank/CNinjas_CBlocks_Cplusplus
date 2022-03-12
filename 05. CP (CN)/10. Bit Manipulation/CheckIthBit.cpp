#include <bits/stdc++.h>
using namespace std;

void checkIth(int n, int i) {
	int x = pow(2, i);  //  pow function is O(log N)
	int xb = 1 << i;  //  Using left shift operator .. for calculating 2 ^ i.
	int z = n & xb;
	if(z == 0) {  //  Doing & with only ith bit set as 1 .. if ith = 1 returns non-zero
		cout << "False" << endl;
	}
	else {
		cout << "True" << endl;
	}
	return;
}

int main() {
	int n, i;
	cin >> n >> i;
	checkIth(n, i);
	return 0;
}