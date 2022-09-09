#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			cout << (n-j) << " ";
		}
		for(int j=0; j<(2*(n-i)-1); j++) {
			cout << (n-i) << " ";
		}
		for(int j=0; j<i; j++) {
			cout << (((n-i)+1)+j) << " ";
		}
		cout << endl;
	}
	for(int i=2; i<=4; i++) {
		for(int j=0; j<n-i; j++) {
			cout << (n-j) << " ";
		}
		for(int j=0; j<((2*i)-1); j++) {
			cout << i << " ";

		}
		for(int j=0; j<n-i; j++) {
			cout << (i+j+1) << " ";
		}
		cout << endl;
	}
	return 0;
}