// Time Complexity = O(log N)


#include <bits/stdc++.h>
using namespace std;

int returnFirstSetBit(int n) {
	int temp = n;
	int i=0;  // Bit count
	while(n != 0) {
		if((n & 1) != 0) {
			break;
		}
		i++;
		n = n >> 1;
	}
	int m = (1 << i);
	return m;
}

int main() {
	int n;
	cin >> n;
	int m = returnFirstSetBit(n);
	cout << m << endl;
	return 0;
}