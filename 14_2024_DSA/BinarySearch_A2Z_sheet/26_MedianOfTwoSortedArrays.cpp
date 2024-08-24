#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        vector<int> arr(n1+n2);
        int i1=0, i2=0, idx=0;
        while(i1<n1 && i2<n2) {
        	if(nums1[i1] <= nums2[i2]) {
        		arr[idx] = nums1[i1];
        		idx++;
        		i1++;
        	}
        	else {
        		arr[idx] = nums2[i2];
        		idx++;
        		i2++;
        	}
        }
        while(i1 < n1) {
        	arr[idx] = nums1[i1];
        	idx++;
        	i1++;
        }
        while(i2 < n2) {
        	arr[idx] = nums2[i2];
        	idx++;
        	i2++;
        }
        int n = (n1+n2);
        if((n%2) == 0) {
        	double ans = (double)(arr[n/2] + arr[(n-1)/2]);
        	ans /= 2.0;
        	return ans;
        }
        else {
        	double ans = (double)arr[n/2];
        	return ans;
        }
    }
};

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	vector<int> nums1(n1), nums2(n2);
	for(int i=0; i<n1; i++) {
		cin >> nums1[i];
	}
	for(int i=0; i<n2; i++) {
		cin >> nums2[i];
	}
	Solution solve;
	double ans = solve.findMedianSortedArrays(nums1, nums2);
	cout << fixed << setprecision(5) << ans << "\n";
	return 0;
}