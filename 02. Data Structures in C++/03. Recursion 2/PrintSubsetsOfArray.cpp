// Time Complexity = O(N * 2^N)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

void printSubset(int input[], int start, int size, int output[], int osize) {
    if(start == size) {
        for (int i=0; i<osize; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    printSubset(input, start+1, size, output, osize);
    output[osize] = input[start];
    printSubset(input, start+1, size, output, osize+1);
    return;
}

void printSubsetsOfArray(int input[], int size) {
    int output[size+1];
    printSubset(input, 0, size, output, 0);
    return;
}

int main(){
    int size;
    cin >> size;
    int *input = new int [size];
    for (int i=0; i<size; i++) {
        cin >> input[i];
    }
    printSubsetsOfArray(input, size);
    delete []input;
    return 0;
}