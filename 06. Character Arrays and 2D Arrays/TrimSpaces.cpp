// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) {
    int size = strlen(input) , j = 0;
    for (int i=0; i<size; i++) {
        if(input[i] == ' ') {
            continue;
        }
        input[j++] = input[i];
    }
    input[j] = '\0';
    return;
}

int main() {
    int size = 1e6;
    char* input = new char[size];
    cin.getline(input, size);
    trimSpaces(input);
    cout << input << endl;
    return 0;
}