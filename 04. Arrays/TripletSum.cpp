// Time Complexity = O(n*3) .. O(n*2) for 1 test case
// Space Complexity = O(n*2) .. O(n) for 1 test case


#include <iostream>
#include <climits>
using namespace std;

int tripletSum(int *input, int size, int x){
    int count = 0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            for (int k=0; k<size; k++) {
                if((input[i]+input[j]+input[k] == x)  &&  ((i!=j) && (j!=k) && (i!=k))  ){
                    count ++;
                }
            }
        }
    }
    return count/6;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        int *arr = new int [n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cin >> x;
        int ans = tripletSum(arr, n, x);
        cout << ans << endl;
    }
}