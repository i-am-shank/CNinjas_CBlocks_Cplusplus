#include <bits/stdc++.h>
using namespace std;

// Backtracking -> First recursion call, then process (backtrack)

void printNums_Backtrack(int n, int i) {
	if(i > n) {
		return;
	}
	printNums_Backtrack(n, i+1);
	cout << i << "\n";
	return;
}

int main() {
	int n;
	cin >> n;
	printNums_Backtrack(n, 1);
	return 0;
}