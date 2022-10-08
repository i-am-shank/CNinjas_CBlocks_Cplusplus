#include <bits/stdc++.h>
using namespace std;

vector<int> longestPrefixSuffix(string& str) {
	int n = str.size();
	vector<int> lps(n, 0);
	int i=1, j=0;
	while(i < n) {
		if(str[i] == str[j]) { // continue matching
			lps[i] = (j+1);
			i++;
			j++;
		}
		else { // Go back.. to get the shorter - longest-prefix
			if(j != 0) { // Not reached begining
				j = lps[j-1]; // Refer back to last matched 
			}
			else { // If j = 0
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

bool kmpSearch(string str, string pattern) {
	vector<int> lps = longestPrefixSuffix(pattern);
	int ns = str.size(), np = pattern.size();
	int i=0, j=0;
	while(i<ns && j<np) {
		if(str[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			// Use lps.. to start matching again with closest backtrack
			if(j != 0) {
				j = lps[j-1];
			}
			else { // j already traversed back to 0
				i++; // Still not matched.. start matching from next char.
			}
		}
	}
	if(j == np) {
		// Pattern traversed
		return true; // Pattern found
	}
	else {
		return false;
	}
}

int main() {
	string str, pattern;
	cin >> str >> pattern;
	bool ans = kmpSearch(str, pattern);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}