#include <iostream>
using namespace std;

// 12
// 1 1 1 1 2 2 2 2 2 1 1 1

int longestRepeatingOdd(int* arr, int n) {
	int prev = 0, cnt=0, maxCnt=0;
	for(int i=0; i<n; i++) {
		if(((arr[i]%2) != 0) && (arr[i] == prev)) {
			cnt++;
			maxCnt = max(maxCnt, cnt);
		}
		else if((arr[i]%2) != 0) {
			prev = arr[i];
			cnt = 1;
			maxCnt = max(maxCnt, cnt);
		}
		else {
			// no need to update prev.. 
			cnt = 0;
		}
	}
	return maxCnt;
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int ans = longestRepeatingOdd(arr, n);
	cout << ans << "\n";
	return 0;
}