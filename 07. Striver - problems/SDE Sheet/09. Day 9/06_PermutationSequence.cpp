#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getNumber(int n, int curr, int k, int fact, vector<int>& arr, string &ans) {
		while(ans.size() < n) {
			fact = fact/curr; // Lies in this section of permutation
			int idx = (k/fact); // Exact index needed
			ans += to_string(arr[idx]);
			arr.erase(arr.begin() + idx); // Erased index-element
			// Remaining elements .. automatically sorted
			k = (k % fact);
			curr--; // (n-1)! needed for next iteration
		}
		return;
	}

public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        int fact = 1;
        for(int i=1; i<=n; i++) {
        	arr.push_back(i);
        	fact *= i;
        }
        string ans = "";
        getNumber(n, n, k-1, fact, arr, ans);
        return ans;
    }
};

int main() {
	int n, k;
	cin >> n >> k;
	Solution solve;
	string ans = solve.getPermutation(n, k);
	cout << ans << "\n";
	return 0;
}