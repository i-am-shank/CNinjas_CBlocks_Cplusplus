#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isPalindrome(string s) {
		string s2 = s;
		reverse(s2.begin(), s2.end());
		return (s == s2);
	}

	void getSubsets(string& s, int n, vector<string>& subset, vector<vector<string>>& subsets) {
		if(n < 0) {
			// reverse(subset.begin(), subset.end());
			subsets.push_back(subset);
			return;
		}
		string temp = "";
		for(int i=n; i>=0; i--) {
			temp = s[i] + temp;
			if(isPalindrome(temp)) {
				// cout << temp << " ";
				subset.push_back(temp);
				getSubsets(s, i-1, subset, subsets);
				subset.pop_back(); // To explore other possibilities
			}
		}
		return;
	}

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> subsets;
        vector<string> subset;
        int n = s.size();
        getSubsets(s, n-1, subset, subsets);
        int m = subsets.size();
        vector<vector<string>> ans(m);
        for(int i=0; i<m; i++) {
        	for(int j=subsets[i].size()-1; j>=0; j--) {
        		ans[i].push_back(subsets[i][j]);
        	}
        }
        return ans;
    }
};

int main() {
	Solution solve;
	string s;
	cin >> s;
	vector<vector<string>> ans = solve.partition(s);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}