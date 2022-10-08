#include <bits/stdc++.h>
using namespace std;

string getString(char s[]) {
	string str = "";
	int i = 0;
	while(s[i] != '\0') {
		str += s[i];
		i++;
	}
	return str;
}

vector<int> longestPrefixSuffix(string pattern) {
	int n = pattern.size();
	vector<int> lps(n, 0);
	int i=1, j=0;
	while(i < n) {
		if(pattern[i] == pattern[j]) {
			lps[i] = (j+1);
			i++;
			j++;
		}
		else {
			if(j != 0) {
				j = lps[j-1];
			}
			else {
				lps[i] = 0; // No matching-prefix found
				i++;
			}
		}
	}
	return lps;
}

int getIndex(string str, string pattern) {
	vector<int> lps = longestPrefixSuffix(pattern);
	int ns=str.size(), np=pattern.size(), i=0, j=0;
	while(i<ns && j<np) {
		if(str[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			if(j != 0) {
				j = lps[j-1];
			}
			else {
				i++; // ith char not matchable with any char of pattern
			}
		}
	}
	if(j != np) {
		// pattern not matched
		return -1;
	}
	else {
		int end = i; // End index (not included in matching) .. Starting idx = (end - np)
		int ans = (end - np);
		return ans;
	}
}

int findString(char s[], char t[]) {
	vector<int> lps = longestPrefixSuffix(t);
	string str="", pattern="";
	str = getString(s);
	pattern = getString(t);
	int ans = getIndex(str, pattern);
	return ans;
}

int main() {
	char s[100000], t[100000];
	string str_s, str_t;
	cin >> str_s >> str_t;
	int ns = str_s.size(), nt = str_t.size();
	for(int i=0; i<ns; i++) {
		s[i] = str_s[i];
	}
	s[ns] = '\0';
	for(int i=0; i<nt; i++) {
		t[i] = str_t[i];
	}
	t[nt] = '\0';
	int ans = findString(s, t);
	cout << ans << "\n";
	return 0;
}