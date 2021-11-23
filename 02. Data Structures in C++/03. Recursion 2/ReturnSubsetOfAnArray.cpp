// Time Complexity = O(N*3)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

int subsetHelper(int input[], int start, int end, int ** output) {
    if(start > end) {
        output[0][0] = 0;
        return 1;
    }
    int smallSize = subsetHelper(input, start+1, end, output);
    for(int i=0; i<smallSize; i++) {
        output[smallSize+i][0] = output[i][0] + 1;
        output[smallSize+i][1] = input[start];
        for(int j=2; j<output[i][0]+2; j++) {
            output[smallSize+i][j] = output[i][j-1];
        }
    }
    return 2*smallSize;
}

int subset(int input[], int n, int** output) {
    return subsetHelper(input, 0, n-1, output);
}

int main() {
    int n;
    cin >> n;
    int *input = new int [n];
    for (int i=0; i<n; i++) {
        cin >> input[i];
    }
    int **output = new int* [1000];
    for (int i=0; i<1000; i++) {
        output[i] = new int [20];
    }
    int size = subset(input, n, output);
    for (int i=0; i<size; i++) {
        for(int j=0; j<output[i][0]; j++) {
            cout << output[i][j+1] << " ";
        }
        cout << endl;
    }
    delete [] input;
    for (int i=0; i<1000; i++) {
        delete [] output[i];
    }
    delete []output;
    return 0;
}