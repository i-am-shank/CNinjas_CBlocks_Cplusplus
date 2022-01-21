// Time Complexity = O(logN)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

// Algorithm (Binary Search) :
//  1. Find middle element as, (start+end) / 2. Compare it with element.
//  2. 3 cases of comparison :
//      i. (element < middle element) = Search in 1st half of array.
//      ii. (element > middle element) = Search in 2nd half of array.
//      iii. (element == middle element) = Return index of middle element.

int binarySearchHelper(int *arr, int s, int e, int x) {
    if(s > e) {
        return -1;
    }
    int mid = (s+e) / 2;
    if(arr[mid] > x) {
        int smallAns = binarySearchHelper(arr, s, mid-1, x);
        return smallAns;
    }
    else if(arr[mid] < x) {
        int smallAns = binarySearchHelper(arr, mid+1, e, x);
        if(smallAns == -1) {
            return smallAns;
        }
        return smallAns + mid;
    }
    else {
        return mid;
    }
}

int binarySearch(int* arr, int size, int x) {
    return binarySearchHelper(arr, 0, size-1, x);
}

int main() {
    int n, x;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    int ans = binarySearch(arr, n, x);
    cout << ans << endl;
    delete []arr;
    return 0;
}