#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

int gcd(int a, int b) {
	if(a == 0) {
		return b;
	}
	return gcd(b%a, a);
}

int main() {
	int t;
	cin >> t;
	// 1 <= a[i] <= 1000
	vector<pp> coprimes;
	for(int i=1; i<=1000; i++) {
		for(int j=1; j<=1000; j++) {
			int curr = gcd(i, j);
			if(curr == 1) {
				// coprime .. gcd = 1
				coprimes.push_back(mp(i,j));
			}
		}
	}
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		unordered_map<int,int> indexMap;
		for(int i=0; i<n; i++) {
			cin >> a[i];
			indexMap[a[i]] = i+1; // 1-indexing
			// Store max. index (last occurence)
			// as max. sum is required
		}
		int count = 0;
		int maxSum = -1; // If no i,j exists
		for(auto it: coprimes) {
			int f=it.fi, s=it.se;
			if(indexMap.find(f) != indexMap.end()) {
				if(indexMap.find(s) != indexMap.end()) {
					// Both f & s are present
					int currSum = (indexMap[f] + indexMap[s]);
					maxSum = max(maxSum, currSum);
				}
			}
		}
		cout << maxSum << "\n";
	}
}