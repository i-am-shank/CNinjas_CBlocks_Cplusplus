// Time Complexity = O(NloglogN)
// Space Complexity = O(N)


#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
	bool sieve[n+1];
	for(int i=0; i<n+1; i++) {
		sieve[i] = true;
	}
	sieve[0] = false;
	sieve[1] = false;
	for(int i=2; i*i<n+1; i++) {
		for(int j=i*i; j<n+1; j+=i) {
			sieve[j] = false;
		}
	}
	int count = 0;
	for(int i=0; i<n+1; i++) {
		if(sieve[i] == true) {
			count++;
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	int count = countPrimes(n);
	cout << count << endl;
	return 0;
}