#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(m+n)
	// Space : O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1=m-1, i2=n-1, k=(m+n)-1;
        while(i1>=0 && i2>=0) {
        	if(nums1[i1] >= nums2[i2]) {
        		nums1[k--] = nums1[i1--];
        	}
        	else {
        		nums1[k--] = nums2[i2--];
        	}
        }
        while(i2 >= 0) {
        	nums1[k--] = nums2[i2--];
        }
        // If (i1 >= 0) .. they are already at there place
        return;
    }
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> nums1(m+n,0), nums2(n);
	for(int i=0; i<m; i++) {
		cin >> nums1[i];
	}
	for(int j=0; j<n; j++) {
		cin >> nums2[j];
	}
	Solution solve;
	solve.merge(nums1, m, nums2, n);
	for(int i=0; i<(m+n); i++) {
		cout << nums1[i] << " ";
	}
	cout << "\n";
	return 0;
}