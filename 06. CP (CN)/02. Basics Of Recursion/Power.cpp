// Time Complexity = O(N)
// Space Complexity = O(N)  ..  O(1) space waiting in each recursion call (until last).


#include <bits/stdc++.h>
using namespace std;

int power(int x, int n) {
    if(n == 0) {
        return 1;
    }
    int smallAns = power(x, n-1);
    return (x * smallAns);
}

int main() {
    int x, n;
    cin >> x >> n;
    int ans = power(x, n);
    cout << ans << endl;
    return 0;
}