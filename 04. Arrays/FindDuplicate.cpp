// Time Complexity = O(n*3) .. O(n*2) for 1 test case
// Space Complexity = O(n*2) .. O(n) for 1 test case


#include <iostream>
using namespace std;

int duplicateNumber(int *arr, int size){
    if (size == 0) {
        return 0;
    }
    for (int i=0; i<size; i++) {
        int count = 0;
        for (int j=0; j<size; j++){
            if (arr[i] == arr[j]) {
                count ++;
            }
        }
        if (count == 2) {
            return arr[i];
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int [n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cout << duplicateNumber(arr, n) << endl;
    }
    return 0;
}