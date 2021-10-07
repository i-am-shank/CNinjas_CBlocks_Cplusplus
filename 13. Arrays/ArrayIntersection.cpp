// Time Complexity = O(n*4) .. O(n*3) for 1 test case
// Space Complexity = O(n*2) .. O(n) for 1 test case


#include <iostream>
#include <climits>
using namespace std;

void intersection(int *input1, int *input2, int size1, int size2) {
    for (int j=0; j<size1; j++){
        for (int k=0; k<size2; k++){    // iterate over array2 in array1
            if (input1[j] == input2[k]){    // compare for intersection
                cout << input1[j] << " ";
                input2[k] = INT_MIN;
                break;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr1 = new int [n];
        for (int i=0; i<n ; i++) {
            cin >> arr1[i];
        }
        int m;
        cin >> m;
        int *arr2 = new int [m];
        for (int i=0; i<m ; i++) {
            cin >> arr2[i];
        }
        intersection(arr1, arr2, n, m);
        delete [] arr1;
        delete [] arr2;
        cout << endl;
    }
    return 0;
}