#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int s1=0, e1=n1-1, s2=0, e2=n2-1;
        
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