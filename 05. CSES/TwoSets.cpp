// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n % 4 == 0  ||  n % 4 == 3) {    // correct logic
        cout << "YES" << endl;
        if(n % 4 == 0) {
            cout << n/2 << endl;
            for(int i=0; i<n; i+=4) {
                cout << (i+1) << " " << (i+4) << " ";
            }
            cout << endl << n/2 << endl;
            for(int i=0; i<n; i+=4) {
                cout << (i+2) << " " << (i+3) << " ";
            }
            cout << endl;
        }
        else {
            cout << ((n+1) / 2) << endl;
            if(n >= 3) {
                cout << "1 2 ";
            }
            for(int i=4; i<=(n-3) ; i+=4) {
                cout << i << " " << (i+3) << " ";
            }
            cout << endl << ((n-1) / 2) << endl;
            if(n >= 3) {
                cout << "3 ";
            }
            for(int i=4; i<=(n-3) ; i+=4) {
                cout << (i+1) << " " << (i+2) << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}