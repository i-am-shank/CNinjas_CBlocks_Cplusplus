// Time Complexity = O(n*3) .. O(n*2) for each test case.
// Space Complexity = O(n*2) .. O(n) for each test case.


#include <iostream>
using namespace std;

void bubbleSort(int *input, int size) {
    for (int j=size-1; j>=0; j--) {
        for (int i=0; i<j; i++) {
            if (input[i] > input[i+1]){
                int temp = input[i];
                input[i] = input[i+1];
                input[i+1] = temp;
            }
        }
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
        bubbleSort(arr, n);
        for (int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete [] arr;
    }
    return 0;
}