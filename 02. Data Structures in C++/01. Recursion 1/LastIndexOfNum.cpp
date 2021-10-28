// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
    if (input[size-1] == x) {
        return (size-1);
    }
    if (size == 0) {
        return -1;
    }
    return lastIndex(input, size-1, x);
}

int main() {
    int n, x, ans;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    ans = lastIndex(arr, n, x);
    cout << ans << endl;
    delete []arr;
    return 0;
}