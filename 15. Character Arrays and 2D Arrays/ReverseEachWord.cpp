// Time Complexity = O(N*2)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

void reverse(char* begin, char* temp) {
    while (begin < temp) {
        char a = *begin;
        *begin++ = *temp;
        *temp-- = a;
    }
    return;
}

void reverseEachWord(char input[]) {
    char* begin=input, *temp=input;
    while (*temp) {
        temp++;
        if (*temp == ' ') {
            reverse(begin, temp-1);
            begin = temp + 1;
        }
        else if (*temp == '\0') {
            reverse(begin, temp-1);
        }
    }
    return;
}

int main() {
    int size = 1e6;
    char *input = new char[size];
    cin.getline(input, size);
    reverseEachWord(input);
    cout << input << endl;
    return 0;
}