// Time Complexity = O(N*2)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void replacePi(char input[]) {
    int size = strlen(input);
    if(size < 2) {
        return;
    }
    if (input[0]=='p' && input[1]=='i') {
        for (int i=size-1; i>=2; i--) {
            input[i+2] = input[i];
        }
        input[size+2] = '\0';
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input + 4);
    }
    else {
        replacePi(input + 1);
    }
    return;
}

int main() {
    int size = 50;
    char *input = new char [50];
    cin.getline(input, 50);
    replacePi(input);
    cout << input << endl;
    delete []input;
    return 0;
}