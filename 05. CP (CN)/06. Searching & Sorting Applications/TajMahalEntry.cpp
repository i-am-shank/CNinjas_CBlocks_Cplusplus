#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll;

int entryWindow(ll* people, int n) {
	ll minV = INT_MAX;
	for(int i=0; i<n; i++) {
		if(minV > people[i]) {
			minV = people[i];
		}
	}
	ll x = (minV / n);
	for(int i=0; i<n; i++) {
		people[i] -= (x * n);
	}
	int ans = -1;
	for(int i=0; i<n; i++) {
		if(people[i] <= i) {
			ans = i;
			break;
		}
	}
	if(ans == -1) {
		for(int i=0; i<n; i++) {
			if(people[i] <= (n+i)) {
				ans = i;
				break;
			}
		}
	}
	return (ans+1);
}

int main() {
	int n;
	cin >> n;
	ll* input = new ll[n];
	for(int i=0; i<n; i++) {
		cin >> input[i];
	}
	int ans = entryWindow(input, n);
	cout << ans << endl;
	delete []input;
	return 0;
}