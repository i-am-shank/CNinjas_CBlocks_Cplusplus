// {1+3*(5+[9*5] ) }

// 1+3 -> valid
// (   or   )   -> invalid

// []  {}  ()

#include <bits/stdc++.h>
using namespace std;

bool isValid(string str) {
	// ({}) .. ( .. { .. } .. )
	// LIFO .. stack
	stack<char> stk;
	int n = str.size();
	for(int i=0; i<n; i++) {
		char c = str[i];
		// Only pushing parenthesis
		if(c=='[' || c=='(' || c=='{') {
			stk.push(c);
		}
		else if(c==']') {
			if(stk.empty()) {
				return false;
			}
			if(stk.top() == '[') {
				stk.pop();
			}
			else {
				// any invalid character is on top
				cout << "[" << "\n";
				return false;
			}
		}
		else if(c=='}') {
			if(stk.empty()) {
				return false;
			}
			if(stk.top() == '{') {
				stk.pop();
			}
			else {
				// any invalid character is on top
				cout << "{" << "\n";
				return false;
			}
		}
		else if(c==')') {
			if(stk.empty()) {
				return false;
			}
			if(stk.top() == '(') {
				stk.pop();
			}
			else {
				// any invalid character is on top
				cout << "(" << "\n";
				return false;
			}
		}
		else if(c==' ') {
			continue;
		}
	}
	return stk.empty();
}

int main() {
	string str;
	getline(cin, str);
	bool ans = isValid(str);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}