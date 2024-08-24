#include <bits/stdc++.h>
using namespace std;

// 39 6 11 14 18 36 37 38

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // find index of minimum element
        int n = arr.size();
        int s=0, e=(n-1);
        int ans = -1;
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	if(arr[s] <= arr[mid]) {
        		// left half sorted
        		if((ans==-1) || (ans!=-1 && arr[ans]>arr[s])) {
        			ans = s; // index-(s) has smallest element
        		}
        		// search in right half
        		s = (mid+1);
        	}
        	else {
        		// right half sorted
        		if((ans==-1) || (ans!=-1 && arr[ans]>arr[mid])) {
        			ans = mid; // index-(mid) has smallest element
        		}
        		e = (mid-1);
        	}
        }
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	int ans = solve.findKRotation(arr);
	cout << ans << "\n";
	return 0;
}