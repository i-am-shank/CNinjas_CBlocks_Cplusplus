// Time Complexity = O(N*3)
// Space Complexity = O(N*2)


#include <iostream>
using namespace std;

void print2DArray(int **input, int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<(row-i); j++) {
            for (int k=0; k<col; k++) {
                cout << input[i][k] << ' ';
            }
            cout << endl;
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    for (int i=0; i<n; i++) {
        arr[i] = new int [m];
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    print2DArray(arr, n, m);
    for (int i=0; i<n; i++) {
        delete []arr[i];
    }
    delete []arr;
    return 0;
}