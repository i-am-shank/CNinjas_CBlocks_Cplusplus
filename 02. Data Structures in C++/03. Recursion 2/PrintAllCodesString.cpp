// Time Complexity = O(2^N)
// Space Complexity = O(2^N)


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void printCodes(string input, string output) {
    if(input[0] == '\0') {
        cout << output << endl;
        return;
    }
    int first = input[0] - 48;
    char firstChar = first + 'a' - 1;
    char secondChar = '\0';
    printCodes(input.substr(1), output+firstChar);
    if(input[1] != '\0') {
        int second = first * 10 + input[1] - 48;
        if(second >= 10 && second <= 26) {
            secondChar = second + 'a' - 1;
            printCodes(input.substr(2), output+secondChar);
        }
    }
    return;
}

void printAllPossibleCodes(string input) {
    string output = "";
    printCodes(input, output);
    return;
}

int main() {
    string input;
    cin >> input;
    printAllPossibleCodes(input);
    return 0;
}