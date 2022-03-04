#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

char getChar (int i) {
	return (char)(i+97);
}

void printPalindrome(string s) {
	map<char, vector<int>> indexMap;
	for(int i=0; i<s.size(); i++) {  // Storing indexes in map
		indexMap[s[i]].push_back(i);
	}
	map<char, int> freq;
	for(int i=0; i<26; i++) {  // Storing frequencies with help of index map.
		freq[getChar(i)] = indexMap[getChar(i)].size();
	}
	int odd_freq_count = 0;
	for(int i=0; i<26; i++) {
		if((freq[getChar(i)] % 2)  !=  0) {
			odd_freq_count ++;
		}
	}
	if(odd_freq_count >= 2) {
		cout << -1 << endl;
		return;
	}
	int ans[s.size()];
	int start = 0, end = s.size()-1;
	for(int i=0; i<26; i++) {
		char currChar = getChar(i);
		for(int j=0; j<freq[currChar]; j+=2) {
			if(freq[currChar] - j  ==  1) {
				ans[s.size()/2] = indexMap[currChar][j];
				continue;
			}
			ans[start] = indexMap[currChar][j];
			ans[end] = indexMap[currChar][j+1];
			start ++;
			end --;
		}
	}
	for(int i=0 ;i<s.size(); i++) {
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
	return ;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		printPalindrome(s);
	}
	return 0;
}