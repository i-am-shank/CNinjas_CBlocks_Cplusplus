#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int charToInt(char c) {
	return (int)(c);
}

void printRepititions(vector<string> input) {
	int n = input.size();
	unordered_map<string, int> freq;
	for(int i=0; i<n; i++) {
		freq[input[i]] ++;
	}
	unordered_map<string, int> :: iterator it;
	int count = 0;
	for(it=freq.begin(); it!=freq.end(); it++) {
		if(it->second > 1  &&  it->first!="") {
			cout << it->first << " " << it->second << " " << endl;
			count ++;
		}
	}
	if(count ==  0) {
		cout << -1 << endl;
	}
	return;
}

int main() {
	string s;
	getline(cin, s);
	int n = s.size();
	vector<string> input;
	string temp;
	for(int i=0; i<n+1; i++) {
		int currC = charToInt(s[i]);
		if((currC >= 65 && currC<=90)  ||  (currC>=97 && currC<=122)) {
			temp.push_back(s[i]);
		}
		else {
			input.push_back(temp);
			temp = ""; // clear temp string.
		}
	}
	printRepititions(input);
	return 0;
}