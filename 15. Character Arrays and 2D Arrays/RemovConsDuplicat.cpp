// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[]) {
    int size = strlen(input), j=1;
    char last = input[0];
    for (int i=1; i<size; i++) {
        while (input[i] == last) {
            i++;
        }
        input[j++] = input[i];
        last = input[i];
    }
    input[j] = '\0';
    return;
}

int main() {
    int size = 1e6;
    char* input = new char[size];
    cin >> input;
    removeConsecutiveDuplicates(input);
    cout << input << endl;
    delete []input;
    return 0;
}