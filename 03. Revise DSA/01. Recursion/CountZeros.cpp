#include <iostream>
using namespace std;

int countZerosHelper(int n) {
    if(n == 0) {
        return 0;
    }
    if(n%10 == 0) {
        return 1+countZerosHelper(n/10);
    }
    else {
        return countZerosHelper(n/10);
    }
}

int countZeros(int n) {
    if(n == 0) {
        return 1;
    }
    return countZerosHelper(n);
}

int main() {
    int n;
    cin >> n;
    int ans = countZeros(n);
    cout << ans << endl;
    return 0;
}