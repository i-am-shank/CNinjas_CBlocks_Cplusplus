#include <bits/stdc++.h>
using namespace std;

long long Kadane_Sum(int *arr, int n) {
	long long currSum = 0, KadaneSum = INT_MIN;
	for(int i=0; i<n; i++) {
		currSum = currSum + arr[i];
		KadaneSum = max(currSum, KadaneSum);
		if(currSum < 0) {
			currSum = 0;
		}
	}
	return KadaneSum;
}

long long maxSumSubarray(int *arr, int n, int k) {  // KadaneSum , sum , prefixSum
	long long KadaneSum = Kadane_Sum(arr, n);
	if(k == 1) {
		return KadaneSum;
	}
	long long sum = 0, prefixSum = INT_MIN;
	for(int i=0; i<n; i++) {  // prefixSum
		sum = sum + arr[i];
		prefixSum = max(sum, prefixSum);
	}
	long long currSuffixSum = 0, suffixSum = INT_MIN;
	for(int i=n-1; i>=0; i--) {  // suffixSum
		currSuffixSum = currSuffixSum + arr[i];
		suffixSum = max(suffixSum, currSuffixSum);
	}
	long long ans;
	if(sum < 0) {
		ans = max(KadaneSum  ,  suffixSum + prefixSum);
	}
	else {
		ans = max(KadaneSum  ,  (sum*(k-2)) + prefixSum + suffixSum);
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int *arr = new int[n];
		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}
		long long ans = maxSumSubarray(arr, n, k);
		cout << ans << endl;
		delete []arr;
	}
	return 0;
}