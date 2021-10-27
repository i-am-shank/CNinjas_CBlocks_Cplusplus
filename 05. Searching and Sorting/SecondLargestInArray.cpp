// Time Complexity = O(n*2)  ..  O(n) for each test case
// Space Complexity = O(n*2)  ..  O(n) for each test case


#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int *input, int n) {
    int l=INT_MIN, s=INT_MIN;
    for (int i=0; i<n; i++) {
        if (input[i] > l){
            s = l;
            l = input[i];
        }
        else if ((input[i]>s) && (input[i]<l)) {
            s = input[i];
        }
    }
    if (s <= 1){
        return INT_MIN;
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int [n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int ans = findSecondLargest(arr, n);
        cout << ans << endl;
        delete []arr;
    }
    return 0;
}