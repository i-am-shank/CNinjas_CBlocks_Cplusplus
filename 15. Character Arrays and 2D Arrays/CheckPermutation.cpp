// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char input1[], char input2[]) {
    int arr[256];
    int size1 = strlen(input1), size2 = strlen(input2);
    if (size1 != size2) {
        return false;
    }
    for(int i=0; i<256; i++) {
        arr[i] = 0;
    }
    for(int i=0; i<size1; i++) {
        arr[int(input1[i])]++;
    }
    for(int i=0; i<size2; i++) {
        arr[int(input2[i])]--;
    }
    for(int i=0; i<256; i++) {
        if(arr[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int size = 1e6;
    char input1[size], input2[size];
    cin >> input1 >> input2;
    cout << (isPermutation(input1, input2) ? "true" : "false");
    return 0;
}