#include <bits/stdc++.h>
#include <unordered_map>
#include <string>
using namespace std;

string uniqueChar(string str) {
	unordered_map<char, int> freq;
	string ans;
	for(int i=0; i<str.size(); i++) {
		if(freq.find(str[i]) == freq.end()) { // Not found before
			ans.push_back(str[i]);
		}
		freq[str[i]] ++;
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	string ans = uniqueChar(s);
	cout << ans << endl;
	return 0;
}