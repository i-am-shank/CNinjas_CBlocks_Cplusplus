#include <bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string expression) {
	int n = expression.size();
	stack<char> stk;
	for(int i=0; i<n; i++) {
		if(expression[i] == '(') {
			stk.push(expression[i]);
		}
		else if(expression[i] == ')') {
			int count = 0;
			while(!stk.empty() && stk.top()!='(') {
				stk.pop();
				count++;
			}
			if(count == 0) {
				// Unnecessary bracket
				return true;
			}
			else { // pop out '('
				// exceptions don't exist
				// ..balanced parenthesis
				stk.pop();
			}
		}
		else if(expression[i]=='+' || expression[i]=='-' || expression[i]=='/' || expression[i]=='*') {
			stk.push(expression[i]);
		}
	}
	return false;
}

int main() {
	string expression;
	cin >> expression;
	bool ans = checkRedundantBrackets(expression);
	cout << (ans==true?"true":"false") << "\n";
	return 0;
}