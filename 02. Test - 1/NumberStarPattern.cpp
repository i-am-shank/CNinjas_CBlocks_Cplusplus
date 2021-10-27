// Time Complexity = O(n^2)
// Space Complexity = O(1)

#include <iostream>
using namespace std;

int main(){
    int n, i, j, k, l;
    cin >> n;
    for (i=0; i<n; i++){
        for (j=1; j<=(n-i); j++){
            cout << j;
        }
        for (k=1 ; k<=(2*i); k++){
            cout << "*";
        }
        for (l=(n-i); l>=1; l--){
            cout << l;
        }
        cout << endl;
    }
}