#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int n = arr.size();
	vector<int> prefix(n);
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += arr[i];
		prefix[i] = sum;
	}
	for(int s=0; s<n; s++) {
		for(int e=s; e<n; e++) {
			int sum = prefix[e];
			if(s > 0) {
				sum -= prefix[s-1];
			}
			minHeap.push(sum);
			if(minHeap.size() > k) {
				minHeap.pop();
			}
		}
	}
	int ans = minHeap.top();
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}
		int ans = getKthLargest(arr, k);
		cout << ans << endl;
	}
	return 0;
}