#include <iostream>
#include <string>
using namespace std;

bool scrambledString(string s1, int n, string s2, int m) {
    if(n != m) {
        return false;
    }
    
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    bool ans = scrambledString(s1, n, s2, m);
    cout << (ans == true ? "Yes" : "No") << endl;
    return 0;
}