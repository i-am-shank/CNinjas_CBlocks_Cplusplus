#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		ll sum = 0;
		map<ll,ll> freq;
		for(ll i=0; i<n; i++) {
			cin >> a[i];
			sum += a[i];
			freq[a[i]]++;
		}
		if((2*sum) % n != 0) {
			// Required sum isn't integer
			cout << 0 << "\n";
		}
		else {
			ll target = ((2*sum) / n);
			ll count = 0;
			for(ll i=0; i<n; i++) {
				ll n1 = a[i];
				ll n2 = (target-n1);
				ll f1 = freq[n1];
				if(freq.find(n2) != freq.end()) {
					if(n1 == n2) {
						ll f = freq[n1];
						count += (f * (f-1)) / 2;
						freq[n1] = 0; // Avoid repetition
						// As n1 won't pair with any other no.
					}
					else {
						ll f1=freq[n1], f2=freq[n2];
						count += (f1 * f2);
						freq[n1] = 0; // Avoid 2x cound
						// For f-->s , s-->f
					}
				}
			}
			cout << count << "\n";
		}
	}
	return 0;
}