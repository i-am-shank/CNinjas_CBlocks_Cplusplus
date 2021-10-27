// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char input[]) {
    int arr[256], size = strlen(input), max=0, maxIndex=0;
    for (int i=0; i<256; i++) {
        arr[i] = 0;
    }
    for (int i=0; i<size; i++) {
        arr[int(input[i])]++;
    }
    for (int i=0; i<256; i++) {
        if(arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return char(maxIndex);
}

int main() {
    int size=1e6;
    char input[size];
    cin >> input;
    cout << highestOccurringChar(input);
    return 0;
}