// Time Complexity = O(NlogN)
//      .. For Brute force solution .. time is O(N^2)
// Space Complexity = O(N)


#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll getInversions_BruteForce(long long *arr, int n) {    // Time Complexity = O(N^2)
	ll count = 0;
	for(int i=0; i<n-1; i++) {
		ll ele = arr[i];
		for(int j=i+1; j<n; j++) {
			if(arr[j] < ele) {
				count ++;
			}
		}
	}
	return count;
}

ll merge(ll *arr, int start, int mid, int end) {
	ll temp[end-start+1];
	ll count = 0;
	int i = start, j= mid+1, k=0;
	while(i<=mid && j<=end) {
		if(arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			count += (mid-i+1);
		}
	}
	while(i <= mid) {
		temp[k++] = arr[i++];
	}
	while(j <= end) {
		temp[k++] = arr[j++];
	}
	k = 0;
	for(i=start; i<=end; i++) {
		arr[i] = temp[k++];
	}
	return count;
}

ll mergeSort(ll *arr, int start, int end) {
	if(start >= end) {
		return 0;
	}
	int mid = (start + end) / 2;
	ll smallAns1 = mergeSort(arr, start, mid);
	ll smallAns2 = mergeSort(arr, mid+1, end);
	ll count = merge(arr, start, mid, end);
	return (smallAns1 + smallAns2 + count);
}

ll getInversions(long long *arr, int n) {
	ll ans = mergeSort(arr, 0, n-1);
	return ans;
}

int main() {
	int n;
	cin >> n;
	ll* arr = new ll[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	ll count = getInversions(arr, n);
	cout << count << endl;
	delete []arr;
	return 0;
}