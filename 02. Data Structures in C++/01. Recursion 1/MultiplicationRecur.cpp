// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
    if (n == 0) {
        return 0;
    }
    return m + multiplyNumbers(m, n-1);
}

int main() {
    int m, n;
    cin >> m >> n;
    int ans = multiplyNumbers(m, n);
    cout << ans << endl;
    return 0;
}