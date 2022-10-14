#include <bits/stdc++.h>
using namespace std;

// Count :-
// 0 1 2 3 4 5 6 7 ..
// Fibonacci series :-
// 0 1 1 2 3 5 8 13 ..

// Time : O(2^n)
// Space : O(n) .. Auxiliary recursion stack space
int fib(int n) {
	if(n <= 1) { // Base case for 0 & 1 .. works for (n-1) & (n-2)
		return n;
	}
	return (fib(n-1) + fib(n-2));
}

int main() {
	int n;
	cin >> n;
	int ans = fib(n);
	cout << ans << "\n";
	return 0;
}