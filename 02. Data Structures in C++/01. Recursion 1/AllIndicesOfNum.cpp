// Time Complexity = O(N*2)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
    if (size == 0) {
        return 0;
    }
    int smallSize = allIndexes(input+1, size-1, x, output);
    if (input[0] == x) {
        for (int k=smallSize-1; k >= 0; k--) {
            output[k+1] = output[k]+1;
        }
        output[0] = 0;
        smallSize++;
    }
    else {
        for (int k=smallSize-1; k>=0 ; k--) {
            output[k] += 1;
        }
    }
    return smallSize;
}

int main() {
    int n, x, size;
    cin >> n;
    int *input = new int [n];
    int *output = new int [n];
    for (int i=0; i<n; i++) {
        cin >> input[i];
    }
    cin >> x;
    size = allIndexes(input, n, x, output);
    for (int i=0; i<size; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    delete []input;
    delete []output;
    return 0;
}