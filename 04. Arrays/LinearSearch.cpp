// Time Complexity = O(n*2) .. n test cases, linear search = O(n) time
// Space Complexity = O(n*2) .. 1 array (O(n)) in each of n test cases.


#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int x){
    int index = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == x) {
            index = i;
            break;
        }
    }
    return index;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n], x;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cin >> x;
        cout << linearSearch(arr, n, x) << endl;
    }
    return 0;
}