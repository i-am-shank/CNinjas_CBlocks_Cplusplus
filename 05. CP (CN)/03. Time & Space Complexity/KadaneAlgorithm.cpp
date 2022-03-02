// Question  :  Maximum Sum sub-array

#include <iostream>
using namespace std;

int maxSumSubarray(int* arr, int n) {
	int currentSum = 0, maxSum = 0;
	for(int i=0; i<n; i++) {
		currentSum += arr[i];
		if(currentSum > maxSum) {
			maxSum = currentSum;
		}
		if(currentSum < 0) {
			currentSum = 0;
		}
	}
	return maxSum;
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int ans = maxSumSubarray(arr, n);
	cout << ans << endl;
	delete []arr;
	return 0;
}