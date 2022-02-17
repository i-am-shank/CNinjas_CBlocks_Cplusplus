// Time Complexity = O(N)
// Space Complexity = O(N)
//      .. O(1) space waiting in each recursion call.


#include <bits/stdc++.h>
using namespace std;

int lastIndex(int input[], int size, int x) {
    if(size == 0) {
        return -1;
    }
    if(input[size-1] == x) {
        return (size-1);
    }
    int smallAns = lastIndex(input, size-1, x);
    return smallAns;
}

int main() {
    int n, x;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    int ans = lastIndex(arr, n, x);
    cout << ans << endl;
    delete []arr;
    return 0;
}