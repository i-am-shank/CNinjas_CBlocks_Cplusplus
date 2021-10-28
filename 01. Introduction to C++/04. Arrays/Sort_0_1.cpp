// Time Complexity = O(n*2) .. O(n) for 1 test case.
// Space Complexity = O(n*2) .. O(n) for 1 test case.


#include <iostream>
using namespace std;

void sortZeroesAndOne(int *input, int size) {
    int num_zero = 0;
    for (int i=0; i<size; i++) {
        if(input[i] == 0) {
            num_zero ++;
        }
    }
    for (int i=0; i<num_zero; i++) {
        input[i] = 0;
    }
    for (int j=num_zero; j<size; j++) {
        input[j] = 1;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int [n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        sortZeroesAndOne(arr, n);
        for (int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}