// TIme Complexity = O(exp(N))
// Space Complexity = O(1)


#include <iostream>
using namespace std;

int staircase(int n) {
    if (n==1 || n==2) {
        return n;
    }
    if (n == 3) {
        return 4;
    }
    int count1 = staircase(n-1);
    int count2 = staircase(n-2);
    int count3 = staircase(n-3);
    int totalCount = count1 + count2 + count3;
    return totalCount;
}

int main() {
    int n;
    cin >> n;
    int ans = staircase(n);
    cout << ans << endl;
    return 0;
}