#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, difference = 0;
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        for(int j=1; j<n+1; j++) {
            int eleV = (arr[j-1] - difference);
            if(eleV == j) {
                difference += 1;
            }
        }
        cout << difference << endl;
        delete []arr;
    }
    return 0;
}