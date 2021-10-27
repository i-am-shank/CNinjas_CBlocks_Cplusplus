// Time Complexity = O(n^2)
// Space Complexity = O(1)

#include <iostream>
using namespace std;

int main(){
    int n, i, j, k, l;
    cin >> n;
    for (i=1; i<=n; i++){
        for (l=1; l<n-i+1; l++){
            cout << " ";
        }
        for (j=i; j>=1; j--){
            cout << j;
        }
        j+=2;
        for (k=j; k<=i; k++){
            cout << k;
        }
        cout << endl;
    }
}