#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(((ll)m*(ll)k) > (ll)n) {
        	return -1; // can't make m-bouquets
        }
        int minEle=INT_MAX, maxEle=INT_MIN;
        for(int i=0; i<n; i++) {
        	minEle = min(minEle, bloomDay[i]);
        	maxEle = max(maxEle, bloomDay[i]);
        }
        int s=minEle, e=maxEle;
        int ans = e;
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	int count = 0;
        	int prev = 0;
        	for(int i=0; i<n; i++) {
        		if(bloomDay[i] <= mid) {
        			// bloomed
        			if(((i-prev)+1) == k) {
        				count++;
        				prev = (i+1);
        			}
        		}
        		else {
        			// not bloomed
        			prev = (i+1);
        		}
        	}
        	if(count >= m) {
        		ans = min(ans, mid);
        		// search for a smaller no. of days
        		e = (mid-1);
        	}
        	else {
        		s = (mid+1);
        	}
        }
        return (int)ans;
    }
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> bloomDay(n);
	for(int i=0; i<n; i++) {
		cin >> bloomDay[i];
	}
	Solution solve;
	int ans = solve.minDays(bloomDay, m, k);
	cout << ans << "\n";
	return 0;
}