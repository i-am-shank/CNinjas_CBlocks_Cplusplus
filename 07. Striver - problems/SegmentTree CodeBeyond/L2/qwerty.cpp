// 2 strings ? Anagram ... same letters are in both

// a b c

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string& s1, string& s2) {
	vector<int> freq1(26, 0); // initially 0 frequency
	vector<int> freq2(26, 0);
	int n1 = s1.size(), n2 = s2.size();
	for(int i=0; i<n1; i++) {
		freq1[(int)(s1[i]-'a')]++; // [0, 26)
	}
	for(int i=0; i<n2; i++) {
		freq2[(int)(s2[i]-'a')]++;
	}
	bool flag = true; // assuming both are anagrams
	for(int i=0; i<26; i++) {
		if(freq1[i] != freq2[i]) {
			// ('a'+i)th character freq. isn't matching
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	bool ans = isAnagram(s1, s2);
	cout << (ans == true ? "true" : "false") << endl;
	return 0;
}