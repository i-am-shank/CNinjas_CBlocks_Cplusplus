#include <bits/stdc++.h>
using namespace std;

// Dividing array into segments.. calling recursion
// Storing Binary tree as array.. (0 or 1-indexing)



int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int s, e;
		cin >> s >> e;
		int ans = minRange(arr, s, e, n);
		cout << ans << endl;
	}
	return 0;
}