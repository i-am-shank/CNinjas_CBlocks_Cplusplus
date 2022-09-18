#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SGTree{
	vector<ll> seg;

	void buildSGTree(ll idx, ll low, ll high, vector<ll>& arr, int level, int n) {
		if(low == high) {
			seg[idx] = arr[low];
			return;
		}
		ll mid = low + ((high-low)>>1);
		buildSGTree((2*idx)+1, low, mid, arr, level+1, n);
		buildSGTree((2*idx)+2, mid+1, high, arr, level+1, n);
		if((n-level)%2 == 0) {
			// Do XOR .. at start .. level=0 (for even n)
			seg[idx] = seg[(2*idx)+1] ^ seg[(2*idx)+2];
		}
		else {
			// Do OR
			seg[idx] = seg[(2*idx)+1] | seg[(2*idx)+2];
		}
		return;
	}

public:
	SGTree(ll n, vector<ll>& arr, int totalLevel) {
		seg = vector<ll>((4*n)+1, LONG_LONG_MAX);
		buildSGTree(0, 0, n-1, arr, 0, totalLevel);
	}

	ll query(ll idx, ll low, ll high, ll l, ll r, int level, int n) {
		if(l>high || r<low) {
			// No overlap
			return 0; // OR with 0 .. no change
			// XOR with 0 .. no change
		}
		else if(l>=low && r<=high) {
			return seg[idx];
		}
		else {
			ll mid = low + ((high-low)>>1);
			ll left = query((2*idx)+1, low, mid, l, r, level+1, n);
			ll right = query((2*idx)+2, mid+1, high, l, r, level+1, n);
			if((n-level)%2 == 0) {
				// Do XOR
				return (seg[(2*idx)+1] ^ seg[(2*idx)+2]);
			}
			else {
				// Do OR
				return (seg[(2*idx)+1] | seg[(2*idx)+2]);
			}
		}
	}

	void update(ll idx, ll low, ll high, ll i, ll val, int level, int n) {
		if(low == high) {
			seg[idx] = val;
			return;
		}
		ll mid = low + ((high-low) >> 1);
		if(i <= mid) {
			update((2*idx)+1, low, mid, i, val, level+1, n);
		}
		else {
			update((2*idx)+2, mid+1, high, i, val, level+1, n);
		}
		if((n-level)%2 == 0) {
			// Do XOR
			seg[idx] = seg[(2*idx)+1] ^ seg[(2*idx)+2];
		}
		else {
			// Do OR
			seg[idx] = seg[(2*idx)+1] | seg[(2*idx)+2];
		}
		return;
	}
};

int main() {
	ll n, m;
	cin >> n >> m;
	ll count = pow(2,n);
	vector<ll> a(count);
	for(ll i=0; i<count; i++) {
		cin >> a[i];
	}
	SGTree sg(count, a, n);
	while(m--) {
		ll pi, bi;
		cin >> pi >> bi;
		pi--;
		// a[pi] = bi; --> 1-indexing to 0-indexing
		// Then provide updated v
		sg.update(0, 0, count-1, pi, bi, 0, n);
		ll ans = sg.query(0, 0, count-1, 0, count-1, 0, n);
		cout << ans << endl;
	}
	return 0;
}