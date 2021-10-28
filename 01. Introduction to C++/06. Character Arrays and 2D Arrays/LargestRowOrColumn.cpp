// Time Complexity = O(N*3)  ..  O(N*2) for each test case
// Space Complexity = O(N*2)


#include <iostream>
#include <climits>
using namespace std;

void findLargest(int **input, int nRows, int mCols) {
    int max_sum = INT_MIN, index = 0, sum;
    bool flag = true;
    for (int i=0; i<nRows; i++) {    // Row sum
        sum = 0;
        for (int j=0; j<mCols; j++) {
            sum += input[i][j];
        }
        if (sum > max_sum) {
            flag = true;
            max_sum = sum;
            index = i;
        }
    }
    for (int j=0; j<mCols; j++) {    // Column sum
        sum = 0;
        for (int i=0; i<nRows; i++) {
            sum += input[i][j];
        }
        if (sum > max_sum) {
            flag = false;
            max_sum = sum;
            index = j;
        }
    }
    if (flag == true) {
        cout << "row" << " ";
    }
    else {
        cout << "column" << " ";
    }
    cout << index << " " << max_sum ;
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int **arr = new int* [n];
        for (int i=0; i<n; i++) {
            arr[i] = new int [m];
            for (int j=0; j<m; j++) {
                cin >> arr[i][j];
            }
        }
        findLargest(arr, n, m);
        cout << endl;
    }
    return 0;
}