#include <bits/stdc++.h>
using namespace std;

int variation(int* arr, int n, int k) {
	sort(arr, arr+n);
	int i=0, j=1, count = 0;
	while(i<n && j<n) {
		if(i == j) {
			if(j < n-1) {
				j++;
			}
			else {
				break;
			}
		}
		if(arr[j] - arr[i] >= k) {
			count += (n-j);
			i++;
		}
		else {
			j++;
		}
	}
	return count;
}

int main() {
	int n, k;
	cin >> n >> k;
	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int count = variation(arr, n, k);
	cout << count << endl;
	delete []arr;
	return 0;
}