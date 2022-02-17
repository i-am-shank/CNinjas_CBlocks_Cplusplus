// Time Complexity = O(N)
// Space Complexity = O(N)
//      .. O(1) space waiting in each recursion call.


#include <bits/stdc++.h>
using namespace std;

bool checkNumber(int input[], int size, int x) {
    if(size == 0) {
        return false;
    }
    if(input[0] == x) {
        return true;
    }
    bool smallAns = checkNumber(input+1, size-1, x);
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
    bool ans = checkNumber(arr, n, x);
    cout << (ans == true ? "true" : "false") << endl;
    delete []arr;
    return 0;
}