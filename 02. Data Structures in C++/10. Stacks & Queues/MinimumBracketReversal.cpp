// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <string>
#include <stack>
using namespace std;

int countBracketReversals(string input) {
    int l = input.length();
    if(l%2 != 0) {
        return -1;
    }
    else {
        stack <int> s;
        for (int i=0; i<l; i++) {
            if(input[i] == '{') {
                s.push(input[i]);
            }
            else if(!s.empty()) {
                if(s.top() == '{') {
                    s.pop();
                }
                else {
                    s.push(input[i]);
                }
            }
            else {
                s.push(input[i]);
            }
        }
        int count = 0;
        while(!s.empty()) {
            char c1 = s.top();
            s.pop();
            char c2 = s.top();
            s.pop();
            if(c1 == c2) {
                count ++;
            }
            else {
                count += 2;
            }
        }
        return count;
    }
}

int main() {
    string input;
    cin >> input;
    int ans = countBracketReversals(input);
    cout << ans << endl;
    return 0;
}