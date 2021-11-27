// Time Complexity = O(2^N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

int tripletSumHelper(int *arr, int start, int n, int left, int num) {
    if(start > n) {
        return 0;
    }
    if(left == 0) {
        if(num == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int smallAns1 = tripletSumHelper(arr, start+1, n, left-1, num-arr[start]);
    int smallAns2 = tripletSumHelper(arr, start+1, n, left, num);
    return smallAns1 + smallAns2;
}

int tripletSum(int *arr, int n, int num) {
    return tripletSumHelper(arr, 0, n, 3, num);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, num;
        cin >> n;
        int *arr = new int[n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cin >> num;
        int ans = tripletSum(arr, n, num);
        cout << ans << endl;
        delete [] arr;
    }
    return 0;
}