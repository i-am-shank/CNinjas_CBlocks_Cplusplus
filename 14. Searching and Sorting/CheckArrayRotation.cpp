// Time Complexity = O(N*2)  ..  O(N) for each test case
// Space Complexity = O(N*2)  ..  O(N) for each test case


#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size) {
    int k=1, i=0;
    while ((input[i] < input[i+1])  &&  (i < size-1)){
        k++;
        i++;
    }
    if ((k == size)  ||  (size == 0)) {
        return 0;
    }
    return k;
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
        int ans = arrayRotateCheck(arr, n);
        cout << ans << endl;
        delete []arr;
    }
    return 0;
}