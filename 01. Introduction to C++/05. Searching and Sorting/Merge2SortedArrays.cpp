// Time Complexity = O(n*2) .. O(n) for each test case.
// Space Complexity = O(n*2) .. O(n) for each test case.


#include <iostream>
using namespace std;

void merge(int *arr1, int size1, int *arr2, int size2, int *ans) {
    int i=0, j=0, k=0;
    while ((i < size1)  &&  (j < size2)) {
        if (arr1[i] <= arr2[j]) {
            ans[k] = arr1[i];
            i++;
            k++;
        }
        else {
            ans[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < size1){
        ans[k] = arr1[i];
        k++;
        i++;
    }
    while (j < size2){
        ans[k] = arr2[j];
        k++;
        j++;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        int *arr1 = new int[n];
        for (int i=0; i<n; i++) {
            cin >> arr1[i];
        }
        cin >> m;
        int *arr2 = new int[m];
        for (int j=0; j<m; j++) {
            cin >> arr2[j];
        }
        int *ans = new int[n+m];
        merge(arr1, n, arr2, m, ans);
        for (int k=0; k<m+n; k++) {
            cout << ans[k] << " ";
        }
        cout << endl;
        delete []arr1;
        delete []arr2;
        delete []ans;
    }
    return 0;
}