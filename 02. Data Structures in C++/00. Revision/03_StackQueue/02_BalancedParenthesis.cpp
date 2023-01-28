#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expression) {
    int n = expression.size();
    stack<char> stk;
    for(int i=0; i<n; i++) {
    	if(expression[i] == '(') {
    		stk.push(expression[i]);
    	}
    	else if(expression[i] == ')') {
    		if(!stk.empty() && stk.top()=='(') {
    			stk.pop();
    		}
    		else {
    			return false;
    		}
    	}
    }
    // If something left.. return false
    return (stk.empty());
}

int main() {
	string expression;
	cin >> expression;
	bool ans = isBalanced(expression);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}