#include <iostream>
using namespace std;

int subset(int input[], int startIndex, int n, int** output) {
    if (startIndex == n) {
        output[0][0] = 0;
        return 1;
    }
    int smallSize = subset(input, startIndex+1, n, output);
    for (int i=0; i<smallSize; i++) {
        for (int j=1; j<=output[i][0]; j++) {
            output[i+smallSize][j+1] = output[i][j];
        }
        output[i+smallSize][1] = input[startIndex];
        output[i+smallSize][0] = output[i][0] + 1;
    }
    return 2 * smallSize;
}

int subsetSumHelper(int** subsets, int start, int n, int** output, int k) {
    if (start==n || k==0) {
        return 0;
    }
    int smallSize = subsetSumHelper(subsets, start+1, n, output, k);
    int sum = 0;
    for (int i=1; i<=subsets[start][0]; i++) {
        sum += subsets[start][i];
    }
    if (sum == k) {
        for (int i=0; i<=subsets[start][0] ; i++) {
            output[smallSize][i] = subsets[start][i];
        }
        return smallSize + 1;
    }
    else {
        return smallSize;
    }
}

int subsetSumToK(int input[], int n, int** output, int k) {
    int **subsets = new int* [1000];
    for (int i=0; i<1000; i++) {
        subsets[i] = new int [50];
    }
    int totalSubsets = subset(input, 0, n, subsets);
    return subsetSumHelper(subsets, 0, totalSubsets, output, k);
}

int main() {
    int n;
    cin >> n;
    int input[n];
    for (int i=0; i<n; i++) {
        cin >> input[i];
    }
    int k;
    cin >> k;
    int **output = new int* [1000];
    for (int i=0; i<1000; i++) {
        output[i] = new int[50];
    }
    int size = subsetSumToK(input, n, output, k);
    for (int i=0; i<size; i++) {
        for (int j=1; j<=output[i][0]; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}