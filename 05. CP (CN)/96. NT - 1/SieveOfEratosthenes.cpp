// Find all Prime Numbers from 0 to n.  -->  Sieve of Eratosthenes (Best complexity)


// No. of Operations = (n/2 + n/3 + n/5 + ...)    .. (n^(1/2)) terms
// From Merter's theorem, (1/2 + 1/3 + 1/5 + ... n^(1/2) terms) = log ( log(n^(1/2)) )
// No. of Operations = n * (log ( log(n^(1/2)) ))

// Time Complexity = (n * (log(log(n))) )
// Space Complexity = O(n)


#include <bits/stdc++.h>
using namespace std;

void printSieve(int n) {
	bool *arr = new bool [n+1];
	for(int i=0; i<n+1; i++) {
		arr[i] = true;
	}
	arr[0] = false, arr[1] = false;
	for(int i=2; i*i<n+1; i++) {
		for(int j=i*i; j<n+1; j+=i) {  // i=2, loops (n/2) times.. i=3 (n/3) times.. i=x (n/x) times
			arr[j] = false;
		}
	}
	for(int i=0; i<n+1; i++) {
		if(arr[i] == true) {
			cout << i << " ";
		}
	}
	cout << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	printSieve(n);
	return 0;
}