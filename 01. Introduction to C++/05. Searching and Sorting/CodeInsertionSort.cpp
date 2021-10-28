// Time Complexity = O(n*3) .. O(n*2) for each test case.
// Space Complexity = O(n*2) .. O(n) for each test case.


#include <iostream>
#include <climits>
using namespace std;

void insertionSort(int *input, int size) {
    int si, s;
    for (int i=0; i<size; i++) {
        si=i, s=input[i];
        for (int j=i+1; j<size; j++) {
            if(input[j] < s){
                s=input[j];
                si = j;
            }
        }
        int temp = s;
        input[si] = input[i];
        input[i] = temp;
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
        insertionSort (arr, n);
        for (int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete [] arr;
    }
    return 0;
}