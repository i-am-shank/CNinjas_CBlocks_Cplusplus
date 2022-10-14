#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getSubsequences(string& s, int n, string word, vector<string>& words) {
		if(n < 0) {
			if(word != "") {
				words.push_back(word);
			}
			return;
		}
		getSubsequences(s, n-1, word, words);
		word = s[n] + word;
		getSubsequences(s, n-1, word, words);
		return;
	}

public:
	vector<string> AllPossibleStrings(string s) {
		int n = s.size();
		vector<string> words;
		string word = "";
		getSubsequences(s, n-1, word, words);
		sort(words.begin(), words.end());
		return words;
	}
};

int main() {
	Solution solve;
	string s;
	cin >> s;
	vector<string> ans = solve.AllPossibleStrings(s);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}