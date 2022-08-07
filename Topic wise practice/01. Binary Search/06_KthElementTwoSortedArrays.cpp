#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	// Time : O( log(min(n,m)) )
	// Space : O(1)
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        if(n > m) {
        	return kthElement(arr2, arr1, m, n, k);
        }
        int s=max(0,k-m), e=min(n,k);
        while(s <= e) {
        	int cut1 = (s+e) >> 1;
        	int cut2 = (k-cut1);
        	int l1=INT_MIN, l2=INT_MIN, r1=INT_MAX, r2=INT_MAX;
        	if(cut1 != 0) {
        		l1 = arr1[cut1-1];
        	}
        	if(cut2 != 0) {
        		l2 = arr2[cut2-1];
        	}
        	if(cut1 < n) {
        		r1 = arr1[cut1];
        	}
        	if(cut2 < m) {
        		r2 = arr2[cut2];
        	}
        	// Check valid partition
        	if(l1<=r2 && l2<=r1) {
        		return max(l1, l2); // Right-most element in left partitions
        		// kth element
        	}
        	else {
        		if(l1 > r2) { // Lower the partition 1
        			e = cut1-1;
        		}
        		else {
        			s = cut1+1;
        		}
        	}
        }
        return 0; // Code will reach here only for invalid parameters
    }
};

int main() {
	Solution solve;
	int n, m, k;
	cin >> n >> m >> k;
	int* arr1 = new int[n];
	for(int i=0; i<n; i++) {
		cin >> arr1[i];
	}
	int *arr2 = new int[m];
	for(int i=0; i<m; i++) {
		cin >> arr2[i];
	}
	int ans = solve.kthElement(arr1, arr2, n, m, k);
	cout << ans << endl;
	delete []arr1;
	delete []arr2;
	return 0;
}