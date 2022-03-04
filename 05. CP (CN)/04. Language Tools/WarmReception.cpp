#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int countChairs(int* a, int* d, int n) {
	sort(a, a+n);
	sort(d, d+n);
	int i=1, j=0, currCount=1, maxCount=0;
	while(i<n && j<n) {
		if(a[i] < d[j]) {
			currCount++;
			i++;
		}
		else if(a[i] > d[j]) {
			currCount--;
			j++;
		}
		else {
			i++;
			j++;
		}
		maxCount = max(maxCount, currCount);
	}
	return maxCount;
}

int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	int *d = new int[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<n; i++) {
		cin >> d[i];
	}
	int ans = countChairs(a, d, n);
	cout << ans << endl;
	delete []a;
	delete []d;
	return 0;
}