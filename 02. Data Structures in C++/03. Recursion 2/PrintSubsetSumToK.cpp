// Time Complexity = O(2^N)
// Space Complexity = O(2^N)


#include <iostream>
using namespace std;

void printSubset(int input[], int start, int size, int output[], int osize, int k) {
    if(start == size) {
        if(k == 0) {
            for (int i=0; i<osize; i++) {
                cout << output[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    printSubset(input, start+1, size, output, osize, k);
    if (k > 0) {
        output[osize] = input[start];
        printSubset(input, start+1, size, output, osize+1, k-input[start]);
    }
    return;
}

void printSubsetSumToK(int input[], int size, int k) {
    int *output = new int[size];
    printSubset(input, 0, size, output, 0, k);
    delete []output;
    return;
}

int main() {
    int size, k;
    cin >> size;
    int *input = new int[size];
    for (int i=0; i<size; i++) {
        cin >> input[i];
    }
    cin >> k;
    printSubsetSumToK(input, size, k);
    delete []input;
    return 0;
}