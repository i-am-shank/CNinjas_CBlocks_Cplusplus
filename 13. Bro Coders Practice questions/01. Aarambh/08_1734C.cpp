#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		unordered_map<int,int> mp;
		vector<int> nums;
		for(int i=0; i<n; i++) {
			if(s[i] == '0') {
				// cout << (i+1) << " ";
				mp[i+1] = 1; // 1-indexing
				nums.push_back(i+1);
			}
		}
		// cout << "\n";
		ll cost = 0;
		for(auto it: nums) {
			int x = it;
			bool done = false;
			// cout << x << " - ";
			for(int i=x; i<=n; i+=x) {
				if(done==true && (mp.find(i)==mp.end() || mp[i]==0)) {
					// Break in multiple count of it
					break;
				}
				else {
					if(mp[i] > 0) {
						done = true;
						// cout << i << " ";
						cost += (ll)x;
						mp[i]=0;
					}
				}
			}
			// cout << "\n";
		}
		cout << cost << "\n";
	}
	return 0;
}