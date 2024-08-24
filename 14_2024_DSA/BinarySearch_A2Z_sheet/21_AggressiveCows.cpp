#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int> &stalls) {
    	sort(stalls.begin(), stalls.end());
    	int minDiff = INT_MAX;
    	for(int i=0; i<(n-1); i++) {
    		int currDiff = (stalls[i+1] - stalls[i]);
    		minDiff = min(minDiff, currDiff);
    	}
    	int s=minDiff, e=stalls[n-1];
    	int ans = minDiff;
    	while(s <= e) {
    		int mid = (s + ((e-s)>>1));
    		// mid  -->  min. distance
    		// check if it is a possible min. distance
    		int prev = -1; // not initialised
    		int count = 0;
    		for(int i=0; i<n; i++) {
    			if(prev == -1) {
    				prev = stalls[i];
    				count++;
    			}
    			else {
    				if(stalls[i]-prev >= mid) {
    					prev = stalls[i];
    					count++;
    				}
    			}
    		}
    		if(count >= k) {
    			// a possible min. distance
    			ans = mid;
    			s = (mid+1);
    			// try to maximise this min. distance
    		}
    		else {
    			// try a smaller min. distance to get stall count
    			e = (mid-1);
    		}
    	}
    	return ans;
    }
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> stalls(n);
	for(int i=0; i<n; i++) {
		cin >> stalls[i];
	}
	Solution solve;
	int ans = solve.solve(n, k, stalls);
	cout << ans << "\n";
	return 0;
}