// Time Complexity = O(N)
// Space Complexity = O(N)


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int [n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n/2; i++) {
        int total = arr[i] + arr[(n-1)-i];
        int a = total / 10;
        int b = total % 10;
        cout << a << " " << b << endl;
    }
    delete []arr;
    return 0;
}