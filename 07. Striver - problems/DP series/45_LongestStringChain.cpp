#include <bits/stdc++.h>
using namespace std;

class Solution {
	// Comparing word1 & word2  ->  Such that :
	//  -> word1 has exactly 1 extra character than word2.
	static bool compare(string word1, string word2) {
		int i=0, j=0, n1=word1.size(), n2=word2.size(), count=0;
		if(n1 != n2+1) {
			return false;
		}
		while(i < n1) {
			if(word1[i] == word2[j]) {
				i++;
				j++;
			}
			else {
				count++;
				i++;
			}
		}
		if(count == 1) {
			return true;
		}
		return false;
	}

	int lis_modified(int n, vector<string>& words) {
		int maxLength = 1;
		vector<int> dp(n, 1);
		for(int i=0; i<n; i++) {
			for(int j=0; j<i; j++) {
				if(compare(words[i],words[j]) && dp[i]<dp[j]+1) {
					dp[i] = dp[j]+1;
					maxLength = max(maxLength, dp[i]);
				}
			}
		}
		return maxLength;
	}

	static bool sortBySize(string s1, string s2) {
		return s1.size() < s2.size();
	}

public:
    int longestStrChain(vector<string>& words) {
    	sort(words.begin(), words.end(), sortBySize);
        int n = words.size();
        int ans = lis_modified(n, words);
        return ans;
    }
};

int main() {
	Solution solve;
	int n;
	cin >> n;
	vector<string> words;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		words.push_back(s);
	}
	int ans = solve.longestStrChain(words);
	cout << ans << endl;
	return 0;
}