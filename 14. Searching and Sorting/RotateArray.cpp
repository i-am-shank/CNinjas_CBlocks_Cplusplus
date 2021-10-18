// Time Complexity = O(n*2) .. O(n) for each test case.
// Space Complexity = O(n*2) .. O(n) for each test case.


#include <iostream>
using namespace std;

void rotate(int *input, int d, int n) {
    int arr[n] , i=0, j=0, k=0;
    while (i < d){
        arr[i] = input[i];
        i++;
    }
    while (i < n) {
        input[j++] = input[i++];
    }
    while (j < n) {
        input[j++] = arr[k++];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int *arr = new int[n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        rotate(arr, d, n);
        for (int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete []arr;
    }
    return 0;
}