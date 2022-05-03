#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int start = -1, end = -1, n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());  // Will sort based on 1st element of intervals.
        for(int i=0; i<n; i++) {
        	if(start == -1  ||  end == -1) {
        		start = intervals[i][0];
        		end = intervals[i][1];
        	}
        	else if(intervals[i][0] <= end) {   // start of new interval   VS   end of old interval
        		end = max(intervals[i][1], end);
        	}
        	else {
        		vector<int> temp;
        		temp.push_back(start);
        		temp.push_back(end);
        		ans.push_back(temp);
        		start = intervals[i][0];
        		end = intervals[i][1];
        	}
        	if(i == n-1) {  // Last iteration
    			vector<int> temp;
    			temp.push_back(start);
    			temp.push_back(end);
    			ans.push_back(temp);
    		}
        }
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> intervals;
	for(int i=0; i<n; i++) {
		vector<int> temp;
		for(int j=0; j<2; j++) {
			int ele;
			cin >> ele;
			temp.push_back(ele);
		}
		intervals.push_back(temp);
	}
	Solution solve;
	vector<vector<int>> ans = solve.merge(intervals);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<2; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}