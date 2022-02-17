// Time Complexity = O(N^2)
// Space Complexity = O(1)


#include <bits/stdc++.h>
using namespace std;

int totalSum(int **input, int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 || i==n-1 || j==0 || j==n-1 || i==j || i+j==n-1) {
                sum += input[i][j];
            }
        }
    }
    return sum;
}

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int **input = new int* [n];
        for(int i=0; i<n; i++) {
            input[i] = new int[n];
            for(int j=0; j<n; j++) {
                cin >> input[i][j];
            }
        }
        int sum = totalSum(input, n);
        cout << sum << endl;
        for(int i=0; i<n; i++) {
            delete []input[i];
        }
        delete []input;
    }
}