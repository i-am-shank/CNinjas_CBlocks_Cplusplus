// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void removeAllOccurrencesOfChar(char input[], char c) {
    int j=0, size= strlen(input);
    for(int i=0; i<size; i++) {
        if(input[i] == c){
            continue;
        }
        input[j++] = input[i];
    }
    input[j] = '\0';
    return;
}

int main() {
    int size = 1e6;
    char *input = new char [size];
    cin >> input;
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(input, c);
    cout << input << endl;
    return 0;
}