// Time Complexity = O(N*2)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void removeX(char input[]) {
    int size = strlen(input);
    if (size == 0) {
        return;
    }
    if (input[0] == 'x') {
        int i;
        for (i=0; i<size-1; i++) {
            input[i] = input[i+1];
        }
        input[i] = '\0';
        removeX(input);
        return;
    }
    else {
        removeX(input + 1);
        return;
    }
}

int main() {
    int size = 1e3;
    char *input = new char[size];
    cin.getline(input, size);
    removeX(input);
    cout << input << endl;
    delete []input;
    return 0;
}