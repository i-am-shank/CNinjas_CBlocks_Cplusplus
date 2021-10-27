// Time Complexity = O(n*2) .. O(n) for each test case.
// Space Complexity = O(n*2) .. O(n) for each test case.


#include <iostream>
using namespace std;

void pushZeroesEnd(int *input, int size) {
    int count = 0;
    for (int i=0; i<size; i++) {
        if (input[i] != 0) {
            input[count++] = input[i];
        }
    }
    while (count < size) {
        input[count++] = 0;
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
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        pushZeroesEnd(arr, n);
        for(int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete []arr;
    }
    return 0;
}