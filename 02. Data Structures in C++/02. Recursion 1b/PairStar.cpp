// Time Complexity = O(N*2)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void starPair(char input[], int size) {
    if (size < 1) {
        return;
    }
    if (input[0] == input[1]) {
        for (int i=size-1; i>=2; i--) {
            input[i+1] = input[i];
        }
        input[2] = input[1];
        input[1] = '*';
        input[size+1] = '\0';
        starPair(input+2, size-1);
        return;
    }
    starPair(input+1, size-1);
    return;
}

void pairStar(char input[]) {
    int size = strlen(input);
    starPair(input, size);
    return;
}

int main() {
    int size = 1e3;
    char *input = new char [size];
    cin.getline(input, size);
    pairStar(input);
    cout << input << endl;
    delete []input;
    return 0;
}