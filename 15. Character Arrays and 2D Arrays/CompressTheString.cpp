// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <string>
using namespace std;

string getCompressedString(string &input) {
    int length = input.length();
    if (length == 0) {
        return "";
    }
    int startI=0 , endI=0;
    string output = "";
    while (startI < length) {
        while ((endI<length) && (input[endI] == input[startI])) {
            endI++;
        }
        int count = endI - startI;
        if (count != 1) {
            output += input[startI];
            output += (char)(count + '0');
        }
        else {
            output += input[startI];
        }
        startI = endI;
    }
    return output;
}

int main() {
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
    return 0;
}