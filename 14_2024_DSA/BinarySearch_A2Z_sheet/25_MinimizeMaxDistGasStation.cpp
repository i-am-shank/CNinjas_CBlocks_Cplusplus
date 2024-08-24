#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
    	int n = stations.size();
    	double maxDiff = (double)INT_MIN;
    	for(int i=0; i<(n-1); i++) {
    		double currDiff = (double)(stations[i+1] - stations[i]);
    		maxDiff = max(maxDiff, currDiff);
    	}
    	double s=0, e=maxDiff;
    	while(s<=e  &&  ((e-s) >= 0.01)) {
    		double mid = (s + ((e-s)>>1));
    		int count=1;
    		double curr = stations[0];
    		for(int i=1; i<n; i++) {
    			double curr = (((double)stations[i] - curr) / mid);
    			int currCnt = (int)curr;
    			if((double)currCnt < curr) {
    				currCnt++;
    			}
    			count += currCount;
    			curr = stations[i]; // for next iteration
    		}
    		if(count <= k) {
    			
    		}
    	}
    }
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> stations(n);
	for(int i=0; i<n; i++) {
		cin >> stations[i];
	}
	Solution solve;
	double ans = solve.findSmallestMaxDist(stations, k);
	cout << ans << "\n";
	return 0;
}