// Time Complexity = O(N*3)  ..  O(N*2) for each test case
// Space Comlexity = O(N*2)


#include <iostream>
using namespace std;

void wavePrint(int **input, int nRows, int mCols) {
    for (int j=0; j<mCols; j++) {
        if (j%2 == 0) {
            for (int i=0; i<nRows; i++) {
                cout << input[i][j] << " " ;
            }
        }
        else {
            for (int i=nRows-1; i>=0; i--) {
                cout << input[i][j] << " " ;
            }
        }
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int **arr = new int* [n];
        for (int i=0; i<n; i++) {
            arr[i] = new int[m];
            for (int j=0; j<m; j++) {
                cin >> arr[i][j];
            }
        }
        wavePrint(arr, n, m);
        cout << endl;
    }
    return 0;
}