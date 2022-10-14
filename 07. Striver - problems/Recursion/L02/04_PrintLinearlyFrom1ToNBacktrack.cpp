#include <bits/stdc++.h>
using namespace std;

// Backtrack --> Preorder recursion call
// .. First recursion call, then do processing

void printNums_Backtrack(int n) {
	if(n == 0) {
		return;
	}
	printNums_Backtrack(n-1);
	cout << n << "\n";
	return;
}

int main() {
	int n;
	cin >> n;
	printNums_Backtrack(n);
	return 0;
}