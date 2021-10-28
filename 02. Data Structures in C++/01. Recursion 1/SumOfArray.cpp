// Time Complexity = O(N)
// Space Complexity = O(N)


#include <iostream>
using namespace std;

int sum(int input[], int n) {
    if(n == 0) {
        return 0;
    }
    int smallAns = sum(input+1, n-1);
    return input[0] + smallAns;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int [n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans = sum(arr, n);
    cout << ans << endl;
    delete []arr;
    return 0;
}