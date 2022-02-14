#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, count0 = 0 , count1 = 0;
        cin >> n;
        string s;
        cin >> s;
        for(int i=0; i<n; i++) {
            if(s[i] == '0') {
                count0 ++;
            }
            else {
                count1 ++;
            }
        }
        if(n % 2 != 0) {    // n  -->  odd
            cout << "YES" << endl;
        }
        else {      // n  -->  even
            if(count1 == count0) {
                cout << "YES" << endl;
            }
            else if(count1 % 2 == 0  &&  count0 % 2 == 0) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}