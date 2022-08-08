#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(nlogn)
	// Space : O(1)
    int shipWithinDays(vector<int>& weights, int days) {
        int s=weights[0], e=0, n=weights.size();
        for(int i=0; i<n; i++) {
        	s = min(s, weights[i]);
        	e += weights[i];
        }
        int ans = e;
        while(s <= e) {
        	int mid = s + ((e-s)>>1);
        	bool flag = true;
        	int curr=0, count=1;
        	for(int i=0; i<n; i++) {
        		curr += weights[i];
        		if(curr > mid) {
        			curr = weights[i];
        			if(weights[i] > mid) {
        				flag = false;
        				break;
        			}
        			count++;
        		}
        		if(count > days) {
        			flag = false;
        			break;
        		}
        	}
        	if(flag == true) {
        		ans = mid;
        		e = mid-1; // as we've to get least weight capacity
        	}
        	else { // Shipping not possible
        		s = mid+1; // increase weight capacity
        	}
        }
        return ans;
    }
};

int main() {
	Solution solve;
	int n, days;
	cin >> n >> days;
	vector<int> weights(n);
	for(int i=0; i<n; i++) {
		cin >> weights[i];
	}
	int ans = solve.shipWithinDays(weights, days);
	cout << ans << endl;
	return 0;
}