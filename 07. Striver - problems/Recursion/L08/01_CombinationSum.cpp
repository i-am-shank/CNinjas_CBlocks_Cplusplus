#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getCombinations(vector<int> candidates, int n, int target, vector<int> arr, vector<vector<int>>& combinations) {
		if(n < 0) {
			if(target == 0) {
				reverse(arr.begin(), arr.end());
				combinations.push_back(arr);
			}
			return;
		}
		if(target < 0) {
			return;
		}
		getCombinations(candidates, n-1, target, arr, combinations);
		if(candidates[n] <= target) {
			arr.push_back(candidates[n]);
			getCombinations(candidates, n, target-candidates[n], arr, combinations);
			arr.pop_back();
		}
		return;
	}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> arr;
        int n = candidates.size();
        getCombinations(candidates, n-1, target, arr, combinations);
        set<vector<int>> check;
        vector<vector<int>> ans;
        int m = combinations.size();
        for(int i=0; i<m; i++) {
        	if(check.find(combinations[i]) == check.end()) {
        		check.insert(combinations[i]);
        		ans.push_back(combinations[i]);
        	}
        }
        return ans;
    }
};

int main() {
	int n, target;
	cin >> n >> target;
	vector<int> candidates(n);
	for(int i=0; i<n; i++) {
		cin >> candidates[i];
	}
	Solution solve;
	vector<vector<int>> ans = solve.combinationSum(candidates, target);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}