#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int i1=lower_bound(arr, arr+n, x) - arr;
	    int i2=upper_bound(arr, arr+n, x) - arr;
	    return (i2 - i1);
	}
};

int main() {
	int arr[100000];
	int n, x;
	cin >> n >> x;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	int ans = solve.count(arr, n, x);
	cout << ans << "\n";
	return 0;
}