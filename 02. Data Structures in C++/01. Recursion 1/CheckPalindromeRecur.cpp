// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

bool check(char input[], int size)  {
    if (size < 2) {
        return true;
    }
    if (input[0] == input[size-1]) {
        return check(input+1 , size-2);
    }
    else {
        return false;
    }
}

bool checkPalindrome(char input[]) {
    int size = strlen(input);
    return check(input, size);
}

int main() {
    char input[1000];
    cin >> input;
    bool ans = checkPalindrome(input);
    cout << (ans == true ? "true" : "false") << endl;
    return 0;
}