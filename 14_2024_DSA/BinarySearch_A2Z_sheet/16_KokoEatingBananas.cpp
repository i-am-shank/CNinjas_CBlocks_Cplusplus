#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll n = piles.size();
        vector<ll> prefix(n, 0);
        ll sum = 0;
        for(ll i=0; i<n; i++) {
        	sum += (ll)piles[i];
        	prefix[i] = sum;
        }
        ll s=1, e=sum;
        ll ans = e;
        while(s <= e) {
        	ll mid = (s + ((e-s)>>1));
        	// check if eating (mid) bananas can finish all in h hours
        	ll time = 0;
        	for(ll i=0; i<n; i++) {
        		time += (piles[i] / mid);
        		if((piles[i] % mid)  !=  0) {
        			// some bananas < mid is remaining
        			time++;
        		}
        	}
        	if(time <= h) {
        		ans = min(ans, mid);
        		// search for a smaller
        		e = (mid-1);
        	}
        	else {
        		s = (mid+1);
        	}
        }
        return (int)ans;
    }
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, h;
	cin >> n >> h;
	vector<int> piles(n);
	for(int i=0; i<n; i++) {
		cin >> piles[i];
	}
	Solution solve;
	int ans = solve.minEatingSpeed(piles, h);
	cout << ans << "\n";
	return 0;
}