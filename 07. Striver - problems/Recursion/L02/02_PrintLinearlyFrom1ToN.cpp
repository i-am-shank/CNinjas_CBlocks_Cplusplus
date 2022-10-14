#include <bits/stdc++.h>
using namespace std;

void printNums(int n, int i) {
	if(i > n) {
		return; // (n+1).. won't be printed
	}
	cout << i << "\n";
	printNums(n, i+1);
	return;
}

int main() {
	int n;
	cin >> n;
	printNums(n, 1);
	return 0;
}