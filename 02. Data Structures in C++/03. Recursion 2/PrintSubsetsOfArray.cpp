#include <iostream>
using namespace std;

void printSubsetHelper(int input[], int startIndex, int size, int output[], int osize) {
    if (startIndex == size) {
        for (int i=0; i<osize; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    printSubsetHelper(input, startIndex+1, size, output, osize);
    int smallOutput[size];
    for (int i=0; i<osize; i++) {
        smallOutput[i] = output[i];
    }
    smallOutput[osize] = input[startIndex];
    printSubsetHelper(input, startIndex+1, size, smallOutput, osize+1);
    return;
}

void printSubsetsOfArray(int input[], int size) {
    int output[size];
    return printSubsetHelper(input, 0, size, output, 0);
}

int main() {
    int size;
    cin >> size;
    int input[size];
    for (int i=0; i<size; i++) {
        cin >> input[i];
    }
    printSubsetsOfArray(input, size);
    return 0;
}