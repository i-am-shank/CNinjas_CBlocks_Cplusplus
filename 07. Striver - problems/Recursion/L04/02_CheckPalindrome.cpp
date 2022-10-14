#include <bits/stdc++.h>
using namespace std;

// Using 1-pointer variable
// Time : O(n)
// Space : O(n) .. Recursion stack
bool isPalindrome2(string s, int i, int n) {
	if(i > (n/2)) {
		return true;
	}
	if(s[i] == s[(n-1)-i]) { // recursion call
		return isPalindrome2(s, i+1, n);
	}
	else { // Not matching
		return false;
	}
}

// Using 2-pointer variables
bool isPalindrome(string s, int start, int end) {
	if(start >= end) {
		return true;
	}
	if(s[start] == s[end]) {
		// Recursion call.. for smaller substring
		return isPalindrome(s, start+1, end-1);
	}
	else {
		return false; // Not matching
	}
}

int main() {
	string s;
	cin >> s;
	int n = s.size();
	// bool ans = isPalindrome(s, 0, n-1);
	bool ans2 = isPalindrome2(s, 0, n);
	cout << (ans2 == true ? "true" : "false") << "\n";
	return 0;
}