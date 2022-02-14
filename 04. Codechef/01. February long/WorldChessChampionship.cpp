#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, countC=0, countN=0, countD=0, ans;
        cin >> x;
        string s;
        cin >> s;
        for(int i=0; i<14; i++) {
            if(s[i] == 'C') {
                countC++;
            }
            else if(s[i] == 'D') {
                countD++;
            }
            else {
                countN++;
            }
        }
        char maxChar = max(countC , max(countD, countN));
        if(countC > countN){
            ans = 60 * x;
        }
        else if(countC < countN) {
            ans = 40 * x;
        }
        else {
            ans = 55 * x;
        }
        cout << ans << endl;
    }
    return 0;
}