#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n)
	// Water trapped => will be defined by min. of heights of left & right
	//               => & their difference with current height
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n, 0);
        int leftMax = INT_MIN;
        for(int i=0; i<n; i++) {
        	leftMax = max(leftMax, height[i]);
        	lmax[i] = leftMax;
        }
        vector<int> rmax(n, 0);
        int rightMax = INT_MIN;
        for(int i=n-1; i>=0; i--) {
        	rightMax = max(rightMax, height[i]);
        	rmax[i] = rightMax;
        }
        int water = 0;
        for(int i=1; i<n-1; i++) {
        	int lh = lmax[i-1], rh = rmax[i+1];
        	if(min(lh,rh) > height[i]) {
        		water  +=  (min(lh,rh) - height[i]);
        	}
        }
        return water;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<int> height(n);
	for(int i=0; i<n; i++) {
		cin >> height[i];
	}
	int ans = solve.trap(height);
	cout << ans << "\n";
	return 0;
}