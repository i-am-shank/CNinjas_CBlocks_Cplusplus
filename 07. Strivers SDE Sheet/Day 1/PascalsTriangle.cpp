#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++) {
        	vector<int> temp;
        	if(i <= 2) {
        		for(int k=0; k<i; k++) {
        			temp.push_back(1);
        		}
        	}
        	else {
        		temp.push_back(1);
        		vector<int> past = ans[i-2];
        		for(int j=1; j<i-1; j++) {
        			int ele = past[j-1] + past[j];
        			temp.push_back(ele);
        		}
        		temp.push_back(1);
        	}
        	ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
	Solution solve;
	int num;
	cin >> num;
	vector<vector<int>> ans = solve.generate(num);
	int n = ans.size();
	for(int i=0; i<n; i++) {
		int m = ans[i].size();
		for(int j=0; j<m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}