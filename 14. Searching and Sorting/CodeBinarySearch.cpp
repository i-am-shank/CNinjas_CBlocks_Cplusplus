// Time Complexity = O(nlog(n)) .. O(log(n)) for each test case.
// Space Complexity = O(n)


#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int val) {
    int start=0, end=n-1, mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (input[mid] == val) {
            return mid;
        }
        else if (input[mid] < val) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int index = binarySearch(arr, n, x);
        cout << index << endl;
    }
    delete [] arr;
    return 0;
}