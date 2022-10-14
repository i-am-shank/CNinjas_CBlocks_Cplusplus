#include <bits/stdc++.h>
using namespace std;

// Using 1-pointer variable
void reverseArray2(vector<int>& arr, int i, int n) {
	if(i > (n/2)) {
		return;
	}
	int temp = arr[i];
	arr[i] = arr[(n-1)-i];
	arr[(n-1)-i] = temp;
	reverseArray2(arr, i+1, n);
	return;
}

// Using 2-pointer variables
void reverseArray(vector<int>& arr, int start, int end) {
	if(start >= end) {
		// Nothing remains to be reversed
		return;
	}
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	reverseArray(arr, start+1, end-1);
	return;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	// reverseArray(arr, 0, n-1);
	reverseArray2(arr, 0, n);
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	return 0;
}