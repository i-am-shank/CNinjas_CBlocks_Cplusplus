// TIme Complexity = O(N*2)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicates(char *input, int size) {
    if (size < 2) {
        return;
    }
    if (input[0] == input[1]) {
        for (int i=1; i<size-1; i++) {
            input[i] = input[i+1];
        }
        input[size-1] = '\0';
        removeDuplicates(input, size-1);
        return;
    }
    else {
        removeDuplicates(input+1, size-1);
        return;
    }
}

void removeConsecutiveDuplicates(char *input) {
    int size = strlen(input);
    removeDuplicates(input, size);
    return;
}

int main() {
    char *input = new char [1000];
    cin >> input;
    removeConsecutiveDuplicates(input);
    cout << input << endl;
    delete []input;
    return 0;
}