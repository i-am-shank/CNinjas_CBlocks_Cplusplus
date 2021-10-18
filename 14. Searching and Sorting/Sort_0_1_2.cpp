// Time Complexity = O(N**2)  ..  O(N) for each test case.
// Space Complexity = O(N**2)  ..  O(N) for each test case.


#include <iostream>
using namespace std;

void sort012(int *arr, int n) {
    int c0=0, c1=0, c2=0, i=0, j=0, k=0, l=0;
    for (int i=0; i<n; i++) {
        if (arr[i] == 0)    c0++;
        else if (arr[i] == 1)   c1++;
        else    c2++;
    }
    while (j < c0) {
        arr[i++] = 0;
        j++;
    }
    while (k < c1) {
        arr[i++] = 1;
        k++;
    }
    while (l < c2) {
        arr[i++] = 2;
        l++;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        sort012(arr, n);
        for (int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete []arr;
    }
    return 0;
}