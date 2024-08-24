#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<ll> &arr, ll n, ll x) {
    	int ans = -1;
    	int s=0, e=(n-1);
    	while(s <= e) {
    		ll mid = (s + ((e-s)>>1));
    		if(arr[mid] == x) {
    			return mid;
    		}
    		else if(arr[mid] > x) {
    			// search a smaller no.
    			e = (mid-1);
    		}
    		else {
    			ans = mid;
    			// search a larger no. if exists
    			s = (mid+1);
    		}
    	}
    	return ans;
    }
};

int main() {
	ll n, x;
	cin >> n >> x;
	vector<ll> arr(n);
	for(ll i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	int ans = solve.findFloor(arr, n, x);
	cout << ans << "\n";
	return 0;
}