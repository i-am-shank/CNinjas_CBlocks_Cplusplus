// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkRedundantBrackets(string expression) {
    stack <int> s;
    char ch;
    int l = expression.length();
    for(int i=0; i<l; i++) {
        ch = expression[i];
        if(ch != ')') {
            s.push(ch);
        }
        else {
            int count=0;
            while(s.top() != '(') {
                if(s.top()=='+' || s.top()=='-' || s.top()=='*' || s.top()=='/') {
                    count ++;
                }
                s.pop();
            }
            if(count == 0) {
                return true;
            }
            s.pop();
        }
    }
    return false;
}

int main() {
    string expression;
    cin >> expression;
    bool ans = checkRedundantBrackets(expression);
    if(ans) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}