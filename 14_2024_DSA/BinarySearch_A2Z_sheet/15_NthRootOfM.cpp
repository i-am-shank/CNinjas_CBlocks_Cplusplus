#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution{
	ll nRoot(ll a, ll b) {
		ll s=0, e=a;
		while(s <= e) {
			ll mid = (s + ((e-s)>>1));
			ll curr = 1;
			for(ll i=0; i<b; i++) {
				curr *= mid;
				if(curr > a) {
					break;
				}
			}
			if(curr == a) {
				return mid;
			}
			else if(curr > a) {
				// find a smaller no.
				e = (mid-1);
			}
			else {
				s = (mid+1);
			}
		}
		return -1; // no integer value found
	}

public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    ll a = (ll)m, b = (ll)n;
	    ll ans = nRoot(a, b);
	    return (int)ans;
	}  
};

int main() {
	int n, m;
	cin >> n >> m;
	Solution solve;
	int ans = solve.NthRoot(n, m);
	cout << ans << "\n";
	return 0;
}