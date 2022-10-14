#include <bits/stdc++.h>
using namespace std;

// Parameterized recursion (find result in argument)
void findSum(int n, int& sum) {
	if(n == 0) {
		return;
	}
	sum += n;
	findSum(n-1, sum);
	return;
}

// Functional recursion (function returns the result)
int findSum2(int n) {
	if(n <= 1) {
		return n;
	}
	return (n + findSum2(n-1));
}

int main() {
	int n;
	cin >> n;
	int sum = 0;
	findSum(n, sum);
	int sum2 = findSum2(n);
	cout << sum << " " << sum2 << "\n";
	return 0;
}