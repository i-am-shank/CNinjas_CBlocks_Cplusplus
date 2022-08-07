#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O( log(n1+n2) )
	// Space : O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) {
        	return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.size(), n2 = nums2.size();
        int n = (n1+n2);
        int count = (n+1)/2; // order-no. of median.. in sorted array of length n
        int s=0, e=n1; // searching already optimized by size-condition (top)
        while(s <= e) {
        	int cut1 = (s+e) >> 1;
        	int cut2 = count - (cut1);
        	int l1=INT_MIN, r1=INT_MAX, l2=INT_MIN, r2=INT_MAX; 
        	if(cut1 > 0) {
        		l1 = nums1[cut1-1];
        	}
        	if(cut1 < n1) {
        		r1 = nums1[cut1];
        	}
        	if(cut2 > 0) {
        		l2 = nums2[cut2-1];
        	}
        	if(cut2 < n2) {
        		r2 = nums2[cut2];
        	}
        	if((l1<=r2)  &&  (l2<=r1)) { // valid cut
        		if(n%2 == 0) {
        			double ans = (max(l1,l2) + min(r1,r2)) / 2.0;
        			return ans;
        		}
        		else {
        			double ans = max(l1, l2);
        			return ans;
        		}
        	}
        	else if(l1 > r2) { // in-valid check 1
        		e = cut1-1;
        	}
        	else {
        		s = cut1+1;
        	}
        }
        return 0.0;
    }
};

int main() {
	Solution solve;
	int n1, n2;
	cin >> n1 >> n2;
	vector<int> nums1(n1), nums2(n2);
	for(int i=0; i<n1; i++) {
		cin >> nums1[i];
	}
	for(int i=0; i<n2; i++) {
		cin >> nums2[i];
	}
	double ans = solve.findMedianSortedArrays(nums1, nums2);
	cout << ans << endl;
	return 0;
}