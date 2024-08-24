#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int s=1, e=(n+k);
        int ans = e;
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	int idx = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
        	int cnt = 0;
        	cnt += (mid - (idx+1));
        	if(idx!=n && arr[idx]!=mid) {
        		cnt++;
        	}
        	if(idx == n) {
        		cnt = 0;
        		cnt += (arr[n-1] - n);
        		// nos. missing in range [1, arr[n-1]]
        		cnt += (mid - arr[n-1]);
        		// nos. missing in range (arr[n-1], mid]
        	}
        	// cout<<mid<<" , "<<idx<<" -> "<<cnt<<"\n";
        	if(cnt >= k) {
        		ans = mid;
        		// search for a smaller no.
        		// it might be a case, where k-nos. are already missing
        		e = (mid-1);
        	}
        	else {
        		// search a bigger no. .. to make k-nos. missed
        		s = (mid+1);
        	}
        }
        return ans;
    }
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	int ans = solve.findKthPositive(arr, k);
	cout << ans << "\n";
	return 0;
}