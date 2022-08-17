#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isSetBit(ll mask, ll j) {
	ll getMask = (1 << j);
	if((mask & getMask) == 0) {
		return false;
	}
	return true;
}

bool isZeroPossible(vector<ll> arr) {
	// Creating Power set .. of all clock-anticlock possibilities
	ll n = arr.size();
	ll possibilities = (1 << n);
	for(ll i=1; i<=possibilities; i++) {
		ll mask = i;
		ll clock=0, anticlock=0;
		for(ll j=0; j<n; j++) {
			if(isSetBit(mask, j)) {
				clock += arr[j];
			}
			else {
				anticlock += arr[j];
			}
		}
		if((abs(clock-anticlock) % 360) == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	bool ans = isZeroPossible(arr);
	cout << (ans==true ? "YES" : "NO") << endl;
	return 0;
}