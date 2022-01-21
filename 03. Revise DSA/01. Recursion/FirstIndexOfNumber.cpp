#include <iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
    if(size == 0) {
        return -1;
    }
    if(input[0] == x) {
        return 0;
    }
    int smallAns = firstIndex(input+1, size-1, x);
    if(smallAns == -1) {
        return smallAns;
    }
    return smallAns+1;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int ans = firstIndex(arr, n, x);
    cout << ans << endl;
    delete []arr;
    return 0;
}