// Time Complexity = O(2^N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

int pairSumHelper(int *arr, int start, int n, int left, int num) {
    if(start > n) {
        return 0;
    }
    if(left == 0) {
        if(num == 0) {
            return 1;
        }
        return 0;
    }
    int smallAns1 = pairSumHelper(arr, start+1, n, left-1, num-arr[start]);
    int smallAns2 = pairSumHelper(arr, start+1, n, left, num);
    return (smallAns1+smallAns2);
}

int pairSum(int *arr, int n, int num) {
    return pairSumHelper(arr, 0, n, 2, num);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, num;
        cin >> n;
        int *arr = new int[n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cin >> num;
        int ans = pairSum(arr, n, num);
        cout << ans << endl;
        delete []arr;
    }
    return 0;
}