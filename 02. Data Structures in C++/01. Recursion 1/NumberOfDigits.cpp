// Time Complexity = O(logN)
// Space Complexity = O(1)


#include <iostream>
using namespace std;

int count(int n) {
    if (n == 0) {
        return 0;
    }
    int smallAns = count(n / 10);
    return 1 + smallAns;
}

int main() {
    int n;
    cin >> n;
    int ans = count(n);
    cout << ans << endl;
    return 0;
}