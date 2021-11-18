#include <iostream>
using namespace std;

int subsetHelper(int input[], int n, int startIndex, int** output) {
    if (startIndex == n) {
        output[0][0] = 0;
        return 1;
    }
    int smallSize = subsetHelper(input, n, startIndex+1, output);
    for (int i=0; i<smallSize; i++) {
        output[i+smallSize][0] = output[i][0] + 1;
        output[i+smallSize][1] = input[startIndex];
        for (int j=1; j<=output[i][0]; j++) {
            output[i+smallSize][j+1] = output[i][j];
        }
    }
    return 2*smallSize;
}

int subset(int input[], int n, int** output) {
    return subsetHelper(input, n, 0, output);
}

int main() {
    int input[20],length;
    int** output = new int* [35000];
    for (int i=0; i<35000; i++) {
        output[i] = new int [20];
    }
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    int size = subset(input, length, output);
    for( int i = 0; i < size; i++) { 
        for( int j = 1; j <= output[i][0]; j++) { 
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}