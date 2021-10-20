// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char str[]) {
    bool flag = true;
    int size = strlen(str);
    for (int i=0; i<size/2; i++) {
        if (str[i] != str[size-1-i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
    return 0;
}