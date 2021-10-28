// Time Complexity = O(N*3)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void printString(char* input, int size) {
    for (int i=1; i<=size; i++) {
        for (int j=0; j<i; j++) {
            cout << *(input+j) << "";
        }
        cout << endl;
    }
}

void printSubstrings(char input[]) {
    int size = strlen(input);
    for (int i=0; i<size; i++) {
        printString(input+i, size-i);
    }
}

int main() {
    int size = 1e6;
    char input[size];
    cin >> input;
    printSubstrings(input);
    return 0;
}