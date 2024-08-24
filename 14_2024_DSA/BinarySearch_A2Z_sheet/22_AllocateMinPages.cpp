#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // Function to find minimum number of pages.
    ll findPages(int n, int arr[], int m) {
    	if(m > n) {
    		return -1;
    		// not possible to allocate atleast 1 book
    	}
        ll s=arr[0], e;
        ll sum = 0;
        for(int i=0; i<n; i++) {
        	sum += (ll)arr[i];
        	s = max(s, (ll)arr[i]);
        }
        e = sum;
        ll ans = e;
        while(s <= e) {
        	ll mid = (s + ((e-s)>>1));
        	// check if this can be a possible maximum
        	ll count=1, curr=0;
        	for(ll i=0; i<n; i++) {
        		curr += (ll)arr[i];
        		if(curr > mid) {
        			curr = (ll)arr[i];
        			count++;
        		}
        	}
        	// cout<<mid<<" "<<count<<"\n";
        	if(count <= m) {
        		// managed to distribute lesser students with that maximum
        		// always possible to allocate (m)-students with a lesser max.
        		ans = mid;
        		// find a smaller max. book
        		e = (mid-1);
        	}
        	else {
        		// go with a larger max. value
        		// to manage <= m students
        		// .. anyway possible to do in m-students (in such cases)
        		s = (mid+1);
        	}
        }
        return ans;
    }
};

/*
7 5
15 10 19 10 5 18 7
--> 20  (correct : 25)
*/

int main() {
	int n, m;
	cin >> n >> m;
	int arr[100000];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	ll ans = solve.findPages(n, arr, m);
	cout << ans << "\n";
	return 0;
}