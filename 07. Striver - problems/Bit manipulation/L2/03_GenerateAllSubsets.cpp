#include <bits/stdc++.h>
using namespace std;

bool isSetBit(int curr, int j) {
	int mask = (1 << j);
	return ((curr & mask) != 0);
}

vector<vector<int>> getAllSubsets(vector<int> arr) {
	vector<vector<int>> allSubsets;
	int n = arr.size();
	for(int i=0; i<=((1<<n)-1); i++) {
		int curr = i;
		vector<int> subset;
		for(int j=0; j<n; j++) {
			// Check if jth bit is set in curr
			// If set -> include ele , else exclude
			if(isSetBit(curr, j)) {
				subset.push_back(arr[j]);
			}
		}
		allSubsets.push_back(subset);
	}
	return allSubsets;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	vector<vector<int>> ans = getAllSubsets(arr);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}