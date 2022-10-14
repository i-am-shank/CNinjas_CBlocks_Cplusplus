#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getSums_rec(vector<int>& arr, int n, int sum, vector<int>& ans) {
		if(n < 0) {
			ans.push_back(sum);
			return; // 0 sum
		}
		getSums_rec(arr, n-1, sum, ans);
		getSums_rec(arr, n-1, sum+arr[n], ans);
		return;
	}

public:
	vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        getSums_rec(arr, n-1, 0, ans);
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	Solution solve;
	vector<int> ans = solve.subsetSums(arr, n);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}