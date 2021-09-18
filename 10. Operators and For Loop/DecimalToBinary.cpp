// Time Complexity = O(nlog(n))
// Space Complexity = O(1)

#include <iostream>
using namespace std;

int main(){
    int d, c=0;
    long bin=0, i;
    cin >> d;
    while (d > 0){
        i = d%2;
        if (c != 0){
            for (int j=1; j<=c; j++){
                i *= 10;
            }
        }
        d /= 2;
        c += 1;
        bin += i;
    }
    cout << bin << endl;
}