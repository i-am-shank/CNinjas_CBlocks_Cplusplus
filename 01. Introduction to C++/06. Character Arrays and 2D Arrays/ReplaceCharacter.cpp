// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void replaceCharacter(char input[], char c1, char c2) {
    int i=0;
    while(input[i]) {
        if (input[i] == c1) {
            input[i] = c2;
        }
        i++;
    }
    return;
}

int main() {
    int size = 1e6;
    char *input = new char[size];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}