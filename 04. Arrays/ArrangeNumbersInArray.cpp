// Time Complexity = O(n*2)
// Space Complexity = O(n*2)  ... both are O(n), but for t test cases --> O(n*2)


#include <iostream>
using namespace std;

void arrange(int *arr, int n) {
    int j=0;
    if(n % 2 == 0){
        for (int i=1; i<=(n-1); i+=2) {
            arr[j] = i;
            j++;
        }
        for (int i=n; i>=2; i-=2) {
            arr[j] = i;
            j++;
        }
    }
    else {
        for (int i=1; i<=n; i+=2) {
            arr[j] = i;
            j++;
        }
        for (int i=(n-1); i>=2; i-=2) {
            arr[j] = i;
            j++;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        arrange(arr, n);
        for (int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete [] arr;
        return 0;
    }
}