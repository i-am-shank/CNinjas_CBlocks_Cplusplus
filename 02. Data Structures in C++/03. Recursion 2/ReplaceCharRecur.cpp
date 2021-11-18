// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

void replaceCharacter(char input[], char c1, char c2) {
    if(*input == '\0') {
        return;
    }
    if(input[0] == c1) {
        input[0] = c2;
    }
    replaceCharacter(input+1, c1, c2);
    return;
}

int main() {
    char c1, c2;
    char *input = new char[1000000];
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
    delete []input;
    return 0;
}