// Time Complexity = O(N*2)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

void reverse(char* start, char* end) {
    char temp;
    while(start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    return;
}

void reverseStringWordWise(char input[]) {
    char* temp = input;
    char* begin = input;
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse (begin, temp-1);
        }
        else if (*temp == ' ') {
            reverse (begin, temp-1);
            begin = temp + 1;
        }
    }
    reverse (input, temp-1);
}

int main() {
    int size = 1e3;
    char* input = new char[size];
    cin.getline(input, size);
    reverseStringWordWise(input);
    cout << input << endl;
    delete []input;
    return 0;
}