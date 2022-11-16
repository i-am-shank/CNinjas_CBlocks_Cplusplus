#include <bits/stdc++.h>
using namespace std;

#define ll long

ll getMinimumMoves(int n, int* quantity) {
	ll sum = 0;
	for(ll i=0; i<n; i++) {
		sum += quantity[i];
	}
	ll sum1 = 0, minDiff=LONG_MAX;
	for(ll i=0; i<n-1; i++) {
		sum1 += quantity[i];
		ll sum2 = sum-sum1;
		ll diff = abs(sum - sum2);
		minDiff = min(minDiff, diff);
	}
	return minDiff;
}

int main() {
	int n;
	cin >> n;
	vector<int> quantity(n);
	for(int i=0; i<n; i++) {
		cin >> quantity[i];
	}
	ll ans = getMinimumMoves(n, quantity);
	cout << ans << "\n";
	return 0;
}