// Time Complexity = O(N*3)  ..  O(N*2) for each test case
// Space Complexity = O(N*2)


#include <iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int nCols) {
    int rs=0, re=nRows-1, cs=0, ce=nCols-1;
    while((rs<=re) && (cs<=ce)) {
        for (int j=cs; j<=ce; j++) {
            cout << input[rs][j] << " ";
        }
        rs++;
        for (int i=rs; i<=re; i++) {
            cout << input[i][ce] << " ";
        }
        ce--;
        for (int j=ce; j>=cs; j--) {
            cout << input[re][j] << " ";
        }
        re--;
        for (int i=re; i>=rs; i--) {
            cout << input[i][cs] << " ";
        }
        cs++;
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
            arr[i] = new int [m];
            for (int j=0; j<m; j++) {
                cin >> arr[i][j];
            }
        }
        spiralPrint(arr, n, m);
        cout << endl;
    }
    return 0;
}