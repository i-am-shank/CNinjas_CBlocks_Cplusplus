// Time Complexity = O(log N)


#include <bits/stdc++.h>
using namespace std;

int findFirstSetBit(int n) {
	int temp = n;
	int i = 0;  // Bit count
	while(temp != 0) {
		if((temp & 1) != 0) {
			break;
		}
		i++;
		temp = temp >> 1;
	}
	int m = (1 << i);
	return m;
}

int turnOffFirstSetBit(int n) {
	int x = findFirstSetBit(n);
	int b = ~x;
	return (n & b);
}

int main() {
	int n;
	cin >> n;
	int m = turnOffFirstSetBit(n);
	cout << m << endl;
	return 0;
}