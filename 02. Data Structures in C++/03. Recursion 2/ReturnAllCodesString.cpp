// Time Complexiyt = O(N * 2^N)
// Space Complexity = O(N * 2^N)


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int getCodes(string input, string output[10000]) {
    if (input[0] == '\0') {
        output[0] = "";
        return 1;
    }
    string smallOutput1[500];
    string smallOutput2[500];
    int temp1 = input[0] - 48;
    char tempChar1 = temp1 + 'a' - 1;
    char tempChar2 = '\0';
    int size1 = getCodes(input.substr(1), smallOutput1), size2=0;
    if(input[1] != '\0') {
        int temp2 = temp1 * 10 + input[1] - 48;
        if(temp2>=10 && temp2<=26) {
            tempChar2 = temp2 + 'a' - 1;
            size2 = getCodes(input.substr(2), smallOutput2);
        }
    }
    int count = 0;
    for (int i=0; i<size1; i++) {
        output[count] = tempChar1 + smallOutput1[i];
        count++;
    }
    for (int i=0; i<size2; i++) {
        output[count] = tempChar2 + smallOutput2[i];
        count++;
    }
    return count;
}

int main() {
    string input;
    cin >> input;
    string output[10000];
    int size = getCodes(input, output);
    for (int i=0; i<size && i<10000; i++) {
        cout << output[i] << endl;
    }
    return 0;
}