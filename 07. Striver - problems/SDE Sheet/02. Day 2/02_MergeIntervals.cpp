#include <bits/stdc++.h>
using namespace std;

class Solution {
	static bool sortByStart(vector<int> v1, vector<int> v2) {
		if(v1[0] == v2[0]) {
			return (v1[1] < v2[1]);
		}
		return (v1[0] < v2[0]);
	}

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortByStart);
        // Sorted in ascending order of 1st element of vector
        vector<vector<int>> ans;
        int n = intervals.size();
        for(int i=0; i<n; i++) {
        	if(ans.size() == 0) {
        		ans.push_back(intervals[i]);
        	}
        	else {
        		int x = ans.size();
        		int endLast = ans[x-1][1];
        		int startCurr = intervals[i][0];
        		int endCurr = intervals[i][1];
        		if(startCurr <= endLast) { // Overlap
        			ans[x-1][1] = max(endLast, endCurr);
        		}
        		else {
        			ans.push_back(intervals[i]);
        		}
        	}
        }
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> intervals(n, vector<int>(2,0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<2; j++) {
			cin >> intervals[i][j];
		}
	}
	Solution solve;
	vector<vector<int>> ans = solve.merge(intervals);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}