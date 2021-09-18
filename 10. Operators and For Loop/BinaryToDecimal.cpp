// Time Complexity = O(n)
// Space Complexity = O(1)

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, in=0, p=0, u;
    cin >> n;
    while (n > 0){
        u = n%10;
        in += u * pow(2, p);
        p += 1;
        n /= 10;
    }
    cout << in << endl;
}