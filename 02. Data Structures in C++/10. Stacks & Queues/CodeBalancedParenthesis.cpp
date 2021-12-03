// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string expression) {
    stack <char> s;
    int l = expression.length();
    for (int i=0; i<l; i++) {
        if(expression[i] == '(') {
            s.push(expression[i]);
        }
        if(expression[i] == ')') {
            if(s.empty()) {
                return false;
            }
            if(s.top() == '(') {
                s.pop();
            }
            else {
                return false;
            }
        }
    }
    if(s.empty()) {
        return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    bool ans = isBalanced(s);
    if(ans) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}