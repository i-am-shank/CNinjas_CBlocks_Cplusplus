#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll floorSqrt(ll n) {
        ll s=0, e=n;
        ll ans = n;
        while(s <= e) {
        	ll mid = (s + ((e-s)>>1));
        	if((mid*mid) == n) {
        		return mid;
        	}
        	else if((mid*mid) < n) {
        		ans = mid;
        		s = (mid+1);
        	}
        	else {
        		e = (mid-1);
        	}
        }
        return ans;
    }
};

int main() {
	ll n;
	cin >> n;
	Solution solve;
	ll ans = solve.floorSqrt(n);
	cout << ans << "\n";
	return 0;
}