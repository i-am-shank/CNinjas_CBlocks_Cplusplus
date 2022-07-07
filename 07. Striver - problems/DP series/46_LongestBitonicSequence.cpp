#include <bits/stdc++.h>
using namespace std;

int longestBitonicSequence(vector<int>& arr, int n) {
	vector<int> dp1(n, 1); // LIS from front
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(arr[j] < arr[i]  &&  dp1[j]+1>dp1[i]) {
				dp1[i] = dp1[j]+1;
			}
		}
	}
	vector<int> dp2(n, 1); // LIS from back (reverse)
	for(int i=n-1; i>=0; i--) {
		for(int j=n-1; j>i; j--) {
			if(arr[j] < arr[i]  &&  dp2[j]+1>dp2[i]) {
				dp2[i] = dp2[j]+1;
			}
		}
	}
	int maxBitonic = 1;
	for(int i=0; i<n; i++) {
		int currBitonic = (dp1[i] + dp2[i] - 1);
		maxBitonic = max(maxBitonic, currBitonic);
	}
	return maxBitonic;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr;
		for(int i=0; i<n; i++) {
			int ele;
			cin >> ele;
			arr.push_back(ele);
		}
		int ans = longestBitonicSequence(arr, n);
		cout << ans << endl;
	}
	return 0;
}