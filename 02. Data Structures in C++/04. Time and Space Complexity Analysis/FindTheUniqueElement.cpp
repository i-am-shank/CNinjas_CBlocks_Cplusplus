#include <iostream>
using namespace std;

int findUnique(int *arr, int n) {
    int temp[1000000];
    for (int i=0; i<1000000; i++) {
        temp[i] = 0;
    }
    for(int i=0; i<n; i++) {
        int ele = arr[i];
        temp[ele] += 1;
    }
    int ans = -1;
    for(int i=0; i<1000000; i++) {
        if(temp[i] == 1) {
            ans = i;
            break;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i=0; i<n; ++i) {
            cin >> arr[i];
        }
        cout << findUnique(arr, n) << endl;
    }
    return 0;
}