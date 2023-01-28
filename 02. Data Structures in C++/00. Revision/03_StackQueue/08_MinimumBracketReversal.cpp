#include <bits/stdc++.h>
using namespace std;

int countBracketReversals(string input) {
	int n = input.size();
	stack<char> stk;
	for(int i=0; i<n; i++) {
		if(input[i] == '{') {
			stk.push(input[i]);
		}
		else if(input[i] == '}') {
			if(!stk.empty() && stk.top()=='{') {
				stk.pop();
			}
			else {
				stk.push(input[i]);
			}
		}
	}
	if(stk.size() % 2 != 0) {
		// odd-size
		return -1;
	}
	else {
		// some-reversals can be answer
		// int start=0, end=0;
		int count = 0;
		while(!stk.empty()) {
			if(stk.top() == '{') {
				stk.pop();
				if(stk.top() == '{') {
					count += 1;
					stk.pop();
				}
				else {
					count += 2;
					stk.pop();
				}
			}
			else { // '}'
				stk.pop();
				if(stk.top() == '{') {
					// this case won't reach ideally
					stk.pop();
				}
				else {
					stk.pop();
					count += 1;
				}
			}
		}
		return count;
	}
}

int main() {
	string input;
	cin >> input;
	int ans = countBracketReversals(input);
	cout << ans << "\n";
	return 0;
}