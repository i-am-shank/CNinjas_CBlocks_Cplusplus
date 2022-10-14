#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getCombinations(vector<int> candidates, int n, int idx, int target, vector<int> arr, vector<vector<int>>& combinations) {
		if(idx > n) {
			if(target == 0) {
				combinations.push_back(arr);
			}
			return;
		}
		if(target == 0) {
			combinations.push_back(arr);
			return;
		}
		for(int i=idx; i<=n; i++) {
			if((i>idx) && (candidates[i]==candidates[i-1])) {
				continue;
			}
			if(candidates[i] > target) {
				continue;
			}
			arr.push_back(candidates[i]);
			getCombinations(candidates, n, i+1, target-candidates[i], arr, combinations);
			arr.pop_back();
		}
		return;
	}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> arr;
        int n = candidates.size();
        getCombinations(candidates, n-1, 0, target, arr, combinations);
        set<vector<int>> check;
        vector<vector<int>> ans;
        int m = combinations.size();
        for(int i=0; i<m; i++) {
        	sort(combinations[i].begin(), combinations[i].end());
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
	vector<vector<int>> ans = solve.combinationSum2(candidates, target);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}