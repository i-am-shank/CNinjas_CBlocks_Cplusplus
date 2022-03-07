#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		pair<int, int>* input = new pair<int, int> [n];
		for(int i=0; i<n; i++) {
			cin >> input[i].first >> input[i].second;
		}
		sort(input, input+n);
		for(int i=0; i<m; i++) {
			int p;
			cin >> p;
			int position = lower_bound(input, input+n, make_pair(p, 0)) - input;
			if(position == 0) {    //  Current time matches with 0th position
				int ans = (input[position].first - p);
				cout << ans << endl;
			}
			else {  // Other condition .. General
				int ans = -1;
				if(input[position-1].second > p) {    // Checking previous interval .. for no wait
					ans = 0;
				}
				else if(position < n) {
					ans = input[position].first - p;
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}