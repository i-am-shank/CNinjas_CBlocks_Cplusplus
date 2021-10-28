// Time Complexity = O(N*2)
// Space Complexity = O(1)


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double geometricSum(int k) {
    if (k == 0) {
        return 1;
    }
    return (1 / pow(2 , k)) + geometricSum(k-1);
}

int main() {
    int k;
    cin >> k;
    double ans = geometricSum(k);
    cout << fixed << setprecision(5);
    cout << ans << endl;
    return 0;
}