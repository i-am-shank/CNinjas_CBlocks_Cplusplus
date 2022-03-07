// Time Complexity = O(N logD)    ..  as D is larger than N
//        ..  D = Difference between maximum & minimum element of input array.
// Space Complexity = O(N)


#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll largestMinDistance(vector<ll> input, int n, int c) {
	ll start = 0, end = input[n-1]-input[0];
	ll ans = -1;
	while(start <= end) {
		ll mid = start + ((end - start) / 2);
		// Check if  .. mid ..  distance is possible or not.
		int count = 1, prev = 0;
		for(int i=1; i<n; i++) {
			if(input[i] - input[prev] >= mid) {
				count++;
				prev = i;
			}
			if(count == c) {
				break;
			}
		}
		if(count < c) {
			end = mid-1;
		}
		else {
			ans = mid;
			start = mid+1;
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, c;
		cin >> n >> c;
		vector<ll> input;
		for(int i=0; i<n; i++) {
			ll ele;
			cin >> ele;
			input.push_back(ele);
		}
		sort(input.begin(), input.end());    //  O(N logN)
		ll ans = largestMinDistance(input, n, c);    //  O(N logD)
		cout << ans << endl;
	}
	return 0;
}