#include <bits/stdc++.h>
using namespace std;

#define ll long long

int findLargestMinDistance(vector<int> &boards, int k) {
    ll n = boards.size();
    ll maxEle=INT_MIN, sum=0;
    for(ll i=0; i<n; i++) {
    	sum += (ll)boards[i];
    	maxEle = max(maxEle, (ll)boards[i]);
    }
    ll s=maxEle, e=sum;
    ll ans = sum;
    while(s <= e) {
    	ll mid = (s + ((e-s)>>1));
    	// check if (mid) is a possible largest time
    	ll curr=0, count=1;
    	for(ll i=0; i<n; i++) {
    		curr += (ll)boards[i];
    		if(curr > mid) {
    			count++;
    			curr = (ll)boards[i];
    		}
    	}
    	if(count <= k) {
    		// anytime, within this upper limit,
    		// k painters will do it
    		ans = mid;
    		// search for a smaller max. time
    		e = (mid-1);
    	}
    	else {
    		s = (mid+1);
    	}
    }
    return (int)ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> boards(n);
	for(int i=0; i<n; i++) {
		cin >> boards[i];
	}
	int ans = findLargestMinDistance(boards, k);
	cout << ans << "\n";
	return 0;
}