// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

void permutations(string input, string output) {
    if(input[0] == '\0') {
        cout << output << endl;
        return;
    }
    for (int i=0; i<=output.length(); i++) {
        permutations(input.substr(1), output.substr(0,i) + input[0] + output.substr(i));
    }
    return;
}

void printPermutations(string input) {
    permutations(input, "");
    return;
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}