// Time Complexity = O(N)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

int power(int x, int n) {
    if (n==0) {
        return 1;
    }
    return x * power(x, n-1);
}

int main() {
    int x, n;
    cin >> x >> n;
    int ans = power(x, n);
    cout << ans << endl;
    return 0;
}