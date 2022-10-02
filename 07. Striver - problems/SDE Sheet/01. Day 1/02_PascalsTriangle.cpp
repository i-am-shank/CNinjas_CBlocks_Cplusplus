#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time : O(n^2)
	// Space : O(n) .. Auxiliary space
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> row1;
    	row1.push_back(1);
       	ans.push_back(row1);
        if(numRows == 1) {
        	return ans;
        }
        vector<int> row2;
        row2.push_back(1);
        row2.push_back(1);
        ans.push_back(row2);
        if(numRows == 2) {
        	return ans;
        }
        for(int i=3; i<=numRows; i++) {
        	vector<int> row;
        	row.push_back(1); // start of each row
        	for(int j=1; j<i-1; j++) {
        		row.push_back(ans[i-2][j-1] + ans[i-2][j]);
        	}
        	row.push_back(1); // end of each row
        	ans.push_back(row);
        }
        return ans;
    }
};

int main() {
	Solution solve;
	int numRows;
	cin >> numRows;
	vector<vector<int>> ans = solve.generate(numRows);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}