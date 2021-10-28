// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

int charToInt(char input[], int size) {
    if (size == 1) {
        return input[size-1]-'0';
    }
    int smallAns = charToInt(input, size-1);
    int a = input[size-1] - '0';
    return (smallAns*10) + a;
}

int stringToNumber(char input[]) {
    int size = strlen(input);
    return charToInt(input, size);
}

int main() {
    char *input = new char [10];
    cin >> input;
    int ans = stringToNumber(input);
    cout << ans << endl;
    delete []input;
    return 0;
}