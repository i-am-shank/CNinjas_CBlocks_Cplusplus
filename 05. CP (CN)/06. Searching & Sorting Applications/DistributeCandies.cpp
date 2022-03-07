#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

typedef long long ll;

ll minCandles(vector<ll> input, int k) {
	int n = input.size();
	ll start = 0, end = input[n-1];
	ll ans = 0;
	while(start <= end) {
		int mid = (start + end) / 2;
		int temp = 0;
		for(int i=0; i<n; i++) {
			temp += input[i] / mid;
		}
		if(temp >= k) {
			ans = mid;
			start = mid+1;
		}
		else {
			end = mid-1;
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<ll> input;
		for(int i=0; i<n; i++) {
			ll ele;
			cin >> ele;
			input.push_back(ele);
		}
		sort(input.begin(), input.end());
		ll ans = minCandles(input, k);
		cout << ans << endl;
	}
	return 0;
}