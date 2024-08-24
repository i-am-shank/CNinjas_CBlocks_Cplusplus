#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxEle=INT_MIN, sum=0;
        for(int i=0; i<n; i++) {
        	maxEle = max(maxEle, weights[i]);
        	sum += weights[i];
        }
        int s=maxEle, e=sum, ans=sum;
        while(s <= e) {
        	int mid = (s + ((e-s)>>1));
        	int count = 1, curr=0;
        	for(int i=0; i<n; i++) {
        		curr += weights[i];
        		if(curr > mid) {
        			count++;
        			curr = weights[i];
        		}
        	}
        	if(count <= days) {
        		ans = min(ans, mid);
        		// find a smaller capacity, if possible
        		e = (mid-1);
        	}
        	else {
        		s = (mid+1);
        	}
        }
        return ans;
    }
};

int main() {
	int n, days;
	cin >> n >> days;
	vector<int> weights(n);
	for(int i=0; i<n; i++) {
		cin >> weights[i];
	}
	Solution solve;
	int ans = solve.shipWithinDays(weights, days);
	cout << ans << "\n";
	return 0;
}