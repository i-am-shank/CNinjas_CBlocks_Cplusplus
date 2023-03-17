#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		// (a^b) + (b^c) + (c^a) = n
		// Now,  (a^b)  =  a+b + 2(a & b)
		// 2(a+b+c) + 2((a&b) + (b&c) + (c&a)) = n
		// (a+b+c) + (a&b) + (b&c) + (c&a)  =  (n/2)
		// As LHS is integer, RHS should be integer
		// ===>  n is even, then only possible.

		// Back to original statement :-
		// Assume a = b,
		// (a^b) + (b^c) + (c^a) = n
		// 0 + (a^c) + (c^a) = n
		// 2(a^c) = n
		// (a^c) = (n/2)
		// Assume value of a,  c  =  ((n/2) ^ a).
		if(n % 2 == 0) {
			ll c = (n/2) ^ 1; // assuming, a=b=1.
			cout<<1<<" "<<1<<" "<<c<<"\n";
		}
		else { // If n isn't even, answer not possible
			cout << -1 << "\n";
		}
	}
	return 0;
}