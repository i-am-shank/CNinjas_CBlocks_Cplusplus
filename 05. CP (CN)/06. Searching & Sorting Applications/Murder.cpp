#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll merge(int *arr, int start, int mid, int end) {
	int i=start, j=mid+1, k=0;
	int temp[end-start+1];
	ll count = 0;
	while(i<=mid && j<=end) {
		if(arr[i] < arr[j]) {
			count  +=  (arr[i] * ((end+1)-j));
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid) {
		temp[k++] = arr[i++];
	}
	while(j<=end) {
		temp[k++] = arr[j++];
	}
	k=0;
	for(int i=start; i<=end; i++) {
		arr[i] = temp[k++];
	}
	return count;
}

ll mergeSortHelp(int *arr, int start, int end) {
	if(start >= end) {
		return 0;
	}
	int mid = (start + end) / 2;
	ll smallAns1 = mergeSortHelp(arr, start, mid);
	ll smallAns2 = mergeSortHelp(arr, mid+1, end);
	ll count = merge(arr, start, mid, end);
	return (count + smallAns1 + smallAns2);
}

ll mergeSort(int* arr, int n) {
	return mergeSortHelp(arr, 0, n-1);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int *arr = new int[n];
		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}
		ll sum = mergeSort(arr, n);
		cout << sum << endl;
		delete []arr;
	}
	return 0;
}