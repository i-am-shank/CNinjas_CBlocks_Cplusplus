// Time Complexity = O(n*2)
// Space Complexity = O(n*2) .. actually both are O(n), but for t test cases --> O(n*2)


#include <iostream>
using namespace std;

void swapAlternate(int *arr, int size) {
    if (size == 0) {
        return;
    }
    int temp;
    for (int i=0; i<(size-1); i+=2) {
        temp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = temp; 
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
        swapAlternate(arr, n);
        for (int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}