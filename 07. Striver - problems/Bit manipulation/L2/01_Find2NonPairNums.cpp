#include <bits/stdc++.h>
using namespace std;

// Time : O(n)
// Space : O(1)
pair<int,int> findNums(vector<int> arr) {
	pair<int,int> ans;
	int a=0, b=0, n=arr.size(), xorOfAll=0;
	for(int i=0; i<n; i++) {
		xorOfAll = xorOfAll ^ arr[i];
	}
	int x = 0;
	while((xorOfAll & 1) == 0) {
		x++;
		xorOfAll = xorOfAll >> 1;
	}
	int mask = (1 << x);
	for(int i=0; i<n; i++) {
		if((mask&arr[i]) != 0) {
			a = a^arr[i];
		}
		else {
			b = b^arr[i];
		}
	}
	ans.first = a;
	ans.second = b;
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	pair<int,int> ans = findNums(arr);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}