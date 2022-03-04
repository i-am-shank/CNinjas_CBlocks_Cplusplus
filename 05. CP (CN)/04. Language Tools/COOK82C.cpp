#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	ll *arr = new ll[n];
	for(int i=0 ;i<n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	queue<ll> q;
	int j = 0;
	int p = n-1;
	for(int i=0; i<m; i++) {
		int curr_m;
		cin >> curr_m;
		ll ans;
		while(j < curr_m) {
			if((p >= 0)  &&  (q.empty() || arr[p] >= q.front())) {
				ans = arr[p];
				p--;
			}
			else {
				ans = q.front();
				q.pop();
			}
			q.push(ans / 2);
			j++;
		}
		cout << ans << endl;
	}
	delete []arr;
	return 0;
}