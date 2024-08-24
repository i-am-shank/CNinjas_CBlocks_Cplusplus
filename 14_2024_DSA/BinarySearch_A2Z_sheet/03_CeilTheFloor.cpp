#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        bool floor=false, ceil=false;
        int floorEle=INT_MIN, ceilEle=INT_MAX;
        int n = arr.size();
        for(int i=0; i<n; i++) {
        	if(arr[i] <= x) {
        		if(arr[i] > floorEle) {
        			floorEle = arr[i];
        			floor = true;
        		}
        	}
        	if(arr[i] >= x) {
        		if(arr[i] < ceilEle) {
        			ceilEle = arr[i];
        			ceil = true;
        		}
        	}
        }
        if(floor == false) {
        	floorEle = -1;
        }
        if(ceil == false) {
        	ceilEle = -1;
        }
        vector<int> ans;
        ans.push_back(floorEle);
        ans.push_back(ceilEle);
        return ans;
    }
};

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	vector<int> ans = solve.getFloorAndCeil(x, arr);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}