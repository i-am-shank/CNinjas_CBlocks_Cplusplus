#include <bits/stdc++.h>
using namespace std;

class Solution {
	void subsetSum(vector<int>& arr, int idx, int target, vector<int>& subset, vector<vector<int>>& subsets) {
		if(idx >= arr.size()) {
			if(target == 0) {
				subsets.push_back(subset);
			}
			return;
		}
		if(target == 0) {
			subsets.push_back(subset);
			return;
		}
		for(int i=idx; i<arr.size(); i++) {
			if((i>idx) && (arr[i]==arr[i-1])) {
				continue;
			}
			if(arr[i] > target) {
				break;
			}
			subset.push_back(arr[i]);
			subsetSum(arr, idx+1, target-arr[i], subset, subsets);
			subset.pop_back();
		}
		return;
	}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> subsets;
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        subsetSum(candidates, 0, target, subset, subsets);
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int i=0; i<subsets.size(); i++) {
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
	vector<vector<int>> ans = solve.combinationSum2(candidates, target);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}