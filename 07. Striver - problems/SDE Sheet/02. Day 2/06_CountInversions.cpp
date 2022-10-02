#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
	ll merge(vector<ll>& arr, ll s, ll e, ll mid) {
		ll k = (s-e) + 1;
		ll temp[e+1];
		ll i1=s, i2=mid+1;
		ll ans = 0;
		k = 0;
		while(i1<=mid && i2<=e) {
			if(arr[i1] <= arr[i2]) {
				temp[k++] = arr[i1++];
			}
			else {
				// Add up inversions
				ans += (mid - i1) + 1;
				temp[k++] = arr[i2++];
			}
		}
		while(i1 <= mid) {
			temp[k++] = arr[i1++];
		}
		while(i2 <= e) {
			temp[k++] = arr[i2++];
		}
		k=0;
		for(ll i=s; i<=e; i++) {
			arr[i] = temp[k++];
		}
		return ans;
	}

	ll count(vector<ll>& arr, ll s, ll e) {
		if(s >= e) {
			return 0;
		}
		ll mid = s + ((e-s)>>1);
		ll ans1 = count(arr, s, mid);
		ll ans2 = count(arr, mid+1, e);
		ll ans = merge(arr, s, e, mid);
		return (ans1 + ans2 + ans);
	}

public:
	ll inversionCount(vector<ll>& arr, ll n) {
        ll s=0, e=n-1;
        ll ans = count(arr, s, e);
        return ans;
    }
};

int main() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for(ll i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	ll ans = solve.inversionCount(arr, n);
	cout << ans << "\n";
	return 0;
}