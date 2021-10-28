// Time Complexity = O(logN)
// Space Comlexity = O(1)


#include <iostream>
using namespace std;

int countZeros(int n) {
    if (n < 10) {
        if (n != 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    if (n == 0) {
        return 0;
    }
    if (n % 10 == 0) {
        return 1 + countZeros(n / 10);
    }
    else {
        return countZeros(n / 10);
    }
}

int main() {
    int n;
    cin >> n;
    int ans = countZeros(n);
    cout << ans << endl;
    return 0;
}