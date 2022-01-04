// Time Complexity = O(NlogN)
// Space Complexity = O(N)


#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void intersection(int *arr1, int *arr2, int n, int m) {
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
    int i=0, j=0;
    while(i<n && j<m) {
        if(arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        int *arr1 = new int[n];
        for(int i=0; i<n; i++) {
            cin >> arr1[i];
        }
        cin >> m;
        int *arr2 = new int[m];
        for (int i=0; i<m; i++) {
            cin >> arr2[i];
        }
        intersection(arr1, arr2, n, m);
        delete []arr1;
        delete []arr2;
    }
    return 0;
}