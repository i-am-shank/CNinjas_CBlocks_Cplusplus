// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

// Algorithm (Linear Search) :
//  1. First compare the first element of array, if matched, element found.
//  2. If not found, Recursion call.

int linearSearch(int* arr, int size, int x) {
    if(size == 0) {
        return -1;
    }
    if(arr[0] == x) {
        return 0;
    }
    int smallAns = linearSearch(arr+1, size-1, x);
    if(smallAns != -1) {
        return 1+smallAns;
    }
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
    int ans = linearSearch(arr, n, x);
    cout << ans << endl;
    delete []arr;
    return 0;
}