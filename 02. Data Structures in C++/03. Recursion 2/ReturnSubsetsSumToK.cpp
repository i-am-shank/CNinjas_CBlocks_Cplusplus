// TIme Complexity = O(2^N)  ..  these no. of recursive calls
// Space Complexity = O((N^2) * (2^N))  ..  a 2D array in each recursive call


#include <iostream>
using namespace std;

int subsetHelper(int input[], int start, int n, int **output, int k) {
    if (start == n) {
        if (k == 0) {
            output[0][0] = 0;
            return 1;
        }
        else {
            return 0;
        }
    }
    int size1, size2, m=0;
    int **smallOutput1 = new int*[1000];
    for (int i=0; i<1000; i++) {
        smallOutput1[i] = new int[20];
    }
    int **smallOutput2 = new int*[1000];
    for (int i=0; i<1000; i++) {
        smallOutput2[i] = new int[20];
    }
    size1 = subsetHelper(input, start+1, n, smallOutput1, k);
    size2 = subsetHelper(input, start+1, n, smallOutput2, k-input[start]);
    for (int i=0; i<size1; i++) {
        for (int j=0; j<=smallOutput1[i][0]; j++) {
            output[m][j] = smallOutput1[i][j];
        }
        m++;
    }
    for (int i=0; i<size2; i++) {
        for (int j=1; j<=smallOutput2[i][0]; j++) {
            output[m][j+1] = smallOutput2[i][j];
        }
        output[m][0] = smallOutput2[i][0] + 1;
        output[m][1] = input[start];
        m++;
    }
    return m;
}

int subsetSumToK(int input[], int n, int** output, int k) {
    return subsetHelper(input, 0, n, output, k);
}

int main() {
    int n, k;
    cin >> n;
    int *input = new int[n];
    for (int i=0; i<n; i++) {
        cin >> input[i];
    }
    int **output = new int* [1000];
    for (int i=0; i<1000; i++) {
        output[i] = new int[20];
    }
    cin >> k;
    int size = subsetSumToK(input, n, output, k);
    for (int i=0; i<size; i++) {
        for (int j=1; j<=output[i][0]; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    for (int i=0; i<1000; i++) {
        delete []output[i];
    }
    delete []output;
    delete []input;
    return 0;
}