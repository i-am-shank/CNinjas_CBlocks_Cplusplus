// Time Complexity = O(N^2)
// Space Complexity = O(N)


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, flag = 0;
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int *sort_arr = new int[n];
        for(int i=0; i<n; i++) {
            sort_arr[i] = arr[i];
        }
        sort(sort_arr , sort_arr+n);
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>i; j--) {
                if(arr[i] & arr[j] == 0) {
                    continue;
                }
                else {
                    if(arr[i] > arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                    else {
                        continue;
                    }
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(arr[i] != sort_arr[i]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
        delete []arr;
        delete []sort_arr;
    }
    return 0;
}