#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	// Time Complexity = O(m+n)  ..  both functions

	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {  // O(1) space complexity
		int i=m-1, j=n-1, k=((m+n)-1);
		while(i>=0  &&  j>=0) {
			if(nums1[i] > nums2[j]) {
				nums1[k--] = nums1[i--];
			}
			else {
				nums1[k--] = nums2[j--];
			}
		}
		//  If nums2 is exhausted.. either nums1 also exhausted ..OR.. nums1 is placed correctly
		//  So  -->  no need of   while(i >= 0)  loop.
		while(j >= 0) {
			nums1[k--] = nums2[j--];
		}
		return;
	}

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	if(n == 0) {  // All elements are already in nums1.
    		return;
    	}
    	if(m == 0) {  // All elements are in nums2.
    		for(int i=0; i<n; i++) {
    			nums1[i] = nums2[i];
    		}
    		return;
    	}
        int temp[m+n];
        int i=0, j=0, k=0;
        while(i<m && j<n) {
        	if(nums1[i] <= nums2[j]) {
        		temp[k++] = nums1[i++];
        	}
        	else {
        		temp[k++] = nums2[j++];
        	}
        }
        while(i < m) {
        	temp[k++] = nums1[i++];
        }
        while(j < n) {
        	temp[k++] = nums2[j++];
        }
        for(int i=0; i<k; i++) {
        	nums1[i] = temp[i];
        }
        return;
    }
};

int main() {
	Solution solve;
	int m, n;
	cin >> m >> n;
	vector<int> nums1;
	vector<int> nums2;
	for(int i=0; i<m+n; i++) {   // Last n elements are 0.
		int ele;
		cin >> ele;
		nums1.push_back(ele);
	}
	for(int i=0; i<n; i++) {
		int ele;
		cin >> ele;
		nums2.push_back(ele);
	}
	solve.merge2(nums1, m, nums2, n);
	for(int i=0; i<nums1.size(); i++) {
		cout << nums1[i] << " ";
	}
	cout << endl;
	return 0;
}