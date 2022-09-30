#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

class Solution{
	// Memoization
	int count_mem(string& s, int n, string word, set<string>& words) {
		
	}

	// Recursion
	// Time : O(2^n)
	// Space : O(n) .. Recursion stack
	int count_rec(string& s, int n, string word, set<string>& words) {
		if(n < 0) {
			if(words.find(word) == words.end()) {
				words.insert(word); // for ""
				return 1;
			}
			return 0;
		}
		int notTake = count_rec(s, n-1, word, words) % mod;
		int take = 0;
		word = (s[n] + word);
		if(words.find(word) == words.end()) {
			// word isn't found before
			words.insert(word);
			take = 1 + count_rec(s, n-1, word, words) % mod;
		}
		else {
			take = count_rec(s, n-1, word, words) % mod;
		}
		return (((notTake%mod) + (take%mod)) % mod);
	}

public:	
	int distinctSubsequences(string s) {
	    int n = s.size();
	    set<string> words;
	    int ans1 = count_rec(s, n-1, "", words) % mod;
	    int ans2 = count_mem(s, n-1, "", words) % mod;
	    // for(auto it: words){
	    // 	cout << it << " ";
	    // }
	    // cout << "\n";
	    return ans1;
	}
};

int main() {
	Solution solve;
	string s;
	cin >> s;
	int ans = solve.distinctSubsequences(s);
	cout << ans << "\n";
	return 0;
}