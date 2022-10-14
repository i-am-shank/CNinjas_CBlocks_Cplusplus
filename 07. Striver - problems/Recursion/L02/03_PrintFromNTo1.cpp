#include <bits/stdc++.h>
using namespace std;

void printNums(int n) {
	if(n == 0) {
		return;
	}
	cout << n << "\n";
	printNums(n-1);
	return;
}

int main() {
	int n;
	cin >> n;
	printNums(n);
	return 0;
}