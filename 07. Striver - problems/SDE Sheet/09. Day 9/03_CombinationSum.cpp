#include <bits/stdc++.h>
using namespace std;

class Solution {
	void subsetSum(vector<int>& candidates, int n, int target, vector<int> subset, vector<vector<int>>& subsets) {
		if(n<0) {
			if(target == 0) {
				subsets.push_back(subset);
			}
			return;
		}
		if(target < 0) {
			return; // invalid entry
		}
		subsetSum(candidates, n-1, target, subset, subsets);
		if(candidates[n] <= target) {
			subset.push_back(candidates[n]);
			// As infinite supply.. don't decrease index on take !
			subsetSum(candidates, n, target-candidates[n], subset, subsets);
		}
		return;
	}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> subsets;
        vector<int> subset;
        int n = candidates.size();
        subsetSum(candidates, n-1, target, subset, subsets);
        set<vector<int>> s;
        int m = subsets.size();
        vector<vector<int>> ans;
        for(int i=0; i<m; i++) {
        	sort(subsets[i].begin(), subsets[i].end());
        	if(s.count(subsets[i]) == 0) {
        		s.insert(subsets[i]);
        		ans.push_back(subsets[i]);
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